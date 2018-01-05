#include "TopSpin.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

TopSpin::TopSpin(int size, int spinSize) 
{
	_size = size; 
	_spinSize = spinSize;

	// initalizes the size and spinSize 
	if (size < 1)
	{
		size = 20; 
	}
	if (spinSize > size)
	{
		spinSize = 4;
	}

	for (int k = 1; k <= size; k++)
	{
		board.addData(k); //adds Nodes of value k to the CDLL board from 1 to size of the board
	}
}

TopSpin::~TopSpin() //empty destructor as CDLL board is not a pointer
{

}

void TopSpin::random(unsigned int times)  //random function
{
	srand(time(NULL)); //randomizes numbers
	unsigned int leftShift = rand() % 19 + 1; //leftShift is a random number between 1 and 19
	for (unsigned int c(0); c < times; c++)  //repeats the following for times amount
	{
		for (unsigned int i(1); i <= leftShift; i++)
		{
			shiftLeft(); //shifts the board to the left a random number of times between 1 and 19
		}
		spin(); //then spins the board 
	}
}

void TopSpin::shiftLeft() 
{
	board.incrementHead(); //shifts the board left by making the head Node to the next one 
}

void TopSpin::shiftRight()
{
	board.decrementHead(); //shifts the board right by making the head Node the old tail	 
}

void TopSpin::spin()
{
	int temp = _spinSize; //sets temp as the spinner size
	for (int k = 1; k <= temp; k++)
	{
		board.swap(k, temp); //swaps the numbers in the spinner 
			temp--; //decremenents the spinner size holder
	}
}

bool TopSpin::isSolved() 
{
	for (int k = 1; k <= _size; k++)
	{
		if (board.getData(k) != k) // if the board is not in ascending order then return false
		{
			return false;
		}
	}
	return true; //return true if every number matches 
}