/*@file Drivercpp

*Tasnim Bashar
*October 11, 2017

*This program reads punch cards from input and
*writes the corresponding text to output window.

*We assumed that input is always valid

*/

#include <iostream>
#include "PunchCard.h"
#include <string>
using namespace std;

int main()
{
   // stops the infinity loop when last punch card is found
   while (true)
   {
      PunchCard punchCard;

      cin >> punchCard;
      cout << punchCard.toString() << endl;

      if (punchCard.isLastCard)
      {
         break;
      }
   }
   return 0;
}