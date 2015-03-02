//
//  assignment[7]_kami.cpp
//  HWS
//
//  Created by Michael Kantor on 2/24/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

class DumbChessBoard{
public:
    
    int results;
    
    int  queensBoard[8];
    int  queensColumn;
    int  queensRow;
    int  solutions;
    bool needsToRetry;
    bool isBacktracked;
    
    void init(){
        queensColumn   = 0;
        queensRow      = 0;
        solutions      = 0;
        needsToRetry   = true;
    }
    
    bool ok(){
        for(int col = 7; col > 0; col--){
            
            int row = 0;
            
            row = queensBoard[col];
            
            for(int i = 1; i <= col; i++){
                if(queensBoard[col - i] == row){
                    return false;
                }
                else if (queensBoard[col - i] == row - i || queensBoard[col - i] == row + i){
                    return false;
                }

            }
            
        }
        return true;
    }
  
    void run(){
        for(int r1 = 0; r1 < 8; r1++)
            for(int r2 = 0; r2 < 8; r2++)
              for(int r3 = 0; r3 < 8; r3++)
                  for(int r4 = 0; r4 < 8; r4++)
                      for(int r5 = 0; r5 < 8; r5++)
                          for(int r6 = 0; r6 < 8; r6++)
                              for(int r7 = 0; r7 < 8; r7++)
                                  for(int r8 = 0; r8 < 8; r8++){
        
                                      queensBoard[0] = r1;
                                      queensBoard[1] = r2;
                                      queensBoard[2] = r3;
                                      queensBoard[3] = r4;
                                      queensBoard[4] = r5;
                                      queensBoard[5] = r6;
                                      queensBoard[6] = r7;
                                      queensBoard[7] = r8;
                                      
                                      if(ok()){
                                          outputSolution();
                                      }
                                      
                                      for (int x = 0; x < 8; x++) {
                                          queensBoard[x] = -1;
                                      }
                                   
        }
    }
    
    
    void outputSolution(){
        results++;
        cout << "There Are " << results << " Solutions\n";
        cout << "The current combination is : ";
        for (int i = 0; i < 8; i++){
            cout <<queensBoard[i];
        }
        cout <<"\n";
    }
};

int hw7(){
    
    DumbChessBoard DumbChess = DumbChessBoard();
    DumbChess.init();
    DumbChess.run();
    
    return 1;
}