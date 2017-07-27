//
// Created by gc on 16-9-18.
//

#include "candidateNode.hpp"



candidateNode ::candidateNode(uint64_t node_id, uint64_t distance_from_start) : node_id(node_id), distance_from_start(distance_from_start) {}
candidateNode ::candidateNode() {this -> node_id = 0; this -> distance_from_start = 0;};