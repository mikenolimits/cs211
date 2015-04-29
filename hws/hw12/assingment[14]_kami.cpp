#include <iostream>
using namespace std;
long int fib(int n){
    long int previous = -1;
    long int solution = 1;
    long int fib      = 0;
    
    for(long x = 0;x <= n;x++)
    {
        fib        = solution + previous;
        previous   = solution;
        solution   = fib;
    }
    
    return solution;
}
int lol(){
    for(int i=1; i<70; i++){
        cout<<" fib("<<i<<") = "<<fib(i)<<endl;
    }
    return 1;
}