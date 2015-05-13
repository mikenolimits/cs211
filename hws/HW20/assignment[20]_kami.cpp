#include <iostream>
using namespace std;
class Rat{
private:
    int n;
    int d;
public:
    // constructors
    
    // default constructor
    Rat(){
        n=0;
        d=1;
    }
    
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    }
    // conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }
    
    //accessor functions (usually called get() and set(...) )
    int getN(){ return n;}
    int getD(){ return d;}
    void setN(int i){ n=i;}
    void setD(int i){ d=i;}
    
    Rat simplify(){
        
        int numerator   = n;
        int denominator = d;
        
        int biggest     = numerator;
        
        int GreatestCommonDenominator = 1;
    
        if(numerator < denominator){
            biggest = denominator;
        }
        
        //Find the GCD. It can't be <= 1
        for (int i = biggest; i >= 2; i--) {
            if ((denominator % i == 0) && (numerator % i == 0)) {
                GreatestCommonDenominator = i;
                break;
            }
        }
        
        //Using the GCD, divide top & bottom
        if(GreatestCommonDenominator != 0){
            numerator /= GreatestCommonDenominator;
            denominator /= GreatestCommonDenominator;
        }
        
        d = denominator;
        n = numerator;
        //this = the current instance via pointer reference.
        return *this;
    }
    
    Rat operator+(Rat r){
        Rat t;
        t.n = n*r.d + d * r.n;
        t.d = d*r.d;
        
        
        return t.simplify();
    }
    
    Rat operator -(Rat r){
        Rat t;
        //(numerator * denominator of R) - (Denominator * Numerator of R)
        t.n = n*r.d - d * r.n;
        t.d = d*r.d;
        
        return t.simplify();
    }
    
    Rat operator *(Rat r){
        Rat t;
        //(numerator * denominator of R) - (Denominator * Numerator of R)
        t.n = n * r.n;
        t.d = d * r.d;
        
        return t.simplify();
    }
    
    Rat operator /(Rat r){
        Rat t;
        //(numerator * denominator of R)
        t.n = n*r.d;
        //Denominator * Numerator
        t.d = d * r.n;
        
        return t.simplify();
    }

    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
    
};
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
    
    if(r.n < r.d){
        os<<r.n<<" / "<<r.d<<endl;
    }else{
        //Get the mixed number on the left. easy.
        int left  = r.n / r.d;
        
        int right = r.n % r.d;
        
        os<<left<< " "<< right <<" / "<<r.d<<endl;
    }
    return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    return is;
}
int rats(){
    Rat x(4,4), y(2,4), z;
    //outputs mixed number 1 1/2
    z = x+y;
    cout<<z;
    
    x.setD(200);
    x.setN(100);
    //outputs 1/4
    z =  x * y;
    cout<<z;
    return 0;
}