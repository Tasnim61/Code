/* Tasnim Bashar
*Given two integers n and k, you need to construct a list which contains n different 
*positive integers ranging from 1 to n and obeys the following requirement: Suppose 
*this list is [a1, a2, a3, ... , an], then the list will be-
*[|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
*If there are multiple answers, print any of them.*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
   vector<int> constructArray(int n, int k) {
      int l = 1, r = k + 1;
      vector<int> ans;
      while (l <= r) {
         ans.push_back(l++);
         if (l <= r) ans.push_back(r--);
      }
      for (int i = k + 2; i <= n; i++)
         ans.push_back(i);
      return ans;
   }
};

int stringToInteger(string input) {
   return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
   if (length == -1) {
      length = list.size();
   }

   if (length == 0) {
      return "[]";
   }

   string result;
   for (int index = 0; index < length; index++) {
      int number = list[index];
      result += to_string(number) + ", ";
   }
   return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
   string line;
   while (getline(cin, line)) {
      int n = stringToInteger(line);
      getline(cin, line);
      int k = stringToInteger(line);

      vector<int> ret = Solution().constructArray(n, k);

      string out = integerVectorToString(ret);
      cout << out << endl;
   }
   return 0;
}