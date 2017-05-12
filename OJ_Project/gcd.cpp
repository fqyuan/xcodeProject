//
//  gcd.cpp
//  OJ_Project
//
//  Created by fqyuan on 27/04/2017.
//  Copyright © 2017 com.fqy.sort. All rights reserved.
//

#include "gcd.hpp"
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
//Assume that m is greater than n
int gcd(int m, int n){
    if(m % n==0)
        return n;
    if(m<n)
        swap(m,n);
    while(n>0){
        n = m%n;
        swap(m,n);
    }
    return n;
}
