#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;

class CrossProblem{
    
    public :
    
    
    int  board[8];
    int  col;
    int  results;
    bool needsToRetry;
    bool isBacktracked;
    
bool ok(int board[], int col)
{
    
    
    //the exit conditions are
    //1. if the current col is equal to the current iteration of the loop
    //2. if the current column in the helper is -1
    //3. if the current position in the board is 1
    
    
    static int helpTable[8][5] =
    {
        {-1},
        {0,-1},
        {1,1, -1},
        {0, 1, 2, -1},
        {2,3, -1},
        {2, 3, 4, -1},
        {0, 2, 4, -1},
        {1, 3, 5, -1}
    };
    

    for (int boardRow = 0; boardRow < col; boardRow++) {
        //We need to make sure that the current column doesn't match up with the interation.
           if (board[col] == board[boardRow]) {
              return false;
           }
    }
    for (int helperRow = 0; helpTable[col][helperRow] != 1; helperRow++) {
    
        int position = board[col] - board[helpTable[col][helperRow] ];
        
        if(abs(position) == (col - helperRow)){
            return false;
        }
    }
    return true;
}

void backtrack()
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
    
    
    int temp[8];
    int top[2]    = {1,2};
    int middle[4] = {0,3,4,7};
    int bottom[2] = {5,6};

    
    for (int x = 0; x < 8; x++) {
        temp[x] = board[x] + 1;
    }
    cout<<" ";
    for (int y = 0; y < 2; y++) {
        cout<<" "<<temp[top[y]];
    }
    cout<<endl;
    for(int z = 0; z < 4; z++){
        cout<<temp[middle[z]]<<" ";
    }
    cout<<endl;

    cout<<" ";
    for(int i = 0; i < 2; i++){
        cout<<" "<<temp[bottom[i]];
    }

    cout<<endl;
}
    void init(){
        isBacktracked = false;
        board[0]      = 0;
    }
    
    
    void run()
    {
        while(true)
        {
            while( col < 8)
            {
                ColumnIncrementor();
            }
            getSolution();
            backtrack();
            isBacktracked = true;
        }
    }

    
    void ColumnIncrementor(){
        if(!isBacktracked) {
            board[col] = -1;
        }
        isBacktracked = false;
        
        while(board[col] < 8)
        {
            board[col]++;
            if(board[col] == 8)
            {
                backtrack();
                continue;
            }
            if(ok(board,col)){
                break;
            }
        }
        col++;

    }
    
};


int seag(){
    char b[5][7] ={"a","a","","",""};
 
    cout<<sizeof(b + 1)<<endl;
    
    cout<<b<<endl;
    cout<<b+1<<endl;
    cout<<b+2<<endl;
    
 return 1;
}