#include<iostream>
#include<algorithm>
using namespace std;

struct BSTNode
{
   int data;
   BSTNode *left;
   BSTNode* right;

   BSTNode(int val) :data(val), left(nullptr), right(nullptr) {}
};
bool isBSTHelper(BSTNode* root, int* min, int* max)
{
   if (root == nullptr)
      return true;
   if (min != nullptr && root->data <= *min || max != nullptr && root->data > *max)
      return false;
   if(!isBSTHelper(root->left, min, &root->data) || !isBSTHelper(root->right, &root->data, max))
      return false;
   return true;
}

bool isBST(BSTNode* root)
{
   if (isBSTHelper(root, nullptr, nullptr))
      return true;
   return false;
}

int main()
{
   BSTNode* root1 = new BSTNode(10);
   root1->left = new BSTNode(8);
   root1->right = new BSTNode(15);
   root1->left->left = new BSTNode(7);
   root1->left->right = new BSTNode(9);
   root1->right->right = new BSTNode(17);
   root1->right->left = new BSTNode(12);

   BSTNode* root2 = new BSTNode(10);
   root2->left = new BSTNode(8);
   root2->right = new BSTNode(15);
   root2->left->right = new BSTNode(17);

   if (isBST(root1))
      cout << "BST" <<endl;
   else
      cout << "not BST"<< endl;

   if (isBST(root2))
      cout << "BST"<<endl;
   else
      cout << "not BST"<<endl;
   return 0;
}