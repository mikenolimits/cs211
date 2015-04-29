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
int  n;
int  bishop;
int  knights;
bool needsToRetry;
bool isBacktracked;

void backtrack(){
    bishop--;
    
    if(bishop == -1)
    {
        cout << "There Are " << results << " Solutions to a"<<knights<<" Knights "<<n <<" * "<<n<<" sized Bishop Board\n";
        cout <<"\n";
        needsToRetry = false;
    }
}

bool ok(){
    int row      = board[bishop] / n;
    int col      = board[bishop] % n;
    
    for(int i = 0; i < bishop; i++){
        
        int currentCol = board[i] / n;
        int currentRow = board[i] % n;
        
        //diagonal test
        if(abs(row-currentRow) == abs(col-currentCol)){
            return false;
        }
        int current      = board[bishop];
        int currentBish  = board[i];
        if(current < currentBish){
            return false;
        }
    }
    return true;
}
    
void run(){

    
    while(needsToRetry){
        
        while(bishop < knights){
            
            while(board[bishop] < n * n){
                //Because if one bishop gets in the way of the other due to their diagonal
                //The best thing we can do is take that bishop and move him right for the next loop.
                if(ok())break;
                else board[bishop]++;
            }
            
            if(board[bishop] == n * n)
            {
                backtrack();
                board[bishop]++;
                continue;
            }
            else{
                int t = board[bishop];
                bishop++;
                board[bishop] = t;
            }
        }
        results++;
        backtrack();
        board[bishop]++;
    }
    }
};
int main()
{
    
    KBishops x = KBishops();
    while(true){
        
        cout<<"Please Enter A Number:";
        cin>>x.n;
        cout<<"Please Enter a # of Bishops";
        cin>>x.knights;
        
        x.board                = new int[x.knights];
        x.bishop               = 0;
        x.needsToRetry         = true;
        x.results              = 0;
        x.board[x.bishop]      = 0;
        
        x.run();
        return 1;
    }
}
