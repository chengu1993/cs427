//
// Created by gc on 16-9-15.
//
#include "Graph.hpp"
#include <iostream>
#include "getTheShortestPath.hpp"


class Comparator
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second > n2.second;
    }
};



Graph::Graph() {
    map = {};
}


pair<int, int> Graph::add_node(uint64_t node_id){
    auto adj_matrix = map.find(node_id);
    if(adj_matrix != map.end()){
        return std::make_pair(0, 0);
    }
    else{
        unordered_set<uint64_t> set;
        map.insert({node_id, set});
        return std::make_pair(1, 1);
    }
}

pair<int, int> Graph::add_edge(uint64_t node_a_id, uint64_t node_b_id){
    if(node_a_id == node_b_id) return std::make_pair(-1, -1);
    auto node_a = map.find(node_a_id);
    auto node_b = map.find(node_b_id);
    if(node_a  == map.end() || node_b == map.end()){
        std::cout<< "Node does not exist"<<std::endl;
        return make_pair(-1, -1);
    }
    else{
        unordered_set<uint64_t> node_a_adj = node_a->second;
        unordered_set<uint64_t> node_b_adj = node_b->second;
        auto key_a = node_a_adj.find(node_b_id);
        auto key_b = node_b_adj.find(node_a_id);
        node_a_adj.insert({node_b_id});
        node_b_adj.insert({node_a_id});
        map[node_a_id] = node_a_adj;
        map[node_b_id] = node_b_adj;
        return key_a == node_a_adj.end() || key_b == node_b_adj.end() ? std::make_pair(1, 1) : std::make_pair(0, 0);
    }
}

pair<int, int> Graph::remove_node(uint64_t node_id){
    auto node = map.find(node_id);
    if(node == map.end()){
        cout << "Node does not exist" << endl;
        return std::make_pair(-1, -1);
    }else{
        auto node = map.find(node_id);
        unordered_set<uint64_t> node_adj = node -> second;
        for(auto itr = node_adj.begin(); itr != node_adj.end(); ++itr){
            pair<int, int> ret = remove_edge(node_id, *itr);
            if(ret.first != 1) return make_pair(-1, -1);
        }
        uint64_t count = map.erase(node_id);
        if(count == 1) return std::make_pair(1, 1);
        return std::make_pair(-1, -1);
    }
}

pair<int, int> Graph::remove_edge(uint64_t node_a_id, uint64_t node_b_id){

    pair<int, int> result = get_edge(node_a_id, node_b_id);
    if(result.first == -1 || result.second == 0) return std::make_pair(-1, -1);
    auto node_a = map.find(node_a_id);
    auto node_b = map.find(node_b_id);
    uint64_t node_a_result = 0;
    uint64_t node_b_result = 0;
    if(node_a == map.end() || node_b == map.end()) return std::make_pair(-1, -1);
    unordered_set<uint64_t> node_a_adj = node_a -> second;
    unordered_set<uint64_t> node_b_adj = node_b -> second;
    if(node_a_adj.find(node_b -> first) != node_a_adj.end()) node_a_result = node_a_adj.erase(node_b -> first);
    if(node_b_adj.find(node_a -> first) != node_b_adj.end()) node_b_result = node_b_adj.erase(node_a -> first);
    map[node_a_id] = node_a_adj;
    map[node_b_id] = node_b_adj;
    if(node_a_result == 1 && node_b_result == 1) return std::make_pair(1, 1);
    return std::make_pair(-1 , -1);

}

pair<int, int> Graph::get_node(uint64_t node_id){
    auto node = map.find(node_id);
    if(node != map.end()) return std::make_pair(1, 1);
    return std::make_pair(1, 0);
}

pair<int, int> Graph::get_edge(uint64_t node_a_id, uint64_t node_b_id){
    auto node_a = map.find(node_a_id);
    auto node_b = map.find(node_b_id);
    if(node_a == map.end() || node_b == map.end()) return std::make_pair(-1, -1);
    unordered_set<uint64_t> node_a_adj = node_a -> second;
    unordered_set<uint64_t> node_b_adj = node_b -> second;
    if(node_a_adj.find(node_b_id) != node_a_adj.end() && node_b_adj.find(node_a_id) != node_b_adj.end())
        return  std::make_pair(1, 1);
    return std::make_pair(1, 0);
}

pair<int, unordered_set<uint64_t>> Graph::get_neighbors(uint64_t node_id){
    auto node = map.find(node_id);
    if(node == map.end()){
        unordered_set<uint64_t>* setptr = new unordered_set<uint64_t>();
        return std::make_pair(-1, *setptr);
    }
    return std::make_pair(1, node -> second);
}




pair<int, uint64_t> Graph::shortest_path(uint64_t node_a_id, uint64_t node_b_id){
    getTheShortestPath* gts = new getTheShortestPath(map);
    return gts -> getPathLength(node_a_id, node_b_id, 0);
}

unordered_map<uint64_t, unordered_set<uint64_t >> Graph::get_map() {
    return this->map;
}
