/*
 Write a program that inputs two integers n and k, where n>=k. Your program should calculate
 the number of different ways that k bishops could be placed on an nXn chessboard.
 Structure your program using the backtracking scheme that we have used for the eight queens
 problem. What needs to be modified is the “OK” function.
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int k, n; //number of bishops, size of the board

//q is an array of squares, where b is a bishop and q[b] is the square the bishop occupies
bool ok(int q[], int b, int n){
    //identify the row and column the bishop is in
    int row = q[b]/n, column = q[b]%n, current_row, current_column;
    
    for(int i=0; i<b; i++){ //for every bishop
        current_row = q[i]/n;
        current_column = q[i]%n;
        
        //diagonal test
        if(abs(row-current_row)==abs(column-current_column)) return false;
    }
    
    return true;
}

void backtrack(int &b, int count){
    b--;
    if(b==-1){
        cout << k << " bishops can be placed on an " << n << " by " << n << " chessboard in " << count << " different ways.";
        exit(1);
    }
}

int vectors(){
    while(true){
        
        //User input
        cout << "Enter n: ";
        cin >> n;
        cout << "Enter k: ";
        cin >> k;
        if(n<0) break;
        
        //Solution/backtracking algorithm
        int* q = new int[k]; //q[bishop] is a square on the n*n grid
        int count = 0, b = 0, t;
        q[b] = 0;
        
        while(true){
            //until we found all the possible solutions
            while(b<k){
                //for each bishop
                
                while(q[b]<n*n){
                    //for each square
                    if(ok(q,b,n)) break;
                    else q[b]++;
                }
                
                if(q[b] == n*n){
                    backtrack(b, count);
                    q[b]++;
                    continue;
                }else{
                    t = q[b];
                    b++;
                    q[b] = t;
                }
            }
            count++;
            backtrack(b, count);
            q[b]++;
        }
    }
    return 0;
}



