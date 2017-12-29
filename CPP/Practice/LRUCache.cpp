/* Tasnim Bashar
*LRU Cache Implementation
*/
#include <iostream>
#include<unordered_map>
#include<list>
#include<utility>

using namespace std;

class LRU {
private:
   list<int> q;
   unordered_map<int, pair<list<int>::iterator, int>> mapp;
   int capacity;
public:
   LRU(int cap) :capacity(cap) {}

   void add(int page, int data) {

      //if not found in cache
      if (mapp.find(page) == mapp.end()) {
         //if cache size is full
         if (q.size() == capacity) {
            // erase the last key
            mapp.erase(q.back());
            q.pop_back();
         }
         //now cache has free space
         q.push_front(page);
         pair<list<int>::iterator, int> p(q.begin(), data);
         mapp.insert({ page, p });
      }
      else {
         //found in cache
         list<int>::iterator it = mapp[page].first;
         q.erase(it);
         q.push_front(page);
         pair<list<int>::iterator, int> p(q.begin(), data);
         mapp[page] = p;
      }
   }

   int get(int page) {
      int value;
      if (mapp.find(page) != mapp.end()) {
         list<int>::iterator it = mapp[page].first;
         int data = mapp[page].second;
         q.erase(it);
         q.push_front(page);
         pair<list<int>::iterator, int> p(q.begin(), data);
         mapp[page] = p;
         return data;
      }
      return -1;
   }

   void displayCache() {
      cout << endl;
      if (q.empty()) {
         cout << "Cache is Empty" << endl;
         return;
      }

      for (auto it = q.begin(); it != q.end(); ++it)
         cout << (*it) << " ";
      cout << endl;
   }
};

int main() {
   LRU cache(2);

   cache.add(1,98);
   cache.add(2,54);
   cache.displayCache();
   cout << cache.get(1) << endl;       // returns 98 (found)
   cache.displayCache();

   cache.add(3,567);
   cout << cache.get(2) << endl;       // returns -1 (not found)
   cache.displayCache();

   cache.add(4,98);
   cache.displayCache();

   cout << cache.get(1) << endl;       // returns -1 (not found)
   cout << cache.get(3) << endl;       // returns 567
   cache.displayCache();
   cout << cache.get(4) << endl;       // returns 98
   cache.displayCache();
   return 0;
}