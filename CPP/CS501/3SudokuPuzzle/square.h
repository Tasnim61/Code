/*@file Square.h
*
*Tasnim Bashar
* 15 October, 2017
*
*Square.h contains the declaration of Square.cpp file.
*/

#pragma once
#include <iostream>

class Square
{
   friend class Puzzle;
   //the square's numerical value
   int value;
   //flag indicating if the value is fixed or not
   bool isFixed;
public:
   //contructor with default value -1 and isFixed to false
   Square(int val = (int)-1, bool isFixed = false);

   //Returns the current value (if no value set, it will return (default value)-1 ).
   int getValue() const;
protected:
   //Takes a single integer and sets the value to the given argument
   void setValue(int val);
};