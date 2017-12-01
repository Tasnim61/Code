/*@file PunchCard.cpp

*Tasnim Bashar
* 11 October, 2017

*Implementions of which is declared in the PunchCard.h file.
*/

#include "PunchCard.h" 
#include <string>
using namespace std;

//encoding scheme(simplified EBCD) 
const char PunchCard::encodingTable[4][10] = {
   { ' ','1','2','3','4','5','6','7','8','9' },
   { '&','A','B','C','D','E','F','G','H','I' },
   { '-','J','K','L','M','N','O','P','Q','R' },
   { '0','/','S','T','U','V','W','X','Y','Z' }
};

/*constructor to set value of card[2][80] to 0
*and isLastCard to false
*/
PunchCard::PunchCard()
{
   //initialize the card with zero
   for(int i = 0; i < 2; i++)
   {
      for(int j = 0; j < 80; j++)
      {
         this->card[i][j] = 0;
      }
   }
   this->isLastCard = false;
}

/*For a punch card, it will take 12 line of strings from input and store
the zone punch information in the 1st row and other punch
information in the 2nd row of the card variable for 80 columns
13th line will be ignored*/

void PunchCard::populatePunchCard(istream& input)
{
   string str;
   // 
   for (int i = 0; i < 12; i++)
   {
      str = "";
      getline(input, str);

      for (int j = 1; j < 80; j++)
      {
         //if there is a puch
         if (str[j] == 'X')
         {
            //zone punch 
            if (i >= 0 && i < 3)
            {
               card[0][j] = i + 1;
            }
            //other punch
            else
            {
               card[1][j] = i - 2;
            }
         }
      }
   }
   // last card
   if (str[0] == 'X')
   {
      this->isLastCard = true;
      return;
   }

   input.ignore();
}

//decode output using encodingTable[][] for card[][]
string PunchCard::toString() const
{
   string str = "";
   // for each column i of card[][], char= encodingTable[[card's 1st row of col i][card's 2nd row of col i]]
   for (int i = 0; i < 80; i++)
   {
      str += encodingTable[card[0][i]][card[1][i]];
   }

   return str;
}

// input overloading operator
istream& operator>>(istream& input, PunchCard& punchCard)
{
   punchCard.populatePunchCard(input);
   return input;
}

