//
// Created by gc on 16-9-18.
//

#include "getTheShortestPath.hpp"



getTheShortestPath :: getTheShortestPath(unordered_map<uint64_t, unordered_set<uint64_t >> map) : map(map) {};

bool operator < (candidateNode node_a, candidateNode node_b){
    return node_a.distance_from_start > node_b.distance_from_start;
}

pair<int, uint64_t > getTheShortestPath :: getPathLength(uint64_t node_start, uint64_t node_end, uint64_t step) {
    // candidateNode* startNode = new candidateNode(node_start, 0);
    excludedNodes.insert({node_start});
    if(node_start == node_end) return std::make_pair(1, step);
    auto node_a = map.find(node_start);
    auto node_b = map.find(node_end);
    if(node_a == map.end() || node_b == map.end()) return make_pair(-1, -1);
    unordered_set<uint64_t > node_a_adj = node_a -> second;
    for(auto itr = node_a_adj.begin(); itr != node_a_adj.end(); ++itr){
        candidateNode* node = new candidateNode(*itr, step + 1);
        if(excludedNodes.find(node -> node_id) == excludedNodes.end()){
            nextNodes.push(*node);
        }
        nextNodes.push(*node);
    }
    candidateNode next;
    do{
        if(nextNodes.empty()) return make_pair(0, -1);
        next = nextNodes.top();
        nextNodes.pop();
    }while(excludedNodes.find(next.node_id) != excludedNodes.end());
    return getPathLength(next.node_id, node_end, next.distance_from_start);
};
