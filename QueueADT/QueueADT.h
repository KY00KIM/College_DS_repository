#pragma once
#include <stdio.h>

typedef struct node{
    void* item;
    struct node* next;
}Node;

typedef struct queue{
    Node* topNode;
    int count;
}Queue;

Queue* CreateQueue(void);

void enqueue (Queue* queue, void* item);

void* dequeue(Queue* queue);

void* queueFront(Queue* queue);

int queueCount(Queue* queue);

void destroyQueue(Queue* queue);

