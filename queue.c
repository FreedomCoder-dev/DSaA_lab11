//
// Created by Freedom Coder on 05.10.2021.
//

#include <stdlib.h>
#include "queue.h"
#include <stdio.h>

struct QNode* newNode(int k)
{
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

struct Queue* F_MakeQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue* q, int k)
{
    struct QNode* temp = newNode(k);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return 0;

    struct QNode* temp = q->front;

    q->front = q->front->next;

    int key = temp->key;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return key;
}

void printQueue(struct Queue* q)
{
    struct QNode* temp = q->front;
    while(temp)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
}

int Qempty(struct Queue* q)
{
    return q->front == NULL;
}