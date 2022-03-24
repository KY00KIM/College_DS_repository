#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    void* item;
    struct node *next;
} Node;

typedef struct stack {
    int count;
    Node *topNode;
} Stack;

Stack *CreateStack(void);

void Push(Stack *pStack, void* item);

void* Pop(Stack *pStack);

void DestroyStack(Stack *pStack);

Stack* CatStack(Stack *pStack1, Stack *pStack2);

void* StackTop(Stack* pStack);

void PrintStack(Stack* pStack);
