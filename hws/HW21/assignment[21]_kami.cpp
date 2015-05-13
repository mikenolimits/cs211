//
//  assignment[21]_kami.cpp
//  HWS
//
//  Created by Michael Kantor on 5/7/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int* conFrac(int * a){
    
    if(*(a + 1) == -1){
        int *v = new int[2];
        
        v[0] = *a;
        v[1] = 1;
        
        return v;
    }
    
    int *v = conFrac(a + 1);
    
    int p = v[0];
    int q = v[1];
    
    v[1]  = p;
    v[0]  = *a * (p +q);
    
    return v;
}

double* conFrac(int * a,int n){
    
    double *container = new double[n];
    int    *numbers   = a;
    
    numbers = conFrac(a);
    
    for (int x = 0; x < n; x++) {
        cout<<numbers[x]<<endl;
        container[x] = numbers[x];
    }
    return container;
}


int nope1(){
    
    int numbers[] ={1,2,3,4,-1};
    
    double *result = conFrac(numbers,5);
    
    cout<<result[0]<<"/"<<result[1]<<endl;
    
    return 1;
    
    
}