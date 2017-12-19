/*Some courses may have prerequisites, for example to take course 0 you have to first take
course 1,which is expressed as a pair: [0,1]
Given the  list of prerequisite pairs, return the ordering of courses you should take to
finish all courses.There may be multiple correct orders, you just need to return one of them.
If it is impossible to finish all courses, return an empty array.For example:
i/p: [[1,0]]   o/p:[0,1]
i/p:[[1,0],[2,0],[3,1],[3,2]]   o/p:[0,1,2,3]or [0,2,1,3].*/

#include<iostream>
#include<vector>
#include<map>


using namespace std;


bool isCycle(vector<vector<int>>& graph, int VIn, vector<int> & visited, vector<int> & result)
{
   if (visited[VIn] == 0)//if state is visiting
      return true;
   if (visited[VIn] == -1)//if state is unvisited
   {
      visited[VIn] = 0;// mark as visiting
      for (int i = 0; i < graph[VIn].size(); i++)
      {
         if (isCycle(graph, graph[VIn][i], visited, result))
            return true;
      }
   }
   if (visited[VIn] != 1) //if vertex is not visited
   {
      result.push_back(VIn);
      visited[VIn] = 1;
   }
   return false;
}

vector<int> findOrder(vector<pair<int, int>>& prerequisites, int n)
{
   vector<vector<int>> graph(n);

   for (int i = 0; i < prerequisites.size(); i++)
   {
      vector<int> p;
      graph[prerequisites[i].first].push_back(prerequisites[i].second);
   }

   vector<int> visited(n, -1);
   vector<int>result;
   //Iterate over an unordered_map using range based for loop
   for (int i = 0; i < n; i++)
   {
      if (isCycle(graph, i, visited, result))
         return {};
   }
   //reverse(result.begin(), result.end());
   return result;
}

int main()
{
   vector<pair<int, int>> pr;
   pr.push_back(make_pair(1, 0));
   pr.push_back(make_pair(2, 0));
   pr.push_back(make_pair(3, 1));
   pr.push_back(make_pair(3, 2));

   vector<int>res = findOrder(pr, 4);

   for (int i = 0; i < res.size(); i++)
   {
      cout << res[i] << " ";
   }

   cout << endl;

   vector<pair<int, int>> pr2;
   pr2.push_back(make_pair(1, 0));
   pr2.push_back(make_pair(0, 2));

   vector<int>res2 = findOrder(pr2, 3);

   for (int i = 0; i < res2.size(); i++)
   {
      cout << res2[i] << " ";
   }

   return 0;
}