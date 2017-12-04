#include<iostream>
#include<iomanip>
#include<string>
#include"Concordance.h"
using namespace std;

string Concordance::getKey()const
{
   return key;
}

LinkedList Concordance::getvalues()const
{
   return values;
}

void Concordance::setKey(string val)
{
   this->key = val;
}

void Concordance::setValues(string before, string after)
{
   this->values.addLast(before, after);
}
bool Concordance:: operator<(const Concordance& other) const
{
   if (this->key < other.key)
      return true;
   return false;
}

bool Concordance:: operator==(const Concordance& other) const
{
   if (this->key == other.key)
      return true;
   return false;
}

void Concordance::print(ostream& output)
{
   Node* curr = this->values.head;
   while (curr != nullptr)
   {
      output << std::right << setw(50) << curr->before;
      output << " " << std::left << setw(15) << key << " " << curr->after << endl;
      curr = curr->next;
   }
}

ostream& operator<<(ostream& output, Concordance& c)
{
   c.print(output);
   return output;
}

