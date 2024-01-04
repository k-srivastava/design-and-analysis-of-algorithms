// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree_node
{
    int data;
    struct binary_tree_node* left;
    struct binary_tree_node* right;
} binary_tree_node_t;

binary_tree_node_t* init_binary_tree_node(const int data, binary_tree_node_t* left, binary_tree_node_t* right)
{
    binary_tree_node_t* root = malloc(sizeof(binary_tree_node_t));

    if (root == NULL)
    {
        fprintf(stderr, "Could not allocate enough space for a new binary tree node.\n");
        exit(1);
    }

    root->data = data;
    root->left = left;
    root->right = right;

    return root;
}

void insert_in_binary_tree(binary_tree_node_t** root, const int data)
{
    if (*root == NULL)
    {
        *root = init_binary_tree_node(data, NULL, NULL);
        return;
    }

    binary_tree_node_t* parent = *root;
    binary_tree_node_t* child = *root;
    bool is_left_child = true;

    while (child != NULL)
    {
        parent = child;

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

    if (is_left_child) parent->left = init_binary_tree_node(data, NULL, NULL);
    else parent->right = init_binary_tree_node(data, NULL, NULL);
}

void search_in_binary_tree(binary_tree_node_t** root, const int target)
{
    if (*root == NULL)
    {
        printf("No root exists. Creating with target.\n");
        *root = init_binary_tree_node(target, NULL, NULL);
        return;
    }

    const binary_tree_node_t* node = *root;
    while (node != NULL)
    {
        if (node->data == target)
        {
            printf("Target found.\n");
            return;
        }

        if (node->data > target) node = node->left;
        else node = node->right;
    }

    printf("Target not found. Creating node.\n");
    insert_in_binary_tree(root, target);
}

void display_binary_tree(FILE* stream, const binary_tree_node_t* node)
{
    if (node != NULL)
    {
        display_binary_tree(stream, node->left);
        fprintf(stream, "%d\n", node->data);
        display_binary_tree(stream, node->right);
    }
}

#endif //BINARY_TREE_H
