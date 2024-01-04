#include "binary_tree.h"
#include "graph.h"

#define NUM_NODES 4

/*
 *  Graph as designed on paper represented in adjacency lists and adjacency matrices.
 *
 *      (1) - (2)
 *       |  \  |
 *      (4)   (3)
 *      |_|
 */
list_node_t* adjacency_list[NUM_NODES] = {
    init_list_node(1, init_list_node(2, init_list_node(3, init_list_node(4, NULL)))),
    init_list_node(2, init_list_node(1, init_list_node(3, NULL))),
    init_list_node(3, init_list_node(1, init_list_node(2, NULL))),
    init_list_node(4, init_list_node(1, init_list_node(4, NULL))),
};

bool adjacency_matrix[NUM_NODES][NUM_NODES] = {
    { false, true, true, true },
    { true, false, true, false },
    { false, true, false, false },
    { true, false, false, true },
};

int main(void) {}

#undef NUM_NODES
