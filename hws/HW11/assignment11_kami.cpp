// CS211 Print a chessboard
#include<iostream>
using namespace std;


int main(){
    int i,j,k,l;
    
    typedef char box[5][7];
    
    box bb,wb,bq,wq,*board[8][8];
    char H = char(219);
    
    //create black queen image
  
    //create white queen image by inverting black queen image
    for(i=0;i<5;i++){
        for(j=0;j<7;j++){
            if(bq[i][j]==' ') wq[i][j]=H;
            if(bq[i][j]==H) wq[i][j]=' ';
        }
    }
    
    //fill in bb=black box and wb=whitebox
    for(i=0;i<5;i++)
        for( j=0;j<7;j++){
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }
    
    //fill board with pointers to bb and wb in alternate positions
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if((i+j)%2==0)
                board[i][j]=&wq;
            else board[i][j]=&bq;
    
    // print the board via the pointers in array board
    
    // first print upper border
    cout<<" ";
    for(i=0;i<7*8;i++)
        cout<<'_';
    cout<<endl;
    
    // now print the board
    for(i=0;i<8;i++)
        for(k=0;k<5;k++){
            cout<<" "<<char(179); //print left border
            for(j=0;j<8;j++)
                for(l=0;l<7;l++)
                    cout<<(*board[i][j])[k][l];
            cout<<char(179)<<endl; // at end of line print bar and then newline
        } 
    
    //before exiting print lower border 
    cout<<" "; 
    for(i=0;i<7*8;i++) 
        cout<<char(196); 
    cout<<endl;  
    
    return 0;
}