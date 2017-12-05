/*In order successor in Binary Tree*/
#include<iostream>
using namespace std;

struct BinaryNode
{
   int data;
   BinaryNode *left;
   BinaryNode* right;

   BinaryNode(int val) :data(val), left(nullptr), right(nullptr) {}
};
BinaryNode* successorHelper(BinaryNode* root,BinaryNode* n, bool& isFound)
{

   if (root == nullptr)
      return nullptr;

   BinaryNode* temp = successorHelper(root->left, n, isFound);
   if(temp == nullptr && isFound == true)
      return root;
   else if (temp != nullptr && isFound == true)
      return temp;
   else
   {
      if (root->data == n->data)
      {
         isFound = true;
         return nullptr;
      }
      else
         return successorHelper(root->right, n, isFound);
   }
}

BinaryNode* getLeftMost(BinaryNode* root)
{
   if (root == nullptr)
      return root;
    BinaryNode* temp = getLeftMost(root->left);
    if (temp == nullptr)
       return root;
    else
       return temp;
}

BinaryNode* successor(BinaryNode* root, BinaryNode* n)
{
    bool isFound = false;
    if (n->right != nullptr)
      return getLeftMost(n->right);
    else
      return successorHelper(root,n, isFound);
}

void printBST(BinaryNode* current)
{
   if (current == nullptr)
      return;

   printBST(current->left);
   cout << current->data << " ";
   printBST(current->right);

}

int main()
{
   BinaryNode* root1 = new BinaryNode(10);
   root1->left = new BinaryNode(8);
   root1->right = new BinaryNode(15);
   root1->left->left = new BinaryNode(7);
   root1->left->right = new BinaryNode(9);
   root1->right->right = new BinaryNode(17);
   root1->right->left = new BinaryNode(12);
   cout << "In order treversal of Binary Tree: ";
   printBST(root1);
   cout << endl;

   BinaryNode* n = successor(root1, root1->left->right);
   cout << "successor of 9 : " << n->data << endl;

   BinaryNode* m = successor(root1, root1->left->left);
   cout << "successor of 7 : " <<m->data << endl;

   BinaryNode* o = successor(root1, root1->right);
   cout << "successor of 15 : " << o->data << endl;

   BinaryNode* p = successor(root1, root1->right->right);
   cout << "successor of 17 : ";
   if (p != nullptr)
      cout << p->data << endl;
   else
      cout << "nullptr" << endl;

   return 0;
}
