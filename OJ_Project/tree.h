//
//  tree.h
//  OJ_Project
//
//  Created by fqyuan on 26/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//

#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct treenode{
    int key;
    struct treenode * left;
    struct treenode * right;
} treenode;

//A utility function to create a new BST node
treenode *createNode(int item){
    treenode * temp = (treenode*)malloc(sizeof(struct treenode));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
//A utility function to do inorder traversal of BST
void inorder(treenode* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

//A utility function to insert a new node with given key in BST
treenode* insert(treenode* root, int key){
    //If the tree is empty
    if(root == NULL)
        return createNode(key);
    //Otherwise recurse down the tree
    if(key <root->key)
        root->left = insert(root->left,key);
    else if(key>root->key)
        root->right = insert(root->right, key);
    return root;
}
//A utility fuction to test if data is in the tree
int  search(treenode* root, int key){
    if(root == NULL)
        return 0;
    else if(key == root->key)
        return 1;
    else if(key <root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* Given a non-empty binary search tree, return the node with minimum
 key value found in that tree. Note that the entire tree does not
 need to be searched. */
treenode * minValueNode(treenode* node)
{
    treenode* current = node;
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    
    return current;
}

/* Given a binary search tree and a key, this function deletes the key
 and returns the new root */
treenode* deleteNode(treenode* root, int key)
{
    // base case
    if (root == NULL) return root;
    
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            treenode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            treenode *temp = root->left;
            free(root);
            return temp;
        }
        
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        treenode* temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->key = temp->key;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

//Find the node of given data
treenode* find(treenode* root, int data){
    treenode * temp = NULL;
    
    return temp;
}
int maxValue(treenode* root){
    if(root==NULL)
        return -1;
    int max = 0;
    while(root){
        max = root->key;
        root = root->right;
    }
    return max;
}

int isBSTUtil(treenode* root, int min, int max){
    //An empty tree is BST
    if(root == NULL)
        return 1;
    //false if this node violates the min/max constraint
    if(root->key<min || root->key>max){
        return 0;
    }
    //Otherwise check the substrees recursively, tightening the min or max constraint
    return isBSTUtil(root->left, min, root->key-1)&&isBSTUtil(root->right, root->key+1, max);
}
int isValidBST(treenode* a) {
    return isBSTUtil(a, INT_MIN, INT_MAX);
}

#endif /* tree_h */
