/*@file BCD.cpp

*Tasnim Bashar
* 1 November, 2017
*Implemention a Binary Coded Decimal (BCD) class to conduct arithmetic
*operations between two numbers where the range of integer is much larger
*than int or long data type in C++
*/
#include "BCD.h"
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

//constructor
Node::Node() {
   root = 0;
   next = nullptr;
}

Node::Node(int val) {
   root = val;
   next = nullptr;
}

BCD::BCD()
{
   head = new Node();
   isPositive = true;
}

BCD::BCD(int val)
{
   long value = val;
   head = new Node();
   isPositive = (value >= 0);

   Node* curr = head;
   while (true)
   {
      int digit = value % 10;
      curr->root = (digit < 0) ? -digit : digit;

      value = value / 10;
      if (value == 0)
         break;

      curr->next = new Node();
      curr = curr->next;
   }
}

BCD::BCD(string str)
{
   this->populateFromString(str);
}

BCD::BCD(const BCD& b)
{
   isPositive = b.isPositive;
   head = LinkedList::copyNodeList(b.head);
}

BCD& BCD:: operator=(const BCD& b)
{
   if (this != &b)
   {
      deleteNodeList();

      this->isPositive = b.isPositive;
      this->head = LinkedList::copyNodeList(b.head);
   }
   return *this;
}

BCD::~BCD() {
   this->deleteNodeList();
}

void BCD::deleteNodeList()
{
   while (head != nullptr)
   {
      Node* garbage = head;
      head = head->next;

      delete garbage;
      garbage = nullptr;
   }
}

Node* LinkedList::copyNodeList(const Node* n)
{
   if (n == nullptr)
      return nullptr;

   Node* result = new Node(n->root);;
   Node* curr = result;

   while (n->next != nullptr)
   {
      curr->next = new Node(n->next->root);
      n = n->next;
      curr = curr->next;
   }
   return result;
}

Node* LinkedList::reverseList(Node* n)
{
   if (n == nullptr || n->next == nullptr)
      return n;

   Node *head = LinkedList::reverseList(n->next);
   n->next->next = n;
   n->next = nullptr;
   return head;
}

void BCD::populateBCD(istream& input)
{
   this->deleteNodeList();
   this->isPositive = true;

   bool isFirst = true;

   // read the characters until 
   // end of line (Ctrl + Z - in windows) is read 
   // or other than 0-9 characters are read
   string str = "";
   char ch;
   while (cin >> ch)
   {
      if (isFirst && (ch == '-' || ch == '+'))
      {
         str += ch;
         isFirst = false;
      }
      else if (ch >= '0' && ch <= '9')
      {
         str += ch;
      }
      else break;
   }

   this->populateFromString(str);
}

void BCD::populateFromString(string str)
{
   this->isPositive = true;
   this->head = nullptr;

   if (str.numOfFixed() == 0)
   {
      this->head = new Node();
      return;
   }

   for (int i = 0; i < static_cast<int>(str.numOfFixed()); i++)
   {
      if (str[i] >= '0' && str[i] <= '9')
      {
         //add to the head of the linked list
         Node* n = new Node(static_cast<int>(str[i] - '0'));
         n->next = this->head;
         this->head = n;
      }
      else if (i == 0 && str[i] == '-')
      {
         this->isPositive = false;
      }
      else break;
   }
}

//print BCD 
void BCD::printBCD(ostream& output)
{
   if (isPositive == false)
      output << '-';
//used string to store BCD
   Node* curr = head;
   string s = "";

   while (curr != nullptr)
   {
      char c = '0' + curr->root;
      s = c + s;
      curr = curr->next;
   }

   output << s;
}

bool BCD:: operator <(const BCD& other)
{
   //if this is negative but other is positive
   if (this->isPositive < other.isPositive)
      return true;
   
   // if this is positive but other is negative
   if (this->isPositive > other.isPositive)
      return false;

   //otherwise (if the signs are equal) then

   // if the signs are positive
   if(this->isPositive == true)
      // return true if (this < other) without considering sign
      return LinkedList::compareTwoList(head, other.head) < 0;
   //if the signs are negative
   else
      // return true if (head > other) without considering sign
      return LinkedList::compareTwoList(head, other.head) > 0;
}

bool BCD:: operator ==(const BCD& other)
{
   // if the signs are equal then 
   if (this->isPositive == other.isPositive)
      //check if the list are equal
      return LinkedList::compareTwoList(head, other.head) == 0;

   return false;
}

int LinkedList::compareTwoList(const Node* a, const Node* b) {

   if (a == nullptr && b == nullptr)
      return 0;
   if (a == nullptr && b != nullptr)
      return -1;
   if (b == nullptr && a != nullptr)
      return 1;

   int ret = LinkedList::compareTwoList(a->next, b->next);

   if (ret == 0)
   {
      if (a->root < b->root)
         return -1;//a<b
      else if (a->root > b->root)
         return 1;//a>b
      else
         return 0;//equal
   }

   return ret;
}

