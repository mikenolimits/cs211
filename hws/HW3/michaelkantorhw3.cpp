//
//  michaelkantor3.cpp
//  HWS
//
//  Created by Michael Kantor on 2/10/15.
//  Copyright (c) 2015 Twitch. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

	/*
	 No clue if any of this code works, its mostly based on the sudo code given in class
	 since i don't like math too much, but it does print out solutions ?
	 */

	int position;

	int queensBoard[8]  = {0};
	int solutions       =  0;
	int queensColumn    =  0;
	int queensRow       =  0;

	/*
	 At this point our current board works, so this method just tells us
	 what our current solution is, basically not doing much else than abstraction.
	 Better than nothing considering how catastrophic the labels make this program
	 */
	void getSolution(){
		solutions++;
		cout << "There Are " << solutions << " Solutions\n";
		cout<<"The current combination is : ";
		for(int i = 0; i < 8; i++){
			cout <<queensBoard[i];
		}
		cout <<"\n";
  }

  bool positionIsValid(){
	//Consider the possibility that a current position might be negative.
	position = queensBoard[queensColumn] - queensBoard[queensRow];
	
	if(position < 0){
		position =  position * -1;
	}
	if(position == queensColumn - queensRow){
		return false;
	}
	  return true;
  }

    int main(){
		
	ColumnIncrementer:
		//Move to the next Column
		queensColumn++;
		if (queensColumn == 8){
			goto solutionsOutput;
		}else{
			queensBoard[queensColumn] = -1;
		}
		
		/*
		 There wasn't really a need to create a 2D board since we keep
		 track of the column as a global variable and can just reset it
		 when the time comes. So instead our RowIncrementor moves to the next
		 place on our board, evaulates weather we are out of rows, and if not
		 moves to the next column.
		 */
	RowIncrementer:
		//Move to the next Row or go back if we are on the 8th col
		
		queensBoard[queensColumn]++;
		
		if (queensBoard[queensColumn] == 8) {
			goto reboot;
		}
		queensRow = 0;
		
		while(queensRow < queensColumn){
			
			if(!positionIsValid()){
				goto RowIncrementer;
				//consider the posibility that the current queens position is the same as the current column
			}else if(queensBoard[queensRow] == queensBoard[queensColumn]){
				goto RowIncrementer;
			}
			
			queensRow++;
		}
		goto ColumnIncrementer;
		
		/*
		 If we've found all the solutions we terminate the program,
		 otherwise, we start from the top and move onto the next row.
		 */
	reboot:
		queensColumn--;
		if(queensColumn == - 1){
			//YAY WE FOUND ALL THE SOLUTIONS o/
			exit(0);
		}else{
			//Theres more solutions :(
			goto RowIncrementer;
		}
		
	solutionsOutput:
		getSolution();
		goto reboot;
 }
