//
//  quicksort.h
//  OJ_Project
//
//  Created by fqyuan on 13/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>
void quicksort(int arr[], int start, int end);
void swap(int *a, int *b);
int partition(int arr[], int start, int end);
#endif /* quicksort_h */