BCD::operator int() const
{
   long ans = 0;
   Node* curr = this->head;

   int sign = 1;
   if (this->isPositive == false)
      sign = -1;
   int i = 1;
   try {
      while (curr != nullptr)
      {
         ans = i * curr->root + ans;
         if (ans*sign > INT_MAX || ans*sign < INT_MIN)
            throw "BCD cannot convert to int because of integer overflow";
         i = i * 10;
         curr = curr->next;
      }
   }
   catch (const char* msg) {
      cerr << msg << endl;
      return 0;
   }

   return ans*sign;
}

BCD BCD::operator +(const BCD& bcd)
{
   BCD ans;
   int compareList = LinkedList::compareTwoList(this->head, bcd.head);

   //if the sign for both BCD is equal then do (this + bcd)
   if (this->isPositive == bcd.isPositive) 
   {
      ans.head = LinkedList::sum(this->head, bcd.head);
      ans.isPositive = this->isPositive;
   }
   //if the sign is different for two BCDs
   else 
   {
      // if sign is different, and they are equal then return zero
      if (compareList == 0)
         return ans;

      // if (this < bcd) then do (bcd - this)
      if (compareList < 0)
      {
         ans.head = LinkedList::sub(bcd.head, this->head);
         ans.isPositive = bcd.isPositive;
      }
      // otherwise (this > bcd), do (this - bcd) 
      else
      {
         ans.head = LinkedList::sub(head, bcd.head);
         ans.isPositive = this->isPositive;
      }
   }
   return ans;
}

BCD BCD::operator -(const BCD& bcd)
{
   BCD ans;
   int compareList = LinkedList::compareTwoList(this->head, bcd.head);

   // if both signs different, then do LinkedList::sum
   if(this->isPositive != bcd.isPositive)
   {
      ans.head = LinkedList::sum(head, bcd.head);
      ans.isPositive = this->isPositive;
   }
   // if signs are equal
   else 
   {
      // equal number subtract equal zero
      if (compareList == 0)
         return ans;

      //if (this < bcd) without sign
      if (compareList < 0)
      {
         // do (bcd - this) and sign is opposite of this
         ans.head = LinkedList::sub(bcd.head, head);
         ans.isPositive = !this->isPositive;
      }
      // if (this > bcd) without sign
      else
      {
         ans.head = LinkedList::sub(head, bcd.head);
         ans.isPositive = this->isPositive;
      }
   }
   return ans;
}

BCD BCD:: operator *(const BCD& bcd)
{
   BCD result;

   // m1 (this) * m2 (bcd)
   const Node* m1Head = this->head;
   const Node* m2Head = bcd.head;

   // do m1(top) * m2 (bottom) according to pencil and paper style
   int count = 0;
   while (m2Head != nullptr)
   {
      const Node* m1Curr = m1Head;
      // temp is used for the temporary multiplication value to add to the final result
      BCD temp;
      Node* tempCurr = temp.head;
      int carry = 0;

      // shift the temp multiplication value by filling with zero
      for(int i = 0; i < count; i++)
      {
         tempCurr->next = new Node(0);
         tempCurr = tempCurr->next;
      }

      //until all the digit of the m1 is multiplied or there is no carry left do the digit multiplication
      while (m1Curr != nullptr || carry > 0)
      {
         // calculate the current digit for temp BCD and carry value
         int value = (m1Curr == nullptr ? 0 : m1Curr->root)*(m2Head == nullptr? 0 : m2Head->root) + carry;
         carry = 0;

         if (value > 9) 
         {
            carry = value / 10;
            value = value % 10;
         }
         tempCurr->root = value;

         if (m1Curr != nullptr)
            m1Curr = m1Curr->next;

         if (m1Curr != nullptr || carry > 0)
         {
            tempCurr->next = new Node();
            tempCurr = tempCurr->next;
         }

         if (m1Curr == nullptr && carry == 0) 
         {
            result.head = LinkedList::sum(temp.head, result.head);
            count++;
         }

      }
      // take the next digit from the m2 (bcd)
      m2Head = m2Head->next;
   }

   result.isPositive = (this->isPositive == bcd.isPositive);
   return result;
}

