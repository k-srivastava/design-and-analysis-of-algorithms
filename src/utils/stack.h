#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
    size_t size;
    size_t capacity;
    int* data;
} stack_t;

stack_t init_stack(size_t capacity);

void free_stack(stack_t stack);

bool push_to_stack(stack_t* stack, int data);

int pop_from_stack(stack_t* stack);

int peek_into_stack(const stack_t* stack);

#endif //STACK_H
