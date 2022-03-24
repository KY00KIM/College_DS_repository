#include "StackADT.h"
#include <stdio.h>
#include <stdlib.h>


Stack *CreateStack() {
    Stack *pStack = (Stack *) malloc(sizeof(Stack));
    if (pStack == NULL) return 0;

    pStack->topNode=NULL;
    pStack->count =0;
    
    return pStack;
}


void Push(Stack *pStack, void* item) {
    Node *NodePtr = (Node *) malloc(sizeof(Node));
    NodePtr->item = item;
    
    NodePtr->next = pStack->topNode;
    pStack->topNode = NodePtr;
    pStack->count++;
}

void* Pop(Stack *pStack) {
    if (pStack->topNode == NULL) return 0;
    
    Node* NodePtr = pStack->topNode;
    
    void* item = pStack->topNode->item;
    pStack->topNode = pStack->topNode->next;
    pStack->count--;
    
    free(NodePtr);
    return item;
}


//Destroys linked NODE
//
//
void DestroyStack(Stack *pStack) {
    Node *NodePtr1 = pStack->topNode;
    Node *NodePtr2 = NodePtr1;
    
    while (1) {
        if (NodePtr1 == NULL) break;
        NodePtr1 = NodePtr1->next;
        free(NodePtr2);
        NodePtr2 = NodePtr1;
    }
     
    free(pStack);
}


Stack* CatStack(Stack *pStack1, Stack *pStack2){

    Node* NodePtr=pStack2->topNode;
    while(NodePtr->next != NULL){
        NodePtr= NodePtr->next;
    }
    NodePtr->next=pStack1->topNode;
    pStack1->topNode= pStack2->topNode;

    pStack1->count += pStack2->count;
    pStack2->topNode = NULL;
    DestroyStack(pStack2);
    
    return pStack1;
}

void PrintStack(Stack* pStack){
    Node* NodePtr=NULL;
    NodePtr = pStack->topNode;
    printf("-------------\n");
    while(NodePtr != NULL){
        printf("%d\n", *(int*)(NodePtr->item)); //VOID_PTR DATA_TYPE
        NodePtr=NodePtr->next;
    }
    printf("-------------\n");
}

void* StackTop(Stack* pStack){
    if(pStack->topNode == NULL)
        return 0;
    
    return pStack->topNode->item;
}
