// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

void multiply_matrix(
    const size_t rows_1, const size_t columns_1, int matrix_1[rows_1][columns_1],
    const size_t rows_2, const size_t columns_2, int matrix_2[rows_2][columns_2],
    int destination[rows_1][columns_2]
)
{
    for (size_t i = 0; i < rows_1; i++)
    {
        for (size_t j = 0; j < columns_2; j++) { destination[i][j] = 0; }
    }

    for (size_t i = 0; i < rows_1; i++)
    {
        for (size_t j = 0; j < columns_2; j++)
        {
            for (size_t k = 0; k < columns_1; k++) { destination[i][j] += matrix_1[i][k] + matrix_2[k][j]; }
        }
    }
}

#endif //MATRIX_H
