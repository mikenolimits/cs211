#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;

class StableMarriage{
    
    public :
    
    int  board[3];
    int  col;
    int  results;
    bool needsToRetry;
    bool isBacktracked;
    
    bool ok()
    {
        
        static int mp[3][3] = {
            0,2,1,0,2,1,1,2,0
        };
        static int wp[3][3] ={
          2,1,0,0,1,2,2,0,1
        };
        
    
        int x = 0;
        int y = 0;
        
        while(x < col){
            //We need to make sure that the current column doesn't match up with the interation.
            if (board[col] == board[x]) {
                return false;
            }
            x++;
        }
        
        while(y < col){
            if( ( mp[col][board[y]] < mp[col][board[col]] ) && ( wp[board[y]][col] < wp[board[y]][y]) )
                return false;
            if( ( wp[board[col]][y] < wp[board[col]][col] )&& ( mp[y][board[col]] < mp[y][board[y]]) )
                return false;
            
            y++;
        }
        return true;
    }
    
    void reboot()
    {
        col--;
        if(col == -1){
            exit(1);
        }
    }
    
    void getSolution()
    {
        results++;
        cout << "There Are " << results << " Solutions\n";
        cout << "The current combination is : \n";
        
        for (int i = 0; i < 3; i++){
            cout<<" "<<i<<" "<<board[i]<<endl;
        }
        cout <<"\n";
    }
    void init(){
        isBacktracked = false;
        board[0]      = 0;
        col           = 0;
    }
    
    
    void run()
    {
        while(true)
        {
            while( col < 3)
            {
                ColumnIncrementor();
            }
            getSolution();
            reboot();
            isBacktracked = true;
        }
    }
    
    
    void ColumnIncrementor(){
        if(!isBacktracked) {
            board[col] = -1;
        }
        isBacktracked = false;
        
        while(board[col] < 3)
        {
            board[col]++;
            if(board[col] == 3)
            {
                reboot();
                continue;
            }
            if(ok()){
                break;
            }
        }
        col++;
    }
    
};


void hw9(){
    StableMarriage x = StableMarriage();
    x.init();
    x.run();
}