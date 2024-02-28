#include <stdlib.h>

#include "binary_tree.h"

#include <stdio.h>

bt_node_t* init_bt_node(const int data, bt_node_t* left, bt_node_t* right)
{
    bt_node_t* node = malloc(sizeof(bt_node_t));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a binary tree node.\n");
        exit(1);
    }

    node->data = data;
    node->left = left;
    node->right = right;

    return node;
}
