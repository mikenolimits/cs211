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
    
bool ok()
{
    
    
    //the exit conditions are
    //1. if the current col is equal to the current iteration of the loop
    //2. if the current column in the helper is -1
    //3. if the current position in the board is 1
    
    
    static int helpTable[8][4] =
    {
        {-1},
        {0,-1},
        {1, -1},
        {0, 1, 2, -1},
        {1, 2, 3, -1},
        {0, 3, 4, -1},
        {3, 4, 5, -1},
        {2, 4, 6, -1}
    };
    
    int y = 0;
    int x = 0;
    
    while(x < col){
        //We need to make sure that the current column doesn't match up with the interation.
        if (board[col] == board[x]) {
            return false;
        }
        x++;
    }
    
    while(true){
    

        if(helpTable[col][y] == -1){
            break;
        }
    
        int position = board[col] - board[helpTable[col][y] ];
        
        if(abs(position) == 1){
            return false;
        }
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
    
    void outputRow(int size, string space = ""){
        
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
    
    
    int run()
    {
        while(true)
        {
            while( col < 8)
            {
                ColumnIncrementor();
            }
            getSolution();
            reboot();
            isBacktracked = true;
        }
        
        return 0;
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


int main(){
    CrossProblem x = CrossProblem();
    x.init();
    x.run();
}