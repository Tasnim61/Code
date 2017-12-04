#pragma once
#include<string>
using namespace std;

struct Node
{
   string before;
   string after;
   Node *next;

   Node(string befor, string after) {
      this->before = befor;
      this->after = after;
      this->next = nullptr;
   }
};

class LinkedList
{
   int size;
public:
   Node* head;
   LinkedList();
   void addLast(string befor, string after);
};