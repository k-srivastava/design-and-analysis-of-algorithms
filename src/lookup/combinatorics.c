#include <stdlib.h>

#include "combinatorics.h"
#include "utils.h"

int calculate_cost(const size_t jobs, int costs[jobs][jobs], int permutation[jobs])
{
    int total_cost = 0;
    for (size_t i = 0; i < jobs; i++)
        total_cost += costs[i][permutation[i]];
    return total_cost;
}

bool is_safe_position(const size_t length, bool board[length][length], const size_t row, const size_t column)
{
    for (size_t i = 0; i < column; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = column; j >= 0 && i < length; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

int find_ideal_assignment_cost(const size_t jobs, int costs[jobs][jobs])
{
    int* current_permutation = generate_range(0, jobs);
    bool generated_last_permutation = false;

    int total_cost = calculate_cost(jobs, costs, current_permutation);

    while (!generated_last_permutation)
    {
        int j = -1;
        for (size_t i = 0; i < jobs; i++)
            if (current_permutation[i + 1] > current_permutation[i])
                j = i;

        if (j == -1)
            generated_last_permutation = true;

        if (!generated_last_permutation)
        {
            size_t l = 0;
            for (size_t i = j + 1; i < jobs; i++)
                if (current_permutation[i] > current_permutation[j])
                    l = i;

            SWAP(current_permutation[j], current_permutation[l], int);

            const size_t k = (jobs - 1 - j) / 2;
            for (size_t i = 0; i < k; i++)
                SWAP(current_permutation[i + j + 1], current_permutation[jobs - i - 1], int);

            const int current_cost = calculate_cost(jobs, costs, current_permutation);
            if (current_cost < total_cost)
                total_cost = current_cost;
        }
    }

    free(current_permutation);
    return total_cost;
}

size_t get_maximum_profit(const size_t capacity, const size_t length, size_t weights[length], size_t profits[length])
{
    if (length == 0 || capacity == 0)
        return 0;

    if (weights[length - 1] > capacity)
        return get_maximum_profit(capacity, length - 1, weights, profits);

    return size_t_max(
        profits[length - 1] + get_maximum_profit(capacity - weights[length - 1], length - 1, weights, profits),
        get_maximum_profit(capacity, length - 1, weights, profits)
    );
}

bool solve_n_queens(const size_t length, bool board[length][length], const size_t column)
{
    if (column == length)
        return true;

    for (size_t i = 0; i < length; i++)
    {
        if (is_safe_position(length, board, i, column))
        {
            board[i][column] = true;

            if (solve_n_queens(length, board, column + 1))
                return true;

            board[i][column] = false;
        }
    }

    return false;
}
