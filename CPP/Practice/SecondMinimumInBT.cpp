/*
*Tasnim Bashar
*Given a non-empty special binary tree consisting of nodes with the non-negative value, where 
*each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then
*this node's value is the smaller value among its two sub-nodes.
*Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.
*If no such second minimum value exists, output -1 instead.
*Input:
    2
   / \
  2   5
 / \
5   7
*Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<sstream>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   
};

class Solution {
public:
   int findSecondMinimumValue(TreeNode* root) {
      if (!root) return -1;
      int ans = minval(root, root->val);
      return ans;
   }
private:
   int minval(TreeNode* p, int minimim) {
      if (p == nullptr) return -1;
      if (p->val != minimim) return p->val;

      int left = minval(p->left, minimim);
      int right = minval(p->right, minimim);

      if (left == -1 && right == -1)
         return -1;
      if (left == -1) return right;
      if (right == -1) return left;
      return min(left, right);
   }
};

void trimLeftTrailingSpaces(string &input) {
   input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
      return !isspace(ch);
   }));
}

void trimRightTrailingSpaces(string &input) {
   input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
      return !isspace(ch);
   }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
   trimLeftTrailingSpaces(input);
   trimRightTrailingSpaces(input);
   input = input.substr(1, input.length() - 2);
   if (!input.size()) {
      return nullptr;
   }

   string item;
   stringstream ss;
   ss.str(input);

   getline(ss, item, ',');
   TreeNode* root = new TreeNode(stoi(item));
   queue<TreeNode*> nodeQueue;
   nodeQueue.push(root);

   while (true) {
      TreeNode* node = nodeQueue.front();
      nodeQueue.pop();

      if (!getline(ss, item, ',')) {
         break;
      }

      trimLeftTrailingSpaces(item);
      if (item != "null") {
         int leftNumber = stoi(item);
         node->left = new TreeNode(leftNumber);
         nodeQueue.push(node->left);
      }

      if (!getline(ss, item, ',')) {
         break;
      }

      trimLeftTrailingSpaces(item);
      if (item != "null") {
         int rightNumber = stoi(item);
         node->right = new TreeNode(rightNumber);
         nodeQueue.push(node->right);
      }
   }
   return root;
}

int main() {
   string line;
   while (getline(cin, line)) {
      TreeNode* root = stringToTreeNode(line);

      int ret = Solution().findSecondMinimumValue(root);

      string out = to_string(ret);
      cout << out << endl;
   }
   return 0;
}