#ifndef _BST
#define _BST

#include<iostream>
using namespace std;

template <class T>
struct BSTNode {
   T value;
   BSTNode<T>* left;
   BSTNode<T>* right;

   BSTNode(T val) 
   {
      this->value = val;
      this->left = nullptr;
      this->right = nullptr;
   }

   BSTNode(T val, BSTNode<T>* left, BSTNode<T>* right) 
   {
      this->value = val;
      this->left = left;
      this->right = right;
   }

   T getValue() const
   {
      return value;
   }
};

template <class T>
class BST
{
private:
   BSTNode<T>* root ;
   int size ;

   bool insertHelper(BSTNode<T> *curr, T val);
   const BSTNode<T>* findHelper(const BSTNode<T>*, T val) const;
   void printBSTHelper(BSTNode<T>* curr);

public:
   BST();
   bool insert(T val);
   bool find(T, BSTNode<T>*&) const;
   void printBST();
};

template <class T>
BST<T>::BST()
{
   this->root = nullptr;
   size = 0;
}

template <class T>
bool BST<T>::insert(T val)
{
   if (size == 0)
   {
      this->root = new BSTNode<T>(val);
   }
   else if (this->size > 0)
   {
      if (!insertHelper(this->root, val))
         return false;
   }
   else
   {
      return false;
   }

   this->size++;
   return true;
}

template <class T>
bool BST<T>::insertHelper(BSTNode<T>* curr, T val)
{
   if (curr == nullptr)
      return false;

   if (curr->value == val)
   {
      return false;
   }
   else if (curr->value < val)
   {
      if (curr->right == nullptr)
      {
         curr->right = new BSTNode<T>(val);
      }
      else
      {
         return insertHelper(curr->right, val);
      }
   }
   else 
   {
      if (curr->left == nullptr) 
      {
         curr->left = new BSTNode<T>(val);
      }
      else 
      {
         return insertHelper(curr->left, val);
      }
   }

   return true;
}

template <class T>
void BST<T>::printBST()
{
   printBSTHelper(this->root); 
}

template <class T>
void BST<T>::printBSTHelper(BSTNode<T>* curr)
{
   if (curr == nullptr)
      return;
   else
   {
      printBSTHelper(curr->left); //recursive traversal of left subtree
      cout << curr->value << endl; //process node
      printBSTHelper(curr->right); //recursive traversal of right subtree
   }
}

template< class T>
bool BST<T>::find(T value, BSTNode<T>*& n) const
{
   const BSTNode<T>* bstNode = findHelper(this->root, value);
   n = const_cast<BSTNode<T>*>(bstNode);
   if (n)
   {
      return true;
   }
   return false;
}

template< class T>
const BSTNode<T>* BST<T>::findHelper(const BSTNode<T>* curr, T val) const
{
   if (curr == nullptr || curr->value == val)
      return curr;
   if (curr->value < val)
      return findHelper(curr->right, val);
   return findHelper(curr->left, val);
}

//#include "BST.cpp"
#endif