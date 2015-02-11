//
//  michaelkantorhw3.cpp
//  HWS
//
//  Created by Michael Kantor on 2/4/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


int hw3(){
	
	cout<<"although we run out of numbers in a program, its also true that if we went up to the set of R (real numbers) then it would not be possible to find a number whose last two digits are odd and a sq.\n";
	cout<<"";
	cout<<"we can express a = b * 50 + c where c > 0 <= 50. So, c = a % 50. This is because (50 + c)^2 will have the same last two digits as c^2."<<endl;
    cout<<"Or in english, we only would need to preform the algorithm 50 times to know that there is no number whose last two digits are odd."<<endl;
	cout<<"So in c++ :)"<<endl;
	
	for (int i = 0; i <= 50; i++){
		cout<<"at position "<<i<<" the value is "<< (i * i) % 100<<endl;
	}
	cout<<"Or in math\n";
	cout<<"c^2 % 100 =\n";
	cout<<"( b * 50 + b )^2 % 100 =\n";
	cout<<"( (b *  50)^2 + 2 * c * b * 50 + c^2 ) % 100 = \n";
	cout<<"( b * b * 2500 + c * c * 100 + c^2 ) % 100 =\n";
	cout<<"( a % 50 )^2 % 100\n";
	cout<<"So some number % 50 squared has the same last two digits as some number squared.\n";
	cout<<"Having proved this, we can say that if we set i in the loop above to the set of R, the program will run infinitely.\n";
	
	return 1;
}