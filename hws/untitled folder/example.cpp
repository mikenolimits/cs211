#include <iostream>
#include<cstdlib>
#include <cmath>
using namespace std;

/*
   I kinda jumped the gun here and made this OOP and made the chess board dynamic.
 */

class ChessBoard {
public:
    int results;
    int position;
    
    int  *queensBoard;
    int  boardSize;
    int  queensColumn;
    int  solutions;
    bool needsToRetry;
    bool isBacktracked;
    
    
    void init(int size){
        queensColumn   = 1;
        solutions      = 0;
        needsToRetry   = true;
        queensBoard    = new int[size];
        boardSize      = size;
    }
    
    void run(){
        
        while(needsToRetry){
            while(queensColumn < boardSize){
                ColumnIncrementor();
            }
            outputSolution();
            reboot();
            isBacktracked = true;
        }
    }
    
    void ColumnIncrementor(){
        
        if(!isBacktracked){
            queensBoard[queensColumn] = -1;
        }
        
        isBacktracked                 = false;
        
        while(queensBoard[queensColumn] < boardSize){
            queensBoard[queensColumn]++;
            
            while(queensBoard[queensColumn] == boardSize)
            {
                reboot();
                queensBoard[queensColumn]++;
            }
            
            if(ok()){
                break;
            }
            
        }
        queensColumn++;
    }
    
    
    bool ok(){
         for(int i = 0; i < queensColumn; i++){
           if(!positionIsValid(i))
          {
             return false;
          }
        }
        return true;
  }
    
    bool positionIsValid(int row) {
        //Consider the possibility that a current position might be negative.
       int position = queensBoard[queensColumn] - queensBoard[row];
        
        if (position < 0) {
            position = abs(position);
        }
        if (position == queensColumn - row) {
            return false;
        }else if(queensBoard[row] == queensBoard[queensColumn]){
            return false;
        }
        return true;
    }

    void outputSolution(){
       results++;
       cout << "There Are " << results << " Solutions\n";
       cout << "The current combination is : ";
       for (int i = 0; i < boardSize; i++){
          cout <<queensBoard[i];
        }
       cout <<"\n";
    }
    
    void reboot(){
        queensColumn--;
        
        if(queensColumn == -1)
        {
            exit(1);
        };
    }
};

int main()
{
    ChessBoard Chess = ChessBoard();
    Chess.init(8);
    Chess.run();
}