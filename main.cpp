#include "TopSpin.h"
#include <iostream>
using namespace std;
int main()
{
	TopSpin newboard(20, 4); //new TopSpin type variable newboard that has parameters size 20 and spinnersize 4
	unsigned int amount;
	cout << "Enter the amount of times you would like to randomize the puzzle. (Positive Integers Only)" << endl;
	cin >> amount; //obtains number of times the puzzle will be randomized (user input)
	newboard.random(amount); //calls function random amount of times
	char choice ('0'); //user input choice variable intitalized as 0
	while (choice != '3') //loop keeps going while the choice is not equal to 3
	{
		cout << newboard << endl; //prints the board from TopSpin and << overload operator
		cout << "Please choose from the following options enter your choice by entering the corresponding number: " << endl
			<< "1. Shift" << endl << "2. Spin" << endl << "3. Quit" << endl;
		cin >> choice; //obtains choice from user
		if (choice == '1') //if choice is one 
		{
			cout << "Enter the number of shifts " << endl;
			int shifts;
			cin >> shifts; //user inputs number of shifts
			cout << "Enter the direction of the shifts" << endl << "l : left " << endl << "r : right " << endl;
			char direction;
			cin >> direction; //user inputs direction of shift 
			for (int k = 0; k < shifts; k++)
			{
				if (direction == 'l')
				{
					newboard.shiftLeft(); //if user inputs l then shiftLeft shifts amount of times
				}
				else
				{
					newboard.shiftRight(); //otherwise shiftRight shifts amount of times
				}
			}
		}
		else if (choice == '2')
		{
			newboard.spin(); //if userinput choice is 2 then the spinner is spun
		}
		}
	if (newboard.isSolved()) //if the board is solved 
	{
		cout << newboard << endl; //print the board again
		cout << "CONGRATULATIONS!" << endl;
		choice = '3'; //sets choice as 3 so the loop is exited
	}
	return 0;
}