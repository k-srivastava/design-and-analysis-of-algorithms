#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "binary_tree.h"

bt_node_t* insert_into_avl_tree(bt_node_t* root, int data);

int get_node_balance_factor(const bt_node_t* node);

#endif //AVL_TREE_H
