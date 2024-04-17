#include "graphs.h"

#include <stdbool.h>
#include <stdlib.h>

size_t min_distance_idx(const size_t vertices, int distances[vertices], bool included[vertices])
{
    int min = EDGE_MAX;
    size_t min_idx = 0;

    for (size_t i = 0; i < vertices; i++)
    {
        if (!included[i] && distances[i] <= min)
        {
            min = distances[i];
            min_idx = i;
        }
    }

    return min_idx;
}

size_t min_key_idx(const size_t vertices, int keys[vertices], bool included[vertices])
{
    int min = INT_MAX;
    size_t min_idx = 0;

    for (size_t i = 0; i < vertices; i++)
    {
        if (!included[i] && keys[i] < min)
        {
            min = keys[i];
            min_idx = i;
        }
    }

    return min_idx;
}

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

void display_min_spanning_tree(const size_t vertices, int parents[vertices], int distance_matrix[vertices][vertices])
{
    printf("Edge\tWeight\n");
    for (size_t i = 1; i < vertices; i++)
        printf("%d - %zu\t%d\n", parents[i], i, distance_matrix[i][parents[i]]);
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

void prims_algorithm(size_t vertices, int distance_matrix[vertices][vertices])
{
    int* parents = malloc(sizeof(int) * vertices);
    int* keys = malloc(sizeof(int) * vertices);
    bool* included = malloc(sizeof(bool) * vertices);

    if (parents == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for integer array of length %zu.\n", vertices);
        exit(1);
    }

    if (keys == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for integer array of length %zu.\n", vertices);
        exit(1);
    }

    if (included == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for boolean array of length %zu.\n", vertices);
        exit(1);
    }

    for (size_t i = 0; i < vertices; i++)
    {
        keys[i] = INT_MAX;
        included[i] = false;
    }

    keys[0] = 0;
    parents[0] = -1;

    for (size_t count = 0; count < vertices - 1; count++)
    {
        const int idx = min_key_idx(vertices, keys, included);
        included[idx] = true;

        for (size_t vertex = 0; vertex < vertices; vertex++)
        {
            const int current = distance_matrix[idx][vertex];
            if (current && !included[vertex] && current < keys[vertex])
            {
                parents[vertex] = idx;
                keys[vertex] = current;
            }
        }
    }

    display_min_spanning_tree(vertices, parents, distance_matrix);

    free(included);
    free(keys);
    free(parents);
}

int* djiktras_algorithm(
    const size_t vertices, const size_t start_vertex_idx,
    int distance_matrix[vertices][vertices]
)
{
    int* distances = malloc(sizeof(int) * vertices);
    bool* included = malloc(sizeof(bool) * vertices);

    if (distances == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for distance array of length %zu.\n", vertices);
        exit(1);
    }

    if (included == NULL)
    {
        fprintf(stderr, "Could not allocate enough memory for boolean array of length %zu.\n", vertices);
        exit(1);
    }

    for (size_t i = 0; i < vertices; i++)
    {
        distances[i] = EDGE_MAX;
        included[i] = false;
    }

    distances[start_vertex_idx] = 0;

    for (size_t i = 0; i < vertices - 1; i++)
    {
        const size_t min_idx = min_distance_idx(vertices, distances, included);
        included[min_idx] = true;

        for (size_t j = 0; j < vertices; j++)
        {
            const int new_distance = distances[min_idx] + distance_matrix[min_idx][j];
            if (!included[j] && distance_matrix[min_idx][j] && distances[min_idx] != EDGE_MAX && new_distance <
                distances[j])
                distances[j] = new_distance;
        }
    }

    free(included);

    return distances;
}
