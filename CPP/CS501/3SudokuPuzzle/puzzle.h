/*@file Puzzle.h
*
*Tasnim Bashar
* 15 October, 2017
*
*Puzzle.h contains the declaration of Puzzle.cpp file.
*/

#pragma once
#include<iostream>
#include"square.h"
#include <vector>

using namespace std; 

class Puzzle
{

private:
   //9*9 Array to store sudoku puzzle
   Square board[9][9];
   //number of fixed square obj in board[][]
   int numOfFixed;

   // if the char is numerical digits (0 to 9) succeds
   bool isNumeric(char in);

   //check whether the value is legal to set at board[row][col]
   bool isLegal(int val, int row, int col);

public:
   //constructor
   Puzzle();

   //takes row and col and return square object at that location 
   Square get(int row, int col);

   /*takes value,row and col and sets square object at that location if the value
   * is legal for that square and return true otherwise return false
   */
   bool set(int val, int row, int col);

   //From input we will take 81 numerical digits ignoring others.Square obj from 1st digit
   //will  be stored in board[0][0] and last will be stored in board[8][8]
   void populateBoard(istream& input);

   // display a puzzle as formatted text.
   void printBoard(ostream& output);

   /*return the number of variable entries in the puzzle, corresponding to the
   original size of the puzzle (before any blank squares are filled in).*/
   int size();

   //return the number of empty squares (those without any value).
   int numEmpty();
};

// input overloading operator
istream& operator>>(istream& input, Puzzle& p);

// output overloading operator
ostream& operator<<(ostream& output, Puzzle& p);
