/*@file PunchCard.h

Tasnim Bashar
11 October, 2017

*/

#include <iostream>
using namespace std;

#ifndef _PUNCHCARD 
#define _PUNCHCARD

class PunchCard
{
private:
   //data which stores zone punch and other punch value for every column
   int card[2][80];

   //encoding scheme(simplified EBCD) 
   const static char encodingTable[4][10];

public:
   bool isLastCard;

   //constructor to set value of card[][] and isLastCard variable 
   PunchCard();

   //decode output using encodingTable[][] for card[][] 
   string toString() const;

   /*For a punch card, it will take 12 line of strings from input and store
   the zone punch information in the 1st row and other punch
   information in the 2nd row of the card variable for 80 columns
   13th line will be ignored*/
   void populatePunchCard(istream& input);
};

istream& operator>>(istream& input, PunchCard &punchCard);

#endif