// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef TOPOLOGICAL_SORT_H
#define TOPOLOGICAL_SORT_H

#include <stddef.h>
#include "../Q1/graph.h"
#include "../utils/stack.h"

typedef struct
{
    size_t vertices;
    list_node_t** adjacency_list;
} graph_t;

graph_t* init_graph(const size_t vertices, list_node_t** adjacency_list)
{
    graph_t* graph = malloc(sizeof(graph_t));

    if (graph == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for a graph.\n");
        exit(1);
    }

    graph->vertices = vertices;
    graph->adjacency_list = adjacency_list;

    return graph;
}

void topological_sort_helper(graph_t* graph, size_t vertex, bool* visited, stack_t stack)
{
    visited[vertex] = true;

    for (size_t i = 0; i < graph->vertices; i++)
    {
        if (!visited[i]) { topological_sort_helper(graph, i, visited, stack); }
    }

    push_to_stack(&stack, vertex);
}

void topological_sort(graph_t* graph)
{
    bool* visited = malloc(sizeof(bool) * graph->vertices);
    stack_t stack = init_stack(graph->vertices);

    if (visited == NULL)
    {
        fprintf(stderr, "Could not allocate enough space for a visited array.\n");
        return;
    }

    for (size_t i = 0; i < graph->vertices; i++) { visited[i] = false; }

    for (size_t i = 0; i < graph->vertices; i++)
    {
        if (!visited[i]) { topological_sort_helper(graph, i, visited, stack); }
    }

    while (stack.size != 0)
    {
        printf("%d\n", pop_from_stack(&stack));
    }

    free(visited);
    free_stack(stack);
}

#endif //TOPOLOGICAL_SORT_H
