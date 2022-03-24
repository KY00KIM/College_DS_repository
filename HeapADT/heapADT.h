#pragma once
#include <stdio.h>
#include<stdbool.h>

typedef struct _heap{
       int * heapAry;
       int size;
       int MaxSize;
   }HEAP;
   
HEAP* heapCreate(int size);
bool heapInsert(HEAP* pHeap, int data);
int heapDelete(HEAP* pHeap);
int heapCount(HEAP* pHeap);
bool heapFull(HEAP* pHeap);
bool heapEmpty(HEAP* pHeap);
bool heapDestroy(HEAP* pHeap);

void _reheapDown(HEAP* pHeap, int idx);
void _reheapUp(HEAP* pHeap, int idx);



