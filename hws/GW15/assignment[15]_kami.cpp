#include <iostream>
#include <vector>
#include<string>
#include<cmath>
using namespace std;
class Bob{
// three towers A,B,C represented as an array of 3 vectors
vector<int> towers[3];
//How many rings we have
int n;
//Canidate is the ring we're moving currently, EX T[1] == 3
int candidate;
//Next Tower
int to;
//Last Tower
int from;
//The number of moves to solve the problem
int moves;

bool swagok(){
    candidate  = towers[from].back();
    //Condition 1: Check if the the last Tower's Ring < Next Towers Ring
    //Condition 2: check if problem is solved by solving to 2^n -1
    if (candidate % 2 == 1){
        to = ((from + 2) % 3);
    }
    else{
        to = (from + 1) % 3;
    }
    if (moves == (pow(2,n) - 1)){
        return true;
    }
    else{
        return false;
    }
}

void dontrun(){
    cout << "Please enter an ODD number of rings to move: ";
    cin >> n;
    cout << endl;
    
    
    //intitialize the 3 towers
    for (int i = n + 1; i >= 1; i--){
        towers[0].push_back(i);
    }
    
    towers[1].push_back(n + 1);
    towers[2].push_back(n + 1);
    
    from      = 0;
    to        = 1;
    candidate = 1;
    
    
    //Loop until the second still has
    while (towers[1].size()){
        cout << "move number " << ++moves << ": Transfer ring" << candidate << " from tower " << char(from + 65) << " to tower " << char(to + 65) << endl;
        
        towers[to].push_back(candidate);
     
        towers[from].pop_back();
        
        if (towers[(to + 1) % 3].back() < towers[(to + 2) % 3].back()){
            from = (to + 1) % 3;
        }
        else{
            //Otherwise will increment from++
            from = (to + 2) % 3;
        }
        
        if (swagok()){
            break;
        }
    }
}
};