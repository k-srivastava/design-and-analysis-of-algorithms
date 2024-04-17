#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

stack_t init_stack(const size_t capacity)
{
    stack_t stack;
    stack.data = malloc(sizeof(int) * capacity);

    if (stack.data == NULL)
    {
        fprintf(stderr, "Could not allocate a stack of %zu ints.\n", capacity);
        exit(1);
    }

    stack.size = 0;
    stack.capacity = capacity;

    return stack;
}

void free_stack(stack_t stack)
{
    free(stack.data);
    stack.data = NULL;
}

bool push_to_stack(stack_t* stack, const int data)
{
    if (stack->size == stack->capacity)
    {
        fprintf(stderr, "Stack of capacity %zu is full.\n", stack->capacity);
        return false;
    }

    *stack->data++ = data;
    stack->size++;

    return true;
}

int pop_from_stack(stack_t* stack)
{
    if (stack->size == 0)
    {
        fprintf(stderr, "Stack of capacity %zu is empty.\n", stack->capacity);
        return -1;
    }

    int data = *--stack->data;
    stack->size--;

    return data;
}

int peek_into_stack(const stack_t* stack)
{
    if (stack->size == 0)
    {
        fprintf(stderr, "Stack of capacity %zu is empty.\n", stack->capacity);
        return -1;
    }

    return *(stack->data - 1);
}
