//
//  assignment[19]_kami.cpp
//  HWS
//
//  Created by Michael Kantor on 4/28/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class KBishops{
    
public:
    
int  results;
int  *board;
// size of the board
int  size;
//# of knights on the board
int  knights;
    
//Current Index
int  bishop;
bool needsToRetry;
bool isBacktracked;

void backtrack(){
    bishop--;
    
    cout<<bishop<<endl;
    //isBacktracked = true;
    if(bishop == -1)
    {
        cout << "There Are " << results << " Solutions to a"<<knights<<" Knights "<<size <<" * "<<size<<" sized Bishop Board\n";
        cout <<"\n";
        needsToRetry = false;
    }
}

bool ok(){
    int row      = board[bishop] / size;
    int col      = board[bishop] % size;
    
    for(int i = 0; i < bishop; i++){
        
        int currentRow    = board[i] / size;
        int currentCol    = board[i] % size;
        
        if((abs(row-currentRow) == abs(col-currentCol))){
            return false;
        }
        
    }
    return true;
}
    
void run(){
    
    board = new int[knights];
    
    while(needsToRetry){
        while(bishop < knights){
            
            
            while(board[bishop] < size * size){
                //Because if one bishop gets in the way of the other due to their diagonal
                //The best thing we can do is take that bishop and move him right for the next loop.
                if(ok()){
                  break;
                }
                else {
                    board[bishop]++;
                }
            }
            //if the current bishop is already at the size of the grid, we need to GTFO!!!!
            if(board[bishop] == size * size)
            {
                backtrack();
                board[bishop]++;
                continue;
            }
            else{
                //We need to move the current bishop right.
                board[bishop] = board[bishop++];
            }
        }
        results++;
        backtrack();
        board[bishop]++;
    }
    delete board;
}
};
int main()
{
    
    KBishops x = KBishops();
    while(true){
        
        cout<<"Please Enter A Number:";
        cin>>x.size;
        cout<<"Please Enter a # of Bishops";
        cin>>x.knights;
        
        x.board            = new int[x.knights];
        x.bishop           = 0;
        x.needsToRetry     = true;
        x.results          = 0;
        x.board[0]         = 0;
        
        x.run();
    }
    return 1;
}
