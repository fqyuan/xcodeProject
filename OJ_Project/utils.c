//
//  utils.c
//  OJ_Project
//
//  Created by fqyuan on 13/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
void generateArr(int arr[], int len){
    srand((unsigned int)time(NULL));
    for(int i=0; i<len; i++){
        arr[i] = rand()%100;
    }
}
void printArr(int arr[], int len){
    for(int i=0; i<len; i++)
        printf("%d ",arr[i]);
    printf("\n");
}
