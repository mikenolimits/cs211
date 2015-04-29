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


int cost(int r, int c){
   
    //base case
    //0 means its reached the end of a row b/c of how arrays work.
    //The initial call will never return this value,
    // this is used solely for the recursion process.
    if(c == 0){
        memo[r][c] = weight[r][c];
        //cout<<memo[r][c]<<endl;
        return memo[r][c];
    }
    //If memo contains a value we'll retrieve it instead of more recursive calls
    if(memo[r][c] != 0){
        return memo[r][c];
    }
    
    // recursive call to the length of all values left, up & down.
    int left = cost ( r, c - 1);
    int up   = cost((r-1+rows)%rows, c-1);
    int down = cost((r+1)%rows, c-1);
    
    // find the value of the shortest path through cell (i,j)
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
    
    //min = min + weight[r][c];
    
    //cout<<"The current min is : "<<(min + weight[r][c])<<endl;
    
    memo [r][c] = (min + weight[r][c]);
    
    return memo [r][c];
}

int hw17(){
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
    
      //start
        char direction   = directionsTaken[0][rowIndex];
        //int colindex   = cols;
        int math         = 0;
    
        for (int y = cols; y > 0; y--) {
            switch(direction){
                    case 'l':
                    math = y-1;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
                    case 'u':
                    math = (y - 1 + rows ) % rows;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
                    case 'd':
                    math = (y+1)%rows;
                    //cout<<math<<endl;
                    cout<<math<<endl;
                    break;
            }
            //cout<<"The math is"<<math<<endl;
            direction = directionsTaken[y][math];
        }
    
    cout<<endl;

    
    //…some code goes here
    
    cout<<"the shortest path is of length "<<min<<endl;
    //system("PAUSE");
    
    return 1;
    
}