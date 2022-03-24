
#include "heapADT.h"
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


HEAP* heapCreate(int size){
    HEAP* pHeap = (HEAP*)malloc(sizeof(HEAP));
    if(!pHeap) return 0;
    
    pHeap->heapAry = (int*)malloc(sizeof(int)*size);
    if(!(pHeap->heapAry)){
        free(pHeap);
        return 0;
    }
    pHeap->MaxSize = size;
    pHeap->size = 0;
    
    return pHeap;
}


int heapDelete(HEAP* pHeap){
    if(heapEmpty(pHeap))return 0;
    int output = pHeap->heapAry[0];
    
    pHeap->heapAry[0] = pHeap->heapAry[pHeap->size-1];
    pHeap->size--;
    _reheapDown(pHeap, 0);
    
    return output;
}

bool heapInsert(HEAP* pHeap, int data){
    if(heapFull(pHeap))return false;
    pHeap->heapAry[pHeap->size] = data;
    pHeap->size++;
    
    _reheapUp(pHeap, pHeap->size-1);
    
    return true;
}



int heapCount(HEAP* pHeap){
    return pHeap->size;
}

bool heapFull(HEAP* pHeap){
    return pHeap->size == pHeap->MaxSize ? true : false;
}

bool heapEmpty(HEAP* pHeap){
    return pHeap->size == 0 ? true : false;
}

bool heapDestroy(HEAP* pHeap){
    if(pHeap)return false;
    free(pHeap->heapAry);
    free(pHeap);
    return true;
}

void _reheapDown(HEAP* pHeap, int idx){
    if(idx >= pHeap->size-1) return;
    
    //larger child
    int child = idx*2 +1;
    if(pHeap->size-1 >= idx*2+2)
    if(pHeap->heapAry[child] < pHeap->heapAry[child+1]){
        child++;
    }
    
    if(pHeap->heapAry[child] > pHeap->heapAry[idx]){
        int tmp = pHeap->heapAry[child];
        pHeap->heapAry[child] = pHeap->heapAry[idx];
        pHeap->heapAry[idx] = tmp;
        _reheapDown(pHeap, child);
    }
    
    return;
}


void _reheapUp(HEAP* pHeap, int idx){
    if(idx <= 0) return;
    
    int parent = (idx-1)/2;
    if(pHeap->heapAry[parent] < pHeap->heapAry[idx] ){
        int tmp = pHeap->heapAry[idx];
        pHeap->heapAry[idx] = pHeap->heapAry[parent];
        pHeap->heapAry[parent] = tmp;
        _reheapUp(pHeap, parent);
    }
    
    return;
}
