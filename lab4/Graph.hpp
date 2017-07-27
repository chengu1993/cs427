//
// Created by gc on 16-9-15.
//




#ifndef LAB1_GRAPH_HPP
#define LAB1_GRAPH_HPP

#include <stdint.h>
#include <unordered_map>
#include <unordered_set>
#include "mongoose.h"

using namespace std;
static const mg_str graph_add_node = MG_MK_STR("add_node");
static const mg_str graph_add_edge = MG_MK_STR("add_edge");
static const mg_str graph_remove_node = MG_MK_STR("remove_node");
static const mg_str graph_remove_edge = MG_MK_STR("remove_edge");
static const mg_str graph_get_node = MG_MK_STR("get_node");
static const mg_str graph_get_edge = MG_MK_STR("get_edge");
static const mg_str graph_get_neighbors = MG_MK_STR("get_neighbors");
static const mg_str graph_shorest_path = MG_MK_STR("shortest_path");


class Graph{
private:
    unordered_map<uint64_t , unordered_set<uint64_t>>  map;
public:
    Graph();

    /**1 success
     * 0 node already exists
     * */
    pair<int, int> add_node(uint64_t node_id);

    /**1 success
     * 0 edge already exists
     * -1 either node does not exist
     * */
    pair<int, int> add_edge(uint64_t node_a_id, uint64_t node_b_id);

    /**1 success
     * -1 edge does not exist
     * */
    pair<int, int> remove_edge(uint64_t node_a_id, uint64_t node_b_id);

    /**1 success
     *
     * */
    pair<int, int> get_node(uint64_t node_id);

    /**1 success
     * -1  either node does not exist
     * */
    pair<int, int> get_edge(uint64_t node_a_id, uint64_t node_b_id);

    /**1 success
     * -1 node does not exist
     * */
    pair<int, unordered_set<uint64_t>> get_neighbors(uint64_t node_id);
};


#endif //LAB1_GRAPH_HPP

