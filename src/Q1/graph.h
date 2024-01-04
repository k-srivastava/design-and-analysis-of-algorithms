// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_node
{
    int data;
    struct list_node* next;
} list_node_t;

list_node_t* init_list_node(int data, list_node_t* next)
{
    list_node_t* node = malloc(sizeof(list_node_t));

    if (node == NULL)
    {
        fprintf(stderr, "Could not allocate enough space for a new list node.\n");
        exit(1);
    }

    node->data = data;
    node->next = next;

    return node;
}

void display_list_node(FILE* stream, const list_node_t* head)
{
    const list_node_t* current = head;
    while (current != NULL)
    {
        fprintf(stream, "%d -> ", current->data);
    }
    fprintf(stderr, "NULL\n");
}

bool are_nodes_adjacent(size_t num_nodes, bool adjacency_matrix[num_nodes][num_nodes], const size_t node_1, const size_t node_2)
{
    return adjacency_matrix[node_1 - 1][node_2 - 1];
}

list_node_t* get_adjacent_nodes(size_t num_nodes, list_node_t* adjacency_list[num_nodes], const size_t node)
{
    return adjacency_list[node - 1];
}

#endif //GRAPH_H
