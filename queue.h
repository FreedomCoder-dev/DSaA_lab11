//
// Created by Freedom Coder on 05.10.2021.
//

#ifndef LAB4_STACK_H
#define LAB4_STACK_H

struct Queue {
    struct QNode *front, *rear;
};

struct QNode
{
    int key;
    struct QNode *next;
};

struct Queue* F_MakeQueue();
void enQueue(struct Queue* q, int k);
int deQueue(struct Queue* q);
int Qempty(struct Queue* q);
void printQueue(struct Queue* q);

#endif //LAB4_STACK_H
