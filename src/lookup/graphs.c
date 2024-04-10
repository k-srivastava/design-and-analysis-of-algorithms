#include "graphs.h"

void display_adjacency_matrix(FILE* stream, const size_t vertices, int adjacency_matrix[vertices][vertices])
{
    fprintf(stream, "{\n");
    for (size_t i = 0; i < vertices; i++)
    {
        fprintf(stream, "\t{\t");
        for (size_t j = 0; j < vertices; j++)
        {
            const int value = adjacency_matrix[i][j];

            if (value == EDGE_MAX)
                fprintf(stream, "INF\t");
            else if (value == EDGE_MIN)
                fprintf(stream, "-INF\t");
            else
                fprintf(stream, "%d\t", value);
        }
        fprintf(stream, "}\n");
    }
    fprintf(stream, "}\n");
}

void warshalls_algorithm(const size_t vertices, int distance_matrix[vertices][vertices])
{
    for (size_t k = 0; k < vertices; k++)
    {
        for (size_t i = 0; i < vertices; i++)
        {
            for (size_t j = 0; j < vertices; j++)
            {
                const int current_distance = distance_matrix[i][k] + distance_matrix[k][j];
                if (current_distance < distance_matrix[i][j])
                    distance_matrix[i][j] = current_distance;
            }
        }
    }
}
