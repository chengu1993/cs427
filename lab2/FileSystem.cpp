#include "FileSystem.hpp"
#include <list>

//Initialize
FileSystem::FileSystem(char *filename) {
    this->filename = filename;
    this->generation = 0;
    this->log_tail = 0;
}

bool FileSystem::read_super_block(int fd, SuperBlock &super_block) {
    SuperBlock *super_block_map = (SuperBlock*) mmap(NULL, BYTE_PER_BLOCK, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(super_block_map == MAP_FAILED){
        return false;
    }
    super_block = *super_block_map;
    msync(super_block_map, sizeof(SuperBlock), MS_SYNC);
    munmap(super_block_map, sizeof(SuperBlock));
    return true;
}

bool FileSystem::write_super_block(int fd, SuperBlock &super_block) {
    //recalculate super block checksum
    super_block.checksum = checksum((void *) &super_block);
    SuperBlock *super_block_map = (SuperBlock*) mmap(NULL, BYTE_PER_BLOCK, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(super_block_map == MAP_FAILED){
        return false;
    }
    *super_block_map = super_block;
    msync(super_block_map, sizeof(SuperBlock), MS_SYNC);
    munmap(super_block_map, sizeof(SuperBlock));
    return true;
}

pair<int, int> FileSystem::record(uint32_t optcode, uint64_t node_a, uint64_t node_b) {
    int fd =  open(this->filename, O_RDWR|O_DIRECT, S_IWUSR|S_IRUSR);
    if(fd == -1){
        printf("Encounter error when opening disk");
        exit(-1);
    }
    //new entry
    Entry entry;
    entry.opcode = optcode;
    entry.node_a = node_a;
    entry.node_b = node_b;

    //find current entry block;
    EntryBlock *entry_block = (EntryBlock*) mmap(NULL, BYTE_PER_BLOCK, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (LOG_BLOCK_START_IDX + log_tail)* BYTE_PER_BLOCK);
    if(this->generation != entry_block->gen_num || entry_block->checksum != checksum((void *) entry_block)){
        entry_block->gen_num = this->generation;
        entry_block->entry_num = 0;
    }
    entry_block->entry[entry_block->entry_num++] = entry;
    entry_block->checksum = checksum((void *) entry_block);

    //if reach the end of current block, increment log_tail
    if(entry_block->entry_num == ENTRY_PER_BLOCK) log_tail++;
    //log tail reaches the end of log segment, return 507 to notify users
    if(log_tail == this->CHK_BLOCK_START_IDX) return make_pair(-2, 0);
    msync(entry_block, BYTE_PER_BLOCK, MS_SYNC);
    munmap(entry_block, BYTE_PER_BLOCK);
    close(fd);
    return make_pair(1, 0);
}

uint64_t FileSystem::checksum(void *block) {
    uint64_t res = MAGIC_NUMBER;
    uint64_t *byte = (uint64_t*) block;
    //skip first 8 byte, and calculate checksum every 8 byte
    for(int i=1; i<BYTE_PER_BLOCK/8; i++){
        res = res ^ byte[i];
    }
    return res;
}

pair<int, int> FileSystem::checkpoint() {
    log_tail = 0;
    this->generation++;
    list<Edges> edge_list = transfer_to_struct();
    int fd =  open(this->filename, O_RDWR|O_DIRECT, S_IRUSR|S_IWUSR);
    if(fd == -1){
        printf("Encounter error when opening disk");
        return make_pair(-1, -1);
    }
    //read super_block
    SuperBlock super_block;
    read_super_block(fd, super_block);
    //calculate checksum
    uint64_t chksum = checksum((void *) &super_block);
     uint64_t memory_size = 0;
    if(super_block.checksum == chksum){// super_block is valid
        //test if graph size exceeds 8GB, we should return 507 to notify users
        memory_size = edge_list.size() / (1024 * 1024 * 1024) * sizeof(Edges);
        if(memory_size > CHECKPOINT_SIZE) return make_pair(-2, 0);
        memory_size = edge_list.size() * sizeof(Edges);
        Edges* check_point_map = (Edges*)mmap(NULL, memory_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, super_block.checkpoint_start * BYTE_PER_BLOCK);
        if(check_point_map == MAP_FAILED){
            return make_pair(-1, -1);
        }
        uint64_t counter = 0;
        for(auto itr = edge_list.begin(); itr != edge_list.end(); ++ itr){
            (check_point_map + counter) -> node_a = itr -> node_a;
            (check_point_map + counter) -> node_b = itr -> node_b;
            counter ++;
        }
        msync(check_point_map, memory_size, MS_SYNC);
        munmap(check_point_map, memory_size);
    }

    super_block.checkpoint_size = memory_size;
    super_block.cur_gen = this->generation;
    write_super_block(fd, super_block);
    close(fd);
    return make_pair(1, 0);
}

list<Edges> FileSystem :: transfer_to_struct() {
    unordered_map<uint64_t , unordered_set<uint64_t >> graph_map = graph->get_map();
    list<Edges> edge_list;
    Edges edges;
    for(auto itr = graph_map.begin(); itr != graph_map.end(); ++itr){
        uint64_t node_a = itr->first;
        unordered_set<uint64_t > node_set = itr->second;
        if(node_set.empty()){
            edges.node_a = node_a;
            edges.node_b = node_a;
            edge_list.insert(edge_list.begin(), edges);
            continue;
        }
        for(auto set_itr = node_set.begin(); set_itr != node_set.end(); ++set_itr){
            edges.node_a = node_a;
            edges.node_b = *set_itr;
            //TODO: need to be fixed, multiple insert [a, b] and [b, a]
            edge_list.insert(edge_list.begin(), edges);
        }
    }
    return edge_list;
};

Graph* FileSystem :: transfer_to_map(list<Edges> edge_list){
    Graph *new_graph = new Graph();
    for(auto itr = edge_list.begin(); itr != edge_list.end(); ++ itr){
        Edges edges = *itr;
        new_graph -> add_node(edges.node_a);
        if(edges.node_a != edges.node_b){
            new_graph -> add_node(edges.node_b);
            new_graph -> add_edge(edges.node_a, edges.node_b);
        }
    }
    return new_graph;
};

bool FileSystem::startup() {
    int fd =  open(this->filename, O_RDWR|O_DIRECT, S_IRUSR|S_IWUSR);
    if(fd == -1){
        printf("Encounter error when opening disk");
        exit(-1);
    }
    //read super_block
    SuperBlock super_block;
    read_super_block(fd, super_block);
    this->generation = super_block.cur_gen;
    uint64_t chksum = checksum((void *) & super_block);
    if(super_block.checksum == chksum){//super block is valid
        //read check point
        list<Edges> edges_list;
        Edges* edges_map = (Edges* ) mmap(NULL, super_block.checkpoint_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, super_block.checkpoint_start * BYTE_PER_BLOCK);
        uint64_t counter = super_block.checkpoint_size / sizeof(Edges);
        for(int i = 0; i < counter; ++ i){
            Edges edge;
            edge.node_a = (edges_map + i) -> node_a;
            edge.node_b = (edges_map + i) -> node_b;
            edges_list.insert(edges_list.begin(), edge);
        }
        graph = transfer_to_map(edges_list);

        //read log and replay
        EntryBlock *entry_block_map = (EntryBlock *) mmap(NULL, super_block.log_seg_size * BYTE_PER_BLOCK, PROT_READ | PROT_WRITE, MAP_SHARED, fd, super_block.log_seg_start * BYTE_PER_BLOCK);
        while(checksum(((void *)entry_block_map )) == entry_block_map->checksum && entry_block_map->gen_num == generation){
            for(int i=0; i<entry_block_map->entry_num; i++){
                switch (entry_block_map->entry[i].opcode){
                    case 0:
                        graph->add_node(entry_block_map->entry[i].node_a);
                        break;
                    case 1:
                        graph->add_edge(entry_block_map->entry[i].node_a, entry_block_map->entry[i].node_b);
                        break;
                    case 2:
                        graph->remove_node(entry_block_map->entry[i].node_a);
                        break;
                    case 3:
                        graph->remove_edge(entry_block_map->entry[i].node_a, entry_block_map->entry[i].node_b);
                        break;
                    default:
                        printf("Operation code is not supported");
                        break;
                }
            }
            entry_block_map++;
        }
    } else {// super block is invalid
        printf("Super block is damaged, please reset using -f");
    }
    close(fd);
    return true;
}

bool FileSystem::format() {
    //always reset log_tail to zero
    log_tail = 0;
    int fd =  open(this->filename, O_RDWR|O_DIRECT, S_IRUSR|S_IWUSR);
    if(fd == -1){
        printf("Encounter error when opening disk");
        exit(-1);
    }

    //read super_block
    SuperBlock super_block;
    read_super_block(fd, super_block);

    //calculate the checksum of super_block
    uint64_t chksum = checksum((void *) &super_block);


    if(super_block.checksum == chksum){//valid
        super_block.cur_gen++;
    } else{// invalid
        super_block.cur_gen = 0;
    }

    //reset graph
    Graph *graph = new Graph();
    super_block.log_seg_start = 1;
    super_block.log_seg_size = this->CHK_BLOCK_START_IDX - 1;
    super_block.checkpoint_start = 512 * 1024;
    super_block.checkpoint_size = 0;

    //renew generation and write super_block
    this->generation = super_block.cur_gen;
    write_super_block(fd, super_block);
    close(fd);
    return true;
}