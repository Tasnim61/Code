/*@file Puzzle.cpp
*
*Tasnim Bashar
* 15 October, 2017
*
*Puzzle class must hold the representation of a puzzle.
*It does this by holding Square objects. It also enforces constraints among the squares
*in a row, column, or block.
*/

#include <iostream>
#include "puzzle.h"
#include <string>
using namespace std;

//constructor
Puzzle::Puzzle() {
   this->numOfFixed = 0;
}

//check whether the value is legal to set at board[row][col]
bool Puzzle::isLegal(int val, int row, int col)
{
   for (int i = 0; i < 9; i++)
   {
      //if the value exists in the entire row or col, value is not legal, return false 
      if (board[row][i].getValue() == val || board[i][col].getValue() == val)
         return false;
      //if the value exists in the corresponding block, value is not legal, return false
      if (board[(row / 3) * 3 + (i / 3)][(col / 3) * 3 + (i % 3)].getValue() == val)
         return false;
   }
   return true;
}

//takes row and col and return square object at that location 
Square Puzzle::get(int row, int col)
{
   return board[row][col];
}

/*takes value,row and col and sets square object at that location if the value
* is legal for that square and return true otherwise return false */
bool Puzzle::set(int val, int row, int col)
{
   //if the value is 0 that means we will replace the existing value with 0
   //no need to check legality
   if (val == 0)
   {
      board[row][col].setValue(val);
      return true;
   }

   // if the value is not legal at the position return false
   if (!isLegal(val, row, col))
      return false;

   //else the value is legal so set value of square obj at that location(board[r][c])
   else
   {
      board[row][col].setValue(val);
      return true;
   }
}

// if the char is numerical digits (0 to 9) succeds
bool Puzzle::isNumeric(char in)
{
   if (in >= '0' && in <= '9')
      return true;
   return false;
}

/*From input we will take 81 numerical digits,square obj from 1st digit
* will  be stored in board[0][0] and last will be stored in board[8][8]*/
void Puzzle::populateBoard(istream& input)
{
   int count = 0;

   //will continue take input utill get 81 digits(which is 0 to 9) 
   while (count < 81)
   {
      char in;
      input >> in;

      //eof exists before taking 81 digits throw error
      if (input.eof())
         throw invalid_argument("End of File before 81 digit");

      //ignore all non-digit characters
      if (isNumeric(in) )
      {
         //Blank squares are represented with zeros
         if (in == '0')
         {
            Square a(0, false);
            board[count / 9][count % 9] = a;
         }

         // if not blank
         else
         {
            Square a(static_cast<int>(in - '0'), true);
            this->numOfFixed++;
            board[count / 9][count % 9] = a;
         }
         count++;
      }
   }

}

/*return the number of variable entries in the puzzle, corresponding to the
original size of the puzzle (before any blank squares are filled in).*/
int Puzzle::size()
{
   return this->numOfFixed;
}

//return the number of empty squares (those without any value).
int Puzzle::numEmpty()
{
   return(81 - this->numOfFixed);
}

// display a puzzle as formatted text.
void Puzzle::printBoard(ostream& output)
{
   string border = "+-------+-------+-------+";
   output << border << endl;
   for (int r = 0; r < 9; r++)
   {
      for (int c = 0; c < 9; c++)
      {
         if ((r == 3 && c == 0) || (r == 6 && c == 0))
            output << border << endl;

         if (c == 0 || c == 3 || c == 6)
            output << "| ";
         if (c != 8)
            output << board[r][c].getValue() << " ";
         else
            output << board[r][c].getValue() << " |" << endl;
      }
   }
   output << border << endl;

}

// input overloading operator
istream& operator>>(istream& input, Puzzle& p)
{
   p.populateBoard(input);
   return input;
}

// output overloading operator
ostream& operator<<(ostream& output, Puzzle& p)
{
   p.printBoard(output);
   return output;
}