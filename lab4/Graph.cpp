//
// Created by gc on 16-9-15.
//
#include "Graph.hpp"
#include <thread>
#include <mutex>
#include <iostream>

Graph *graph = new Graph();
std::mutex mtx;

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
        std::cout<< "Already exist"<<std::endl;
        return std::make_pair(0, 0);
    }
    else{
        unordered_set<uint64_t> set;
        map.insert({node_id, set});
        return std::make_pair(1, 1);
    }
}



/**
 *
 * @param node_a_id lower-numbered-id
 * @param node_b_id higher-numbered-id
 * @return
 */
pair<int, int> Graph::add_edge(uint64_t node_a_id, uint64_t node_b_id){
    if(node_a_id == node_b_id) return std::make_pair(-1, -1);
    auto node_a = map.find(node_a_id);
    if(node_a  == map.end()){
        std::cout<< "Node does not exist"<<std::endl;
        return make_pair(-1, -1);
    }
    else{
        unordered_set<uint64_t> node_a_adj = node_a->second;
        auto key_a = node_a_adj.find(node_b_id);
        node_a_adj.insert({node_b_id});
        map[node_a_id] = node_a_adj;
        return key_a == node_a_adj.end() ? std::make_pair(1, 1) : std::make_pair(0, 0);
    }
}


/**
 *
 * @param node_a_id lower-numbered-id
 * @param node_b_id higher-numbered-id
 * @return
 */
pair<int, int> Graph::remove_edge(uint64_t node_a_id, uint64_t node_b_id){

    pair<int, int> result = get_edge(node_a_id, node_b_id);
    if(result.first == -1 || result.second == 0) return std::make_pair(-1, -1);

    auto node_a = map.find(node_a_id);
    uint64_t node_a_result = 0;

    if(node_a == map.end()) return std::make_pair(-1, -1);

    unordered_set<uint64_t> node_a_adj = node_a -> second;

    if(node_a_adj.find(node_b_id) != node_a_adj.end()) node_a_result = node_a_adj.erase(node_b_id);

    map[node_a_id] = node_a_adj;

    if(node_a_result == 1) return std::make_pair(1, 1);
    return std::make_pair(-1 , -1);

}

pair<int, int> Graph::get_node(uint64_t node_id){
    auto node = map.find(node_id);
    if(node != map.end()) return std::make_pair(1, 1);
    return std::make_pair(1, 0);
}

pair<int, int> Graph::get_edge(uint64_t node_a_id, uint64_t node_b_id){
    auto node_a = map.find(node_a_id);
    if(node_a == map.end()) return std::make_pair(-1, -1);
    unordered_set<uint64_t> node_a_adj = node_a -> second;
    if(node_a_adj.find(node_b_id) != node_a_adj.end())
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
