#include "TreeADT.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

tNode* createTree(tNode* left, void * item, tNode* right){
    tNode* newNode = (tNode*)malloc(sizeof(tNode));
    if(newNode == NULL)return 0;
    
    newNode->left = left;
    newNode->right = right;
    newNode->item = item;
    
    return newNode;
}

void* treeData(tNode* root){
    if(!root)
        return 0;
    
    return root->item;
}

void destroyTree(tNode* root){
    
    if(root == NULL)return;
    
    destroyTree(root->left);
    destroyTree(root->right);
    
    free(root);
}

bool hasChild(tNode* root){
    if(root->left != 0 || root->right != 0)return true;
    return false;
}






void toInfix(tNode* root, char* infix){
    if(root == NULL) return;
    
    char* token =(char*)malloc(sizeof(char)*2);
    strcpy(token, (char*)(root->item));
    
    if((*token) == '+' || (*token)-'0'=='-' ||(*token)=='*' || (*token)=='/')
    strcat(infix, "(");
    
    toInfix(root->left, infix);
    strcat(infix, token);
    toInfix(root->right, infix);
    
    if((*token) == '+' || (*token)-'0'=='-' ||(*token)=='*' || (*token)=='/')
    strcat(infix,")");
    
    free(token);
}

void toPostfix(tNode* root, char* input){
    if(root == NULL) return;
    
    char*token = (char*)malloc(sizeof(char)*2);
    strcpy(token, (char*)(root->item));
    
    toPostfix(root->left, input);
    toPostfix(root->right, input);
    
    strcat(input, token);
    free(token);
}
