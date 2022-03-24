#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearchTreeADT.h"

BST_TREE* bstCreate()
{
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if (tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}

	return tree;
}

void bstDestroy(BST_TREE* tree)
{
	if (tree)
	{
		_bstDestroy(tree->root);
		tree->count = 0;

		free(tree);
	}
}

void _bstDestroy(TREE_NODE* root)
{
	if (root)
	{
		_bstDestroy(root->left);
		_bstDestroy(root->right);
		free(root);
	}
}


bool bstInsert(BST_TREE* tree, int data)
{
    TREE_NODE* new = (TREE_NODE*)malloc(sizeof(TREE_NODE));
    if(new == NULL) return false;
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    
    tree->count++;
    
    TREE_NODE* cur = tree->root;
    if(cur == NULL){
        tree->root = new;
        return true;
    }else
        while(true){
            if(cur->data > data){
                if(cur->left == NULL){
                    cur->left = new;
                    return true;
                }
                cur = cur->left;
            }
            else{
                if(cur->right == NULL){
                    cur->right = new;
                    return true;
                }
                else cur = cur->right;
            }
        }
}

bool bstDelete(BST_TREE* tree, int key)
{
    TREE_NODE* cur = bstSearch(tree, key);
    if(cur == NULL)
        return false;
    else{
        
        //find pre
        bool dir = true; //false = left, right =true
        TREE_NODE* pre = tree->root;
        
        if(cur != tree->root)
            while(true){
            if(pre->left == cur){
                dir = false;
                break;
            }else if( pre->right == cur){
                break;
            }else if(pre->data > key)
                pre = pre->left;
            else
                pre = pre->right;
        }
      
      
        if(cur->left == NULL){
            //KEY HAS NO or ONLY RIGHT CHILD
            if(dir)
                pre->right = cur -> right;
            else
                pre->left = cur->right;
            if(cur == tree->root)
                tree->root = cur->right;
            free(cur);
        }else if(cur->right == NULL){
            //KEY HAS LEFT CHILD ONLY
            if(dir)
                pre->right = cur->left;
            else
                pre->left = cur->left;
            if(cur == tree->root)
                tree->root = cur->left;
            free(cur);
        }else{
            //KEY HAS BOTH CHILD
            
            //find rep
            TREE_NODE* rep = cur->right; //replace smallest among larger elements
            while(rep->left != NULL){
                rep = rep->left;
            }
            int tmp = rep->data;
            
            //rep delete
            TREE_NODE* preRep = cur;
            int once = 1;
            bool dirRep = true; //true = right
            while(true){
                if(preRep->right == rep)
                    break;
                else if(preRep->left == rep){
                    dirRep = false;
                    break;
                }else{
                    if(once){
                        preRep = preRep->right;
                        once = 0;
                    }else
                        preRep = preRep->right;
                }
            }
            if(dirRep)
                preRep->right = rep->right;
            else
                preRep->left = rep->right;
            free(rep);
            
            cur->data = tmp;
        }
        
        tree->count--;
        return true;
    }
}

TREE_NODE* bstSearch(BST_TREE* tree, int key)
{
    TREE_NODE* cur = tree->root;
    while(cur != NULL){
        if(cur->data > key)cur = cur->left;
        else if(cur->data < key) cur = cur->right;
        else break;
    }
    if(cur == NULL) return NULL;
    return (cur->data == key)? cur : NULL;
}

bool bstEmpty(BST_TREE* tree)
{
    if(tree->count == 0)return true;
    else return false;
}

int bstCount(BST_TREE* tree)
{
    return tree->count;
}
