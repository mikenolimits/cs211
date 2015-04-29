//
//  Midterm.cpp
//  HWS
//
//  Created by Michael Kantor on 3/23/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int exp(int x, int n){
    if ( n == 0){
        return x;
    }
    return x * exp(x,n-1);
}

int * return_an_array(int n){
    int size = 0;
    int temp = n;
    while((temp/10) != 0){
        temp = temp/10;
        size++;
    }
    int *a = new int[size];
    int i = 0;
    for (int z = 0; z <= size; z++) {
        a[i] = n%10;
        n = n/10;
        //cout<<a[i];
    }
    return a;
}

void print(int n){
    if(n/10 == 0)
    {
        cout<<n%10;
        return;
    }
    print(n/10);
    cout<<n%10;
}
void print(char* s){
    if(*s == '\0'){
        return;
    }
    cout<<*s;
    print(s+1);
}

void rev_print(char* s){
    if(*s == '\0'){
        return;
    }
    rev_print(s+1);
    cout<<*s;
}
void rev_print(int n){
    if(n/10 == 0)
    {
        cout<<n%10;
        return;
    }
    cout<<n%10;
    rev_print(n/10);
    
}
typedef bool test(int);
int * return_matches(int a[], int & size, test t){
    
    int *p = new int[size];
    int new_size;
    for (int i = 0; i <= size; i++) {
        if(t(a[i])){
            p[new_size] = a[i];
            new_size++;
        }
    }
    size = new_size;
    return p;
}
bool leapyear(int y){
    
    
    if(y == 4) return true;
    
    if(y % 400 == 0)  return true;
    return false;
}

bool is_even(int n){
    if(n%2 == 0){
        return true;
    }else{
        return false;
    }
}

int lololol()
{
    /*
    int size    = 6;
    int a[]     = {1,2,3,4,5,6};
    int* output = return_matches(a, size, is_even);
    
    for (int x = 0; x <= size; x++) {
        cout<<output[x]<<endl;
    }
    */
    
    int *y = return_an_array(1000);
    for (int x = 0; x<4; x++) {
        cout<<y[x]<<endl;
    }
    return 1;

}