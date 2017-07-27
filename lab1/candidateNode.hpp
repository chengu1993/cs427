//
// Created by gc on 16-9-18.
//
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
#ifndef LAB1_CANDIDATENODE_HPP
#define LAB1_CANDIDATENODE_HPP


class candidateNode {
public:
    uint64_t node_id;
    uint64_t distance_from_start;
    candidateNode(uint64_t node_id, uint64_t distance_from_start);
    candidateNode();
};


#endif //LAB1_CANDIDATENODE_HPP
