//
// Created by Freedom Coder on 05.10.2021.
//

#include <stdlib.h>
#include "stack.h"

struct MStack *createStack()
{
    struct MStack *stack = malloc(sizeof(struct MStack));
    stack->top = NULL;
    return stack;
}

void push(struct MStack *stack, void* item)
{
    struct MStackElement *top = stack->top;
    struct MStackElement *nptr = malloc(sizeof(struct MStackElement));
    nptr->data = item;
    nptr->next = top;
    stack->top = nptr;
}

void* pop(struct MStack *stack)
{
    struct MStackElement *top = stack->top;
    if (top != NULL) {
        struct MStackElement *temp;
        temp = top;
        stack->top = top->next;
        free(temp);
        return top->data;
    }
    return NULL;
}

void* peek(struct MStack *stack)
{
    if (stack->top != NULL) return stack->top->data;
    return NULL;
}

int empty(struct MStack *stack)
{
    return stack->top == NULL;
}