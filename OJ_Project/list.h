//
//  list.h
//  OJ_Project
//
//  Created by fqyuan on 14/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node{
    int data;
    int key;
    struct list_node * next;
}list_node;

//Display the list
void printList(list_node* head){
    list_node * list = head;
    printf("\n[ ");
    //start from the beginning
    while(list != NULL){
        printf("(%d,%d) ",list->key, list->data);
        list = list->next;
    }
}
//insert link at the first location
void insertFirst(list_node **head, int key, int data){
    //create a link
    list_node * link = (list_node *)malloc(sizeof(struct list_node));
    if(!link)
        return;
    //Set the content of the node
    link->data = data;
    link->key = key;
    link->next = *head;
    //point first to new first node.
    *head = link;
}

//delete first item
list_node *deleteFirst(list_node *head){
    //Save reference to first link
    list_node * tmpNode = head;
    //Mark next to first link as first
    head = head->next;
    //return the deleted link
    return tmpNode;
}

//is list empty?
int isEmpty(list_node* head){
    return head==NULL;
}

//the length of the list.
int lengthList(list_node* head){
    int len = 0;
    for(list_node* current = head; current!=NULL; current=current->next)
        len++;
    return len;
}
//Find a link with given key
list_node * find(list_node* head, int key){
    //Start from the first link
    list_node * tempNode = head;
    //If list is empty
    if(head==NULL)
        return NULL;
    //navigate through list
    while(tempNode->key !=key){
        //If it is last node
        if(tempNode->next ==NULL)
            return NULL;
        //Else go to next link
        else
            tempNode = tempNode->next;
    }
    //If data is found, return the current link
    return tempNode;
}
//Delete a link with given key
list_node* delete(list_node *head,int key){
    list_node* previous = NULL;
    list_node* current = head;
    if(head == NULL)
        return NULL;
    //Navigate the list
    while(current->key != key){
        if(current->next == NULL)
            return NULL;
        else{
            previous = current;
            current = current->next;
        }
    }
    if(current == head)
        head = head->next;
    else
        previous->next = current->next;
    return current;
}

void sort(list_node * head){
    int i, j, k, tempKey, tempData;
    list_node * current;
    list_node * next;
    int size = lengthList();
    for(i=0; i<size-1; i++){
        current = head;
        next = head->next;
        for(j=1; j<size; j++){
            if(current->data > next->data){
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;
                
                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}
//I have no idea why will this work.
void reverse(list_node ** head){
    list_node * prev = NULL;
    list_node * current = *head;
    list_node * next= NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

//Reorder the list
list_node * listnodeNew(int data, int key){
    list_node * node = (list_node *)malloc(sizeof(list_node));
    node->data = data;
    node->key = key;
    node->next = NULL;
    return node;
}
void reorderList(list_node ** head){
    
}

#endif /* list_h */
