#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct bt_node
{
    int data;
    struct bt_node* left;
    struct bt_node* right;
} bt_node_t;

bt_node_t* init_bt_node(int data, bt_node_t* left, bt_node_t* right);

#endif //BINARY_TREE_H
