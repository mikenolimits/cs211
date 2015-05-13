//
//  stack.cpp
//  HWS
//
//  Created by Michael Kantor on 5/12/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

class stack{
private:
    int top; // top is the index into the array for the current top
    int * p; // p is a pointer into the heap where the stack is actually
    //located. Just like for SA class.
    int size; // size of the array allocated for the stack
public:
    stack(); // a stack to hold 100
    stack(int n); // a stack to hold n elements
    ~stack();
    bool empty();
    void push( int ); // don’t forget to test if stack is full
    int pop(); // return and remove the “top” element of the stack.

    // don’t forget to test if the stack is empty
};

stack::stack(){
    this->size = 100;
    this->top  = 0;
    this->p    = new int[this->size];
}

stack::stack(int n){
  
    this->size = n;
    this->top  = 0;
    
    this->p    = new int[this->size];
}

stack::~stack(){
    
    delete this->p;
}

bool stack::empty(){
    if(this->top == 0){
        return true;
    }else{
        return false;
    }
}


void stack::push(int x){
    this->p[this->top] = x;
    
    int * temp = new int[this->size];
    int z,i;
    
    for (z = this->top, i = 0; z >= 0; z--,i++) {
        temp[i] = this->p[z];
    }
    
    this->p = temp;

    this->top++;
    
}

int stack::pop(){
    
    this->top--;
    int x      = *this->p;
    
    //We only replace this->p once our new array has the elements in reverse order.
    int * temp = new int[this->size];
    
    //We start from the top because we want the newest elements put at index i, which starts from 0
    int z  = this->top;
    int i  = 0;
    
    for (z = this->top, i = 0; z >= 0; z--,i++) {
        temp[i] = this->p[z];
    }
    
    this->p = temp;
    
    
    return x;
}



int main(){
    stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i=0; i<3; i++)
        cout<<s.pop(); // should print 3,2 1
    return 0;
}
