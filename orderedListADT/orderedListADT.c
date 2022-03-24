#include "orderedListADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool retrieve(LIST* pList, void* pKey, void** pDataOut)
{
    NODE* pPre;
    NODE* pCur;

    if (_search(pList, &pPre, &pCur, pKey))
    {
        *pDataOut = pCur->pData;
        return true;
    } else
    {
        *pDataOut = NULL;
        return false;
    }
}

static bool _search(LIST* pList, NODE** pPre, NODE** pLoc, void* pKey)
{
#define COMPARE (((*pList->compare)(pKey, (*pLoc)->pData)))
#define COMPARE_LAST ((*pList->compare) (pKey, pList->rear->pData))

    int result;
    *pPre = NULL;
    *pLoc = pList->head;
    if (pList->size == 0)
        return false;

    if (COMPARE_LAST > 0) //COMPARE_LAST if 1 pKey is LARGEST
    {
        *pPre = pList->rear;
        *pLoc = NULL;
        return false;
    }

    while ((result = COMPARE) > 0) //BREAKS at; Loc is Larger or EQUALS
    {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;
    }

    if (result == 0)
        return true; //Loc EQUAL
    else
        return false; // Loc LARGER Pre SMALLER
}


LIST* createList(int(*compare)(void* pArg1, void* pArg2)){
    LIST * ptr = (LIST*) malloc(sizeof(LIST));
    if(ptr == NULL) return NULL;
    
    ptr->size=0;
    ptr->pos = NULL;
    ptr->head = NULL;
    ptr->rear=NULL;
    ptr->compare = compare;
    return ptr;
}


LIST* destoryList(LIST* pList){
    NODE* pNODE = pList->head, *pNext = pList->head;
    while(pNODE != NULL){
        pNext = pNODE->next;
        free(pNODE->pData);
        free(pNODE);
        pNODE = pNext;
    }
    free(pList);
    pList =NULL;
    return pList;
}
    

bool insert(LIST* pList, void* pDataIn){
    NODE* pPre, *pLoc;
    if(!_search(pList, &pPre, &pLoc, pDataIn)){
        return _insert(pList, pPre, pDataIn);
    }else
        return false;
}


bool Remove(LIST* pList, void* pKey){
    NODE* pPre = NULL, *pLoc = pList->head;
    
    if(_search(pList, &pPre, &pLoc, pKey)){
        _delete(pList, pPre, pLoc);
        return true;
    }else{
        return false;
    }
}


int size(LIST* pList){
    return pList->size;
}


bool isEmpty(LIST* pList){
    return pList->size == 0 ? true:false;
}


bool iterate(LIST* pList, void** pDataOut){
    if(pList->pos == NULL){             //If NULL -> head
        pList->pos = pList->head;
    }else{                              //else next
        pList->pos = pList->pos->next;
    }
    
    if(pList->pos == NULL){     // 1.head==null  2.end of list
        *pDataOut = NULL;
        return false;
    }else{                      // 1.head!=null  2.middle of list
        *pDataOut = pList->pos->pData;
        return true;
    }
}



void initIterator(LIST* pList){
    pList->pos = NULL;
}


void printList(LIST* pList, void(*print)(void* pArg)){
    NODE* ptr = pList->head;
    while(ptr != NULL){
        print(ptr->pData);
        ptr = ptr->next;
    }
    printf("====================\n");
}






static bool _insert(LIST* pList, NODE* pPre, void* pDataIn){
    NODE* ptr = (NODE*)malloc(sizeof(NODE));
    if(ptr == NULL)return false;
    ptr->pData = pDataIn;
    
    if(pPre == NULL){
        ptr->next = pList->head;
        pList->head = ptr;
        if(pList->size == 0) pList->rear = ptr;
    }else {
        if(pPre->next == NULL)pList->rear = ptr;
        ptr->next = pPre->next;
        pPre->next = ptr;
    }
    pList->size++;
    return true;
}

static void _delete(LIST* pList, NODE* pPre, NODE* pCur){
    
    if(pPre == NULL){
        pList->head = pCur->next;
        if(pList->size == 1)
            pList->rear = NULL;
    }else{
        if(pCur->next == NULL)
            pList->rear = pPre;
        pPre->next = pCur->next;
    }
    
    free(pCur->pData);
    free(pCur);
    pList->size--;
    pCur = NULL;
}

