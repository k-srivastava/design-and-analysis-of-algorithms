#ifndef TREES_H
#define TREES_H

#include <stdbool.h>
#include <stdio.h>

typedef struct bt_node
{
    int data;
    struct bt_node* left;
    struct bt_node* right;
} bt_node_t;

typedef enum bt_traversal
{
    BT_PRE_ORDER,
    BT_IN_ORDER,
    BT_POST_ORDER
} bt_traversal_t;

bt_node_t* init_bt_node(int data, bt_node_t* left, bt_node_t* right);

void display_bt(FILE* stream, const bt_node_t* node, bt_traversal_t traversal);

size_t get_node_height(const bt_node_t* node);

int get_node_balance_factor(const bt_node_t* node);

size_t get_bt_diameter(const bt_node_t* root, size_t* height);

void insert_in_bst(bt_node_t** root, int data);

bt_node_t* insert_in_avl_tree(bt_node_t* root, int data);

bool search_in_bst(const bt_node_t** root, int target);

#endif //TREES_H
