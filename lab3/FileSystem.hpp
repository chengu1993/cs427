#include <stdint.h>
#include <cstdint>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <list>
#include "Graph.hpp"

#ifndef LAB1_FILESYSTEM_HPP
#define LAB1_FILESYSTEM_HPP

const static int ENTRY_PER_BLOCK = 204;

extern Graph *graph;


typedef struct SuperBlock{
    uint64_t checksum;
    uint32_t cur_gen;
    uint32_t log_seg_start;
    uint32_t log_seg_size;
    uint32_t checkpoint_start;
    uint64_t checkpoint_size;
    uint64_t paddings[508];
};

typedef struct Entry{
    /** 0 for add_node
     *  1 for add_edge
     *  2 for remove_node
     *  3 for remove_edge*/
    uint32_t opcode;
    uint64_t node_a;
    uint64_t node_b;
};

typedef struct EntryBlock{
    uint64_t checksum;
    uint32_t gen_num;
    uint32_t entry_num;
    Entry entry[ENTRY_PER_BLOCK];
};

typedef struct Edges{
    uint64_t node_a;
    uint64_t node_b;
};

class FileSystem {
public:

    /**
     * Initialization
     * @param filename the disk name
     * @return
     */
    FileSystem(char *filename);

    /**
     *read supuer blcok
     * @param fd file description
     * @param super_block
     * @return
     */
    bool read_super_block(int fd, SuperBlock &super_block);

    /**
     *calculate super block checksum and write super block
     * @param fd file description
     * @param super_block
     * @return
     */
    bool write_super_block(int fd, SuperBlock &super_block);

    /**
     *Record a operation into log segment
     * @param optcode operation code
     * @param node_a
     * @param node_b
     * @return
     */
    pair<int, int> record(uint32_t optcode, uint64_t node_a, uint64_t node_b);

    /**
     *Calculate block checksum (including super block and entry block)
     * @param block pointer to block
     * @return
     */
    uint64_t checksum(void *block);

    /**
     * @return
     *  1 HTTP 200
     * -1 HTTP 400
     * -2 HTTP 507
     */
    pair<int, int> checkpoint();


    /**
       *Transefer map to struck
       * @return list of edges
       */
    list<Edges> transfer_to_struct();


    /**
     *Transfer struct to graph
     * @param edge_list
     * @return graph
     */
    Graph* transfer_to_map(list<Edges> edge_list);



    /**
     *Start up the file system
     * @return
     */
    bool startup();

    /**
     *Format the file system
     * @return
     */
    bool format();


private:
    const static uint32_t SUPER_BLOCK_START_IDX = 0;
    const static uint32_t LOG_BLOCK_START_IDX = 1;
    const static uint32_t CHK_BLOCK_START_IDX = 524288;
    const static uint32_t BYTE_PER_BLOCK = 4096;
    const static uint64_t MAGIC_NUMBER = 888;
    const static uint64_t CHECKPOINT_SIZE = 8; // in GB

    char *filename;
    uint32_t generation;
    uint32_t log_tail;
};


#endif //LAB1_FILESYSTEM_HPP
