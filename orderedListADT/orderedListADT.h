#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    void* pData;
    struct node* next;
} NODE;

typedef struct
{
    int size;
    NODE* pos;
    NODE* head;
    NODE* rear;
    int(*compare) (void* pArg1, void* pArg2);
} LIST;

LIST* createList(int(*compare)(void* pArg1, void* pArg2));

LIST* destoryList(LIST* pList);

bool insert(LIST* pList, void* pDataIn);

bool Remove(LIST* pList, void* pKey);

bool retrieve(LIST* pList, void* pKey, void** pDataOut);

int size(LIST* pList);

bool isEmpty(LIST* pList);

bool iterate(LIST* pList, void** pDataOut);

void initIterator(LIST* pList);

void printList(LIST* pList, void(*print)(void* pArg));

static bool _insert(LIST* pList, NODE* pPre, void* pDataIn);

static void _delete(LIST* pList, NODE* pPre, NODE* pCur);

static bool _search(LIST* pList, NODE** pPre, NODE** pCur, void* pKey);
