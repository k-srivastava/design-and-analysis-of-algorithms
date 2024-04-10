#ifndef GRAPHS_H
#define GRAPHS_H

#include <limits.h>
#include <stdio.h>

#define EDGE_MAX INT_MAX / 3
#define EDGE_MIN INT_MIN / 3

void display_adjacency_matrix(FILE* stream, size_t vertices, int adjacency_matrix[vertices][vertices]);

void warshalls_algorithm(size_t vertices, int distance_matrix[vertices][vertices]);

#endif //GRAPHS_H
