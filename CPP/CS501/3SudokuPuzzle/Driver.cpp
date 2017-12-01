/*@file Driver.cpp
*
*Tasnim Bashar
* 15 October, 2017
*
*This program solves sudoku puzzle.This program create a puzzle object
*and populate it from input that hold the representation of a puzzle.
*It does this by holding square objects.
*It also enforces constraints among the squares in a row, column, or block. and the square object
*holds all of the information associated with one location in the puzzle.
*/

#include<iostream>
#include "puzzle.h"
using namespace std;

//if puzzle is solvable succeeds
bool solve(Puzzle& p, int n = 0);

int main()
{
   Puzzle p;
   cin >> p;
   cout << "Input Puzzle: " << endl;
   cout << p << endl;

   cout << "number of variable entries in the puzzle: " << p.size() << endl;
   cout << "number of empty square in the puzzle: " << p.numEmpty() << endl;

   if (p.size() == 81)
      cout << "the puzzle is already filled with fixed value " << endl;
   else
   {
      if (solve(p))
      {
         cout << "Solution of the Puzzle:" << endl;
         cout << p;
      }
      else
         cout << "Puzzle is not solvable";
   }
   return 0;
}

//if puzzle is solvable succeeds
bool solve(Puzzle& p, int n)
{
   //base case: when pass end of puzzle return success
   if (n >= 81)
      return true;

   //get row and col from n
   int row = n / 9;
   int col = n % 9;

   //Move to next squar if the location is not empty
   if (p.get(row, col).getValue() != 0)
      return solve(p, n + 1);

   for (int digit = 1; digit <= 9; digit++)
   {
      //if value is legal set
      if (p.set(digit, row, col))
      {
         if (solve(p, n + 1))
            return true;
      }

      //replace the value with empty square
      p.set(0, row, col);
   }

   return false;
};

