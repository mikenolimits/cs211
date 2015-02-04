//
//  main.cpp
//  C++Final
//
//  Created by Michael Kantor on 12/22/14.
//  Copyright (c) 2014 Twitch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int old() {
	cout<<"There are no perfect squares who last two digits are both odd.\n";
	cout<<"But for the sake of argument.....\n";
	
	int sq;
	int num = 1;

	bool onesplace  = false;
	bool tensplace  = false;
	
	while(!onesplace || !tensplace){
		//Reset the bools on every loop.
		onesplace = false;
		tensplace = false;
		
		sq     = num * num;
		cout<<"The current sq is"<<sq<<endl;
		int x  = sq % 10;
		int y  = sq / 10 % 10;
		
		if(x % 2 != 0){
			cout<<x<<" Ones is true\n";
			onesplace = true;
		}
		if(y % 2 != 0){
			cout<<y<<" Tens is true\n";
			tensplace = true;
		}
		
		if (onesplace && tensplace) {
			cout << "found a sq :"<< sq<<endl;
		}
		num++;
	}
	cout<<"This problem was a trick question.\n";
	
	return 0;
}