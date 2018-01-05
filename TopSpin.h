#pragma once
#include "TopSpinADT.h"
#include "CDLL.h"
using namespace std;
class TopSpin : public TopSpinADT
{	
private:
	int _size, _spinSize; //size of board and size of spinner
	CDLL <int> board; //type int CDLL 
public:
	TopSpin(int size, int spinSize); //constructor with parameters int size and int spinsize
	~TopSpin(); //destructor
	void random(unsigned int times); //random function 
	void shiftLeft(); //shift board left
	void shiftRight(); //shift board right 
	void spin(); //spins the spinner
	bool isSolved(); //checks to see if puzzle is solved 
	friend ostream& operator<< (ostream& os, const TopSpin& ts); // overload << operator 
};
inline ostream& operator<< (ostream& os, const TopSpin& ts) //overload << operator function
{
	for (int k = 1; k <= ts._size; k++) //outputs the CDLL board
	{
		if (k == 1 || k == (ts._spinSize + 1))
		{
			os << "| "; //outputs the layout indicating where the spinner is
		}
		os << ts.board.getData(k) << " "; //calling get data function from CDLL
	}
	return os;
}	