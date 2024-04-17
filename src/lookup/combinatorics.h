#ifndef COMBINATORICS_H
#define COMBINATORICS_H

#include <stdbool.h>

int find_ideal_assignment_cost(size_t jobs, int costs[jobs][jobs]);

size_t get_maximum_profit(size_t capacity, size_t length, size_t weights[length], size_t profits[length]);

bool solve_n_queens(size_t length, bool board[length][length], size_t column);

#endif //COMBINATORICS_H
