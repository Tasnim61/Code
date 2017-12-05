#include<iostream>
#include<algorithm>
using namespace std;

struct BSTNode
{
   int root;
   BSTNode *left;
   BSTNode* right;

   BSTNode(int val) :root(val), left(nullptr), right(nullptr) {}
};

int checkHeight(BSTNode* root)
{
   if (root == nullptr)
      return -1;

   int left = checkHeight(root->left);
   if (left == INT_MIN)    //found error pass it up
      return INT_MIN;

   int right = checkHeight(root->right);
   if (right == INT_MIN)    //found error pass it up
      return INT_MIN;

   int diff = left - right;
   if (abs(diff) > 1)
      return INT_MIN;    //found error pass it back
   else
      return max(left, right) + 1;
}

bool isBalanced(BSTNode* root)
{
   return checkHeight(root) != INT_MIN;
}

int main()
{
   BSTNode* l = new BSTNode(8);
   BSTNode* r = new BSTNode(15);
   BSTNode* root = new BSTNode(10);
   root->left = l;
   root->right = r;
   
   if (isBalanced(root))
      cout << "Balanced";
   else
      cout << "not balanced";
   return 0;
}