BCD BCD:: operator /(const BCD& bcd)
{
   BCD ans;

   // handle divide by zero case
   try 
   {
      if (LinkedList::compareTwoList(ans.head, bcd.head) == 0)
         throw "something/0 is undefined";
   }
   catch (const char* msg) 
   {
      cerr << msg << endl;
      return ans;
   }

   // if the dividend is zero then ans = 0
   if (*this == BCD())
      return ans;

   // compare without considering the sign
   int compareList = LinkedList::compareTwoList(this->head, bcd.head);

   // if this < bcd, then this/bcd = 0 for integer division
   if (compareList < 0)
   {
      return ans;
   }

   // sign of the ans
   ans.isPositive = (this->isPositive == bcd.isPositive);

   // if this == bcd, then this/bcd = 1
   if (compareList == 0)
   {
      ans.head->root = 1;
      return ans;
   }

   // if this > bcd, then do the division operation
   BCD dividend(*this);
   dividend.head = LinkedList::reverseList(dividend.head);
   Node* currDividend = dividend.head;
   BCD subDividend;

   while (1)
   {
      //retrieve a subDividend from the dividend for subtract
      while (LinkedList::compareTwoList(subDividend.head, bcd.head) < 0)
      {
         // if all the digits of the dividends are finished then return ans
         if (currDividend == nullptr)
         {
            LinkedList::deleteZerosFromEndofTheList(ans.head);
            return ans;
         }

         // build up the subDividend from the dividend
         LinkedList::addToFront(subDividend.head, currDividend->root);
         LinkedList::deleteZerosFromEndofTheList(subDividend.head);

         //advance the currDividend until finish
         currDividend = currDividend->next;
         
         // if subDividend is smaller than divisor, then add 0 to the ans list
         if (LinkedList::compareTwoList(subDividend.head, bcd.head) < 0) 
         {
            LinkedList::addToFront(ans.head, 0);
         }
      }

      // do the multiplication by digits with divisor to get a digit in ans
      // and then do the subtraction
      int ansDigit = 9;
      while (ansDigit >= 1)
      {
         // check with 9 to 1 digit by multiplying with divisor (bcd) if that value is less than or equal of the subDividend
         BCD mul ((BCD(bcd) * BCD(ansDigit)));
         if (mul == subDividend || mul < subDividend)
         {
            //add the digit to ans
            LinkedList::addToFront(ans.head, ansDigit);

            // then subtract (subdividend - divisor*ansDigit)
            Node* subtract = LinkedList::sub(subDividend.head, mul.head);
            subDividend.setList(subtract);
            
            break;
         }
         ansDigit--;
      }
   }
}

void LinkedList::addToFront(Node*& head, int root)
{
   Node* n = new Node(root);
   n->next = head;
   head = n;
}

void BCD::setList(Node* n)
{
   if (this->head != nullptr)
   {
      deleteNodeList();
   }
   this->head = n;
}

// Add two linked list and create a new linked list with the LinkedList::sum value
Node* LinkedList::sum(Node* a, const Node* b)
{
   if (a == nullptr && b == nullptr)
      return nullptr;

   Node* head = new Node();
   Node* n = head;
   int carry = 0;

   while (a != nullptr || b != nullptr || carry > 0)
   {
      int root = ((a != nullptr) ? a->root : 0) + ((b != nullptr) ? b->root : 0) + carry;
      n->root = root % 10;
      carry = root / 10;
      
      if (a != nullptr)
         a = a->next;
      if (b != nullptr)
         b = b->next;

      if (a != nullptr || b != nullptr || carry > 0)
      {
         n->next = new Node();
         n = n->next;
      }
   }

   return head;
}

// Subtract two list
// Condition to be true: (a >=b)
Node* LinkedList::sub(const Node* a, const Node* b)
{
   if (a == nullptr && b == nullptr)
      return nullptr;

   Node* result = new Node();
   Node* curr = result;

   int carry = 0;
   while (a != nullptr || carry > 0)
   {
      //calculate aVal (from a), bVal (from b) and carry (for the next step)
      int aVal = (a != nullptr) ? a->root : 0;
      int bVal = (b != nullptr ? b->root : 0) + carry;
      carry = 0;

      if (bVal > 9)
      {
         carry = bVal / 10;
         bVal = bVal % 10;
      }

      if (aVal < bVal) {
         aVal = 10 + aVal;
         carry += 1;
      }

      // set digit to result list
      int root = aVal - bVal;
      curr->root = root;

      // advance to next digit
      a = a->next;
      if (b != nullptr)
         b = b->next;

      if (a != nullptr)
      {
         curr->next = new Node();
         curr = curr->next;
      }
   }

   // if a is not finished, then add the rest of the digit from a to the result list
   if (a != nullptr)
   {
      while (a != nullptr)
      {
         curr->root = a->root;
         a = a->next;
         if (a != nullptr)
         {
            curr->next = new Node();
            curr = curr->next;
         }
      }
   }

   LinkedList::deleteZerosFromEndofTheList(result);
   return result;
}

Node* LinkedList::getTail(Node* head)
{
   if (head == nullptr)
      return nullptr;
   while (head->next)
   {
      head = head->next;
   }
   return head;
}

void LinkedList::deleteZerosFromEndofTheList(Node* head)
{
   if (head == nullptr)
      return;

   LinkedList::deleteZerosFromEndofTheList(head->next);

   if (head && head->next && head->next->root == 0 && head->next->next == nullptr)
   {
      delete head->next;
      head->next = nullptr;
   }
}

ostream& operator<<(ostream& output, BCD& bcd)
{
   bcd.printBCD(output);
   return output;
}

istream& operator>>(istream& input, BCD& bcd)
{
   bcd.populateBCD(input);
   return input;
}
