//
//  assignment[10]_kami.cpp
//  HWS
//
//  Created by Michael Kantor on 3/10/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

    int results;
    
    int  *queensBoard;
    int  boardSize;
    int  queensColumn = 1;
    bool needsToRetry = true;
    bool isBacktracked;
    int  currentSize  = 1;


void backtrack(){
    queensColumn--;
    
    if(queensColumn == -1)
    {
        if(boardSize < currentSize){
            exit(1);
        }
        cout << "There Are " << results << " Solutions to a "<<currentSize<<" sized Chess Board\n";
        cout <<"\n";
        
        needsToRetry = true;
        queensColumn = 1;
        results      = 0;
        currentSize++;
        queensBoard  = new int[currentSize];
    }
}

bool ok(){
    for(int i = 0; i < queensColumn; i++){
        int position = queensBoard[queensColumn] - queensBoard[i];
        
        if (position < 0) {
            position = abs(position);
        }
        if (position == queensColumn - i) {
            return false;
        }else if(queensBoard[i] == queensBoard[queensColumn]){
            return false;
        }
    }
    return true;
}
    void run(){
        
        while(needsToRetry){
            while(queensColumn < currentSize){
                
                if(!isBacktracked){
                    queensBoard[queensColumn] = -1;
                }
                
                isBacktracked                 = false;
                
                while(queensBoard[queensColumn] < currentSize){
                    queensBoard[queensColumn]++;
                    
                    while(queensBoard[queensColumn] == currentSize)
                    {
                        backtrack();
                        queensBoard[queensColumn]++;
                    }
                    
                    if(ok()){
                        break;
                    }
                    
                }
                queensColumn++;

            }
            results++;
            backtrack();
            isBacktracked = true;
        }
    }

void hw10()
{
    int tries;
    cout<<"Please Enter A Number:";
    cin>>tries;
    
    boardSize        = tries;
    queensBoard      = new int[tries];
    run();
}
