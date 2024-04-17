#ifndef GRAPHS_H
#define GRAPHS_H

#include <limits.h>
#include <stdio.h>

#define EDGE_MAX INT_MAX / 3
#define EDGE_MIN INT_MIN / 3

void display_adjacency_matrix(FILE* stream, size_t vertices, int adjacency_matrix[vertices][vertices]);

// TODO: Add implementation.
size_t travelling_salesman_brute_force(size_t cities, size_t distance_matrix[cities][cities]);

void warshalls_algorithm(size_t vertices, int distance_matrix[vertices][vertices]);

void prims_algorithm(size_t vertices, int distance_matrix[vertices][vertices]);

int* djiktras_algorithm(size_t vertices, size_t start_vertex_idx, int distance_matrix[vertices][vertices]);

#endif //GRAPHS_H
