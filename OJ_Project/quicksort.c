//
//  quicksort.c
//  OJ_Project
//
//  Created by fqyuan on 13/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//

#include "quicksort.h"
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int start, int end){
    int x = arr[end];
    int i = start-1;
    int j;
    for(j=start; j<end; j++){
        if(arr[j]<x){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}
void quicksort(int arr[], int start, int end){
    int pivot;
    if(start<end){
        pivot = partition(arr, start, end);
        quicksort(arr, start, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}
