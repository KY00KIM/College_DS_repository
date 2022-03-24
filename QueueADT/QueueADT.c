#include "QueueADT.h"
#include <stdio.h>
#include<stdlib.h>

Queue* CreateQueue(void){
    Queue* queue= (Queue*)malloc(sizeof(Queue));
    if(queue == NULL) return 0;
    queue->count =0;
    queue->topNode = NULL;
    return queue;
}


void enqueue (Queue* queue, void* item){
    Node* nodePtr = queue->topNode;
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    
    if(queue->count == 0){
        queue->topNode = newNode;
        queue->count++;
    }else{
        while(nodePtr->next != NULL){
            nodePtr = nodePtr->next;
        }
        queue->count++;
        nodePtr-> next = newNode;
    }
}

void* dequeue(Queue* queue){
    Node* nodePtr = queue->topNode;
    
    void* item = queue->topNode->item;
    queue-> topNode = queue->topNode->next;
    
    free(nodePtr);
    queue->count--;
    return item;
}

void* queueFront(Queue* queue){
    return queue->topNode->item;
}

int queueCount(Queue* queue){
    /*
    int cnt=0;
    Node* nodePtr= queue->topNode;
    while(nodePtr != NULL){
        cnt++;
        nodePtr = nodePtr->next;
    }
    */
    return queue->count;
}

void destroyQueue(Queue* queue){
    Node* nodePtr1 = queue->topNode;
    Node* nodePtr2 = queue->topNode;
    
    while(nodePtr1 != NULL){
        nodePtr1 = nodePtr1->next;
        free(nodePtr2);
        nodePtr2 = nodePtr1;
    }
    free(queue);
}
