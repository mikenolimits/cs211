//
//  main.cpp
//  HWS
//
//  Created by Michael Kantor on 2/3/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	
	int arr1[5] = {1, 2, 3, 4,5};
	int arr2[5] = {3, 4, 5, 1,2};
	bool same   =  true;
	
	for(int x = 0; x <= 3; x++){
		if(arr1[x] != arr2[x]){
			cout<<x<<arr1[x]<<endl;
			cout<<x<<arr2[x]<<endl;
			same = false;
			break;
		}
	}
	if(!same){
		cout<<"the two arrays are not equal";
	}else{
		cout<<"the two arrays are equal";
	}
	
	
}