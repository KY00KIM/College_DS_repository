#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

typedef struct nnode{
    void * item;
    struct nnode* left;
    struct nnode* right;
}tNode;

tNode* createTree(tNode* left, void * item, tNode* right);
void* treeData(tNode* root);
void destroyTree(tNode* root);
bool hasChild(tNode* root);

void toInfix(tNode* root, char* infix);
void toPostfix(tNode* root, char* infix);

