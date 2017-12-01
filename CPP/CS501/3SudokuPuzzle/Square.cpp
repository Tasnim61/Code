/*@file Square.cpp
*
*Tasnim Bashar
* 15 October, 2017
*
*A Square class holds all of the information associated with one location in the puzzle.
*/

#include "square.h"
using namespace std;

//contructor to set the value and isFixed with default value -1 and default isFixed to false
Square::Square(int val, bool isFixed) :value(val), isFixed(isFixed) {}

//Returns the current value (if no value set, it will return (default value)-1 ).
int Square::getValue()const
{
   return value;
}

//Takes a single integer and sets the value to the given argument
void Square::setValue(int val)
{
   this->value = val;
}
