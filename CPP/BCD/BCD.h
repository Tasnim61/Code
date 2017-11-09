/*@file BCD.h
*Tasnim Bashar
* 1 November, 2017
*header file
*/
#pragma once
#include<iostream>
using namespace std;

struct Node
{
   int data;
   Node* next;

   Node();
   Node(int);
};

class BCD
{
private:
   Node* head;
   bool isPositive;

   void setList(Node*);
   void deleteNodeList();
   void populateFromString(string);

public:

   BCD();
   BCD(int);
   BCD(string);
   ~BCD();

   BCD(const BCD& b);
   BCD& operator=(const BCD& b);

   bool operator <(const BCD& bcd);
   bool operator ==(const BCD& bcd);

   BCD operator +(const BCD& bcd);
   BCD operator -(const BCD& bcd);
   BCD operator *(const BCD& bcd);
   BCD operator /(const BCD& bcd); 

   operator int() const;

   void populateBCD(istream& input);
   void printBCD(ostream& output);
};

class LinkedList
{
public:
   // linked list functions
   static void addToFront(Node*&, int);
   static Node* reverseList(Node* head);
   static int compareTwoList(const Node* a, const Node* b);
   static void deleteZerosFromEndofTheList(Node*);
   static Node* sum(Node* a, const Node* b);
   static Node* sub(const Node* a, const Node* b);
   static Node* copyNodeList(const Node*);
   static Node* getTail(Node* head);
};

ostream& operator<<(ostream& output, BCD& b);
istream& operator>>(istream& input, BCD& bcd);
