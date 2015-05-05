//
//  assignment[17]_kami.cpp
//  HWS
//
//  Created by Michael Kantor on 4/20/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<vector>

using namespace std;
const int rows = 5;
const int cols = 6;

static int memo[rows][cols] = {0};

char directionsTaken[rows][cols];


const int weight[rows][cols]={
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}
};

//Step 1 : Make a base case. Ours is when the column is 0. At this point we "remember" previous values by sticking it into the const. The base case will only be reached by possible recursive calls later on.
//Step 2 : Check for previous answers by looking inside the Const Array
//Step 3 : recursively Call COST on each direction with the following rules ->
//  left = c -1
//  up   = (r-1 + rowcount) % rowcount
//  down = (r+1)%rows)
//The second arguement is always c-1
//Step 4 : calculate the min of each direction. The lowest will then be
//saved to the cost int for later checks.

int cost(int r, int c){
    
    if(c == 0){
        memo[r][c] = weight[r][c];
        return memo[r][c];
    }
    if(memo[r][c] != 0){
        return memo[r][c];
    }
    
    int left = cost ( r, c - 1);
    int up   = cost((r-1+rows)%rows, c-1);
    int down = cost((r+1)%rows, c-1);
    
    int min = left;
    directionsTaken[r][c]  = 'l';
   
    if(up < min){
        min = up;
        directionsTaken[r][c] = 'u';
    }
    if(down < min){
        min = down;
        directionsTaken[r][c] = 'd';
    }
    
    memo [r][c] = (min + weight[r][c]);
    
    return memo [r][c];
}

int offline(){
    int rowIndex = 0;
    int length[rows];
    
    // get the shortest path out of each cell on the right
    for( int i=0; i<rows; i++){
        length[i] = cost(i,cols-1);
    }
    // now find the smallest of them
    int min = 999999999;
    
    for ( int r = 0; r < rows; r++){
        if (length[r] < min ){
            min = length[r];
            cout<<"The current min is now : "<<min<<endl;
            rowIndex = r;
        }
    }
    //cout<<"The row index is"<<rowIndex<<endl;
    
    //How does one find the path :(
    cout<<"Printing the path:"<<endl;
    
        //int start = weight[0][0];
    
    char direction;
    int  math;
        //int colindex   = cols;
    
    
    for (int x = 0; x < rows; x++) {
        for (int p = 0; p < cols; p++) {
            cout<<directionsTaken[x][p]<<" ";
        }
        cout<<endl;
    }
    
    for (int y = 0; y < cols; y++) {
        direction =  directionsTaken[rowIndex][y];
        switch(direction){
                    case 'l':
                    math = rowIndex-1;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
                    case 'u':
                    math = (rowIndex - 1 + rows ) % rows;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
                    case 'd':
                    math = (rowIndex+1)%rows;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
        }
    }
    
    cout<<endl; 
    
    cout<<"the shortest path is of length "<<min<<endl;
    
    return 1;
}