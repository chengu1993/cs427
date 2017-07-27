//
// Created by gc on 16-9-18.
//
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "candidateNode.hpp"
#ifndef LAB1_GETTHESHORTESTPATH_HPP
#define LAB1_GETTHESHORTESTPATH_HPP


class getTheShortestPath {
public:
    unordered_map<uint64_t, unordered_set<uint64_t > > map;
    priority_queue<candidateNode> nextNodes;
    unordered_set<uint64_t > excludedNodes;
    getTheShortestPath(unordered_map<uint64_t, unordered_set<uint64_t >> graph);
    pair<int, uint64_t > getPathLength(uint64_t node_start, uint64_t node_end, uint64_t step);
};


#endif //LAB1_GETTHESHORTESTPATH_HPP
