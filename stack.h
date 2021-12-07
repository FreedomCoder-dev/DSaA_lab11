//
// Created by Freedom Coder on 05.10.2021.
//

#ifndef LAB4_STACK_H
#define LAB4_STACK_H

struct MStack
{
    struct MStackElement *top;
};

struct MStackElement
{
    void* data;
    struct MStackElement *next;
};

struct MStack *createStack();
void push(struct MStack *stack, void* item);
void* pop(struct MStack *stack);
void* peek(struct MStack *stack);
int empty(struct MStack *stack);

#endif //LAB4_STACK_H
