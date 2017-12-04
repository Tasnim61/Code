#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
   this->head = nullptr;
   size = 0;
}

void LinkedList::addLast(string before, string after)
{
   if (!head)
      this->head = new Node(before, after);
   else
   {
      Node* current =this->head;
      int count = this->size - 1;
      while (current->next != nullptr)
      {
         current = current->next;
      }
      current->next = new Node(before, after);
   }
}