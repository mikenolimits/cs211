//
//  michaelkantorhw2.cpp
//  HWS
//
//  Created by Michael Kantor on 2/3/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;



bool equal(int a[], int b[], int n){
	bool same = true;
	
	for(int i=0; i < n; i++){
		if(a[i] != b[i]){
			same = false;
			break;
		}
	}
	return same;
}


bool shiftCheck(int a[], int b[], int n, string direction){
	bool same = true;
	int garbage;
	
	for(int x = 0; x <= n; x++){
		

		int shiftDirection = (direction == "right") ? x + 1 : x - 1;
		
		//Shift To The New Direction
		for(int l = 0; l < n; l++){
			garbage           = b[shiftDirection];
			b[shiftDirection] = b[l];
			b[l]              = garbage;
			cout<<garbage<<endl;
		}
		
		if(!equal(a,b,n)){
			same = false;
			//cout<<x<<a[x]<<endl;
			//cout<<x<<b[x]<<endl;
			cout<<direction<<" shift is false \n";
			break;
		}
	}
	return same;
}



bool arrayCheck(int a[], int b[], int n){
	
	bool right;
	bool left;
	
	right    = shiftCheck(a,b,n,"right");
	left     = shiftCheck(a,b,n,"left");
	
	if(left || right){
		return true;
	}else{
		return false;
	}
	
}

void evalulate(bool s){
	if(!s){
		cout<<"the two arrays are not equal\n";
	}else{
		cout<<"the two arrays are equal\n";
	}
}


int main(){
	
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {3, 4, 5, 1, 2};
	
	bool same;
	
	same  = arrayCheck(arr1, arr2,5);
	
	evalulate(same);
	
}