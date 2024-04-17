#include <stdlib.h>

#include "trees.h"
#include "utils.h"

bt_node_t* rotate_left(bt_node_t* root)
{
    bt_node_t* root_right = root->right;
    bt_node_t* root_left_subchild = root_right->left;

    root_right->left = root;
    root->right = root_left_subchild;

    return root_right;
}

bt_node_t* rotate_right(bt_node_t* root)
{
    bt_node_t* root_left = root->left;
    bt_node_t* root_right_subchild = root_left->right;

    root_left->right = root;
    root->left = root_right_subchild;

    return root_left;
}

bt_node_t* init_bt_node(const int data, bt_node_t* left, bt_node_t* right)
{
    bt_node_t* root = malloc(sizeof(bt_node_t));

    if (root == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a new binary tree node.\n");
        exit(1);
    }

    root->data = data;
    root->left = left;
    root->right = right;

    return root;
}

void display_bt(FILE* stream, const bt_node_t* node, const bt_traversal_t traversal)
{
    if (node == NULL)
        return;

    switch (traversal)
    {
        case BT_PRE_ORDER:
        {
            fprintf(stream, "%d\n", node->data);
            display_bt(stream, node->left, traversal);
            display_bt(stream, node->right, traversal);
        }

        case BT_IN_ORDER:
        {
            display_bt(stream, node->left, traversal);
            fprintf(stream, "%d\n", node->data);
            display_bt(stream, node->right, traversal);
        }

        case BT_POST_ORDER:
        {
            display_bt(stream, node->left, traversal);
            display_bt(stream, node->right, traversal);
            fprintf(stream, "%d\n", node->data);
        }
    }
}

size_t get_node_height(const bt_node_t* node)
{
    if (node == NULL)
        return 0;

    return size_t_max(get_node_height(node->left), get_node_height(node->right)) + 1;
}

int get_node_balance_factor(const bt_node_t* node)
{
    if (node == NULL)
        return 0;

    return get_node_height(node->left) - get_node_height(node->right);
}

size_t get_bt_diameter(const bt_node_t* root, size_t* height)
{
    if (root == NULL)
        return 0;

    const size_t left_height = get_bt_diameter(root->left, height);
    const size_t right_height = get_bt_diameter(root->right, height);

    *height = size_t_max(*height, left_height + right_height);
    return size_t_max(left_height, right_height) + 1;
}

void insert_in_bst(bt_node_t** root, const int data)
{
    if (*root == NULL)
    {
        *root = init_bt_node(data, NULL, NULL);
        return;
    }

    bt_node_t* parent = *root;
    bt_node_t* child = *root;
    bool is_left_child = true;

    while (child != NULL)
    {
        parent = child;

        if (parent->data == data)
        {
            fprintf(stderr, "Cannot enter duplicate values in a binary search tree.\n");
            return;
        }

        if (parent->data > data)
        {
            child = parent->left;
            is_left_child = true;
        }

        else
        {
            child = parent->right;
            is_left_child = false;
        }
    }

    bt_node_t* new_node = parent->left = init_bt_node(data, NULL, NULL);
    if (is_left_child)
        parent->left = new_node;
    else
        parent->right = new_node;
}

bt_node_t* insert_in_avl_tree(bt_node_t* root, const int data)
{
    if (root == NULL)
        return init_bt_node(data, NULL, NULL);

    if (root->data == data)
        return root;

    if (root->data > data)
        root->left = insert_in_avl_tree(root->left, data);
    else
        root->right = insert_in_avl_tree(root->right, data);

    const int balance_factor = get_node_balance_factor(root);

    if (balance_factor > 1 && root->left->data > data)
        return rotate_right(root);

    if (balance_factor < -1 && root->right->data < data)
        return rotate_left(root);

    if (balance_factor > 1 && root->left->data < data)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    if (balance_factor < -1 && root->right->data > data)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

bool search_in_bst(const bt_node_t** root, const int target)
{
    if (*root == NULL)
        return false;

    const bt_node_t* node = *root;
    while (node != NULL)
    {
        if (node->data == target)
            return true;

        if (node->data > target)
            node = node->left;
        else
            node = node->right;
    }

    return false;
}
