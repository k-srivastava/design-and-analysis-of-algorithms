#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>

typedef struct bt_node
{
    int data;
    struct bt_node* left;
    struct bt_node* right;
} bt_node_t;

typedef enum bt_display
{
    BT_PRE_ORDER,
    BT_IN_ORDER,
    BT_POST_ORDER
} bt_display_t;

bt_node_t* init_bt_node(int data, bt_node_t* left, bt_node_t* right);

size_t get_node_height(const bt_node_t* node);

void display_bt(FILE* stream, const bt_node_t* node, bt_display_t display_type);

#endif //BINARY_TREE_H
