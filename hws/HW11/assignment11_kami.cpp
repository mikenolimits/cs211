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

class GUIChess{
    public :
int results;

int  *queensBoard;
int  boardSize;
int  queensColumn;
bool needsToRetry;
bool isBacktracked;
int  currentSize;

void print(int q[]){
    
    int i,j,k,l;
    
    typedef string box[5][7];
    string blackBox = "\u25A0";
    
    box bb,wb, wq,bq, *board[8][8];
    
    //fill in bb=black box and wb=white box
    for(i=0; i<5; i++){
        for(j=0; j<7; j++){
            wb[i][j]=' ';
            wq[i][j]=' ';
            bb[i][j]=blackBox;
            bq[i][j]=blackBox;
        }
    }
    //white queen on a black background
    for (int i = 0; i < 3; i++) {
        for (int x = 0; x < 5; x++) {
            bq[i][x] = "\u25A0";
        }
    }

    for (int s = 0; s < 3; s++) {
        for (int z = 0; z < 5; z++) {
            bq[s][z] = "\u25A0";
        }
    }
    

    //fill board with pointers to bb and wb in alternate positions
    for(i=0; i<8; i++)
        for(j=0; j<8; j++){
            if((i+j)%2==0 && q[i]==j){
                   board[i][j]=&bq;
            }
            else if((i+j)%2==1 && q[i]==j){
                board[i][j]=&wq;
            }
            else{
                if((i+j)%2==0){
                    board[i][j]=&bb;
                }
            }
            if((i+j)%2==1){
                board[i][j]=&wb;
            }
        }
    //first print upper border
    cout<<"   ";
    for(i=0; i<7*8; i++){
        cout<<"_";
    }
    cout<<endl;
    
    //now print the board
    for(i=0; i<8; i++)
        for(k=0; k<5; k++)
        {
            cout<<"  "<<"|";
            for(j=0; j<8; j++)
                for(l=0; l<7; l++)
                    cout<<(*board[i][j])[k][l];
            cout<<"|"<<endl;//at end of line print bar line and then newline
        }
    
    //before exiting print lower border
    cout<<"   ";
    for(i=0; i<7*8; i++)
        cout<<"_";
    cout<<endl;
    
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            
            if ((i+j)%2==0 && q[i]==j){
                board[i][j]=&bb;
            }
            else if( ((i+j)%2 == 1) && (q[i]== j)){
                board[i][j]=&wb;
            }
            
        }
        
    }
}

void backtrack(){
    queensColumn--;
    
    if(queensColumn == -1)
    {
        if(boardSize < currentSize){
            exit(1);
        }
        cout << "There Are " << results << " Solutions to a "<<currentSize<<" sized Chess Board\n";
        cout <<"\n";
        print(queensBoard);
        
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
    queensColumn = 1;
    needsToRetry = true;
    
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
};
int lolol()
{
    int tries;
    cout<<"Please Enter A Number:";
    cin>>tries;
    
    GUIChess x = GUIChess();
    
    x.boardSize        = tries;
    x.queensBoard      = new int[tries];
    x.run();
    return 1;
    
}
