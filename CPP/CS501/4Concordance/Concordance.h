#pragma once
#include<string>
#include"LinkedList.h"
using namespace std;

class Concordance
{
   string key;
   LinkedList values;
public:
   string getKey() const;
   LinkedList getvalues() const;
   void setKey(string val);
   void setValues(string before, string after);
   bool operator<(const Concordance& other) const;
   bool operator==(const Concordance& other) const;
   void print(ostream& output);

};

ostream& operator<<(ostream& output, Concordance& c);