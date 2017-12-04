#include<iostream>
#include<iomanip>
#include<assert.h>
#include<string>
#include"BST.h"
#include"Concordance.h"
#include <fstream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
   Concordance c;

   //check mutator and accessor function
   c.setKey("love");
   c.setValues("I", "coding");
   cout << "Key is : " << c.getKey();

   //check output operator overloading
   cout << c;
   c.setValues("I", "C++");
   cout << c;

   Concordance d;
   d.setKey("work");
   d.setValues("I", "hard");

   //check operator < overloading
   if (c < d)
      cout << "c < d: true" << endl;
   else
      cout << "c < d: false" << endl;

   //check operator == overloading
   if (c == d)
      cout << "c < d: true" << endl;
   else
      cout << "c < d: false" << endl;



   BST<int> tree1;
   tree1.insert(10);
   tree1.insert(18);
   tree1.insert(8);
   BSTNode<int>* bstNode = nullptr;
   if (tree1.find(18, bstNode))
      cout << "found";
   else
      cout << "not found";

   tree1.printBST();

   //read corpus file and set words into array
   vector<string> arrayOfWord;
   ifstream file("text.txt");
   if (file.is_open())
   {
      cout << "corpus words: " << endl;
      for (string word; file >> word; )
      {
         // converting every word of corpus into lower case
         transform(word.begin(), word.end(), word.begin(), ::tolower);

         //if there is any punctuation after the word
         int last = word.size() - 1;
         if (ispunct(word[last]))
            word.erase(last--, 1);

         //printing the words
         cout << word << endl;

         //pushing the word in the array
         arrayOfWord.push_back(word);
      }
   }

   //read stopword file and set words into BST
   BST<string> stopwordsOfBST;
   ifstream file2("stopwords.txt");
   if (file2.is_open())
   {
      for (string word; file2 >> word; )
         stopwordsOfBST.insert(word);
   }
   cout << "stop words: "<< endl;
   stopwordsOfBST.printBST();

   //store corpus word in BST
   BST<Concordance> concordanceBST;
   for (int i = 0; i < arrayOfWord.size(); i++)
   {
      string key = arrayOfWord[i];

      BSTNode<string>* stopBstNode = nullptr;
      //if corpus word is not a stop word
      if (stopwordsOfBST.find(key, stopBstNode) == false)
      {
         string before = "";
         for (int start = i - 1; start >= 0 && start >= i - 5; start--)
            before = arrayOfWord[start] + " " + before;

         string after = "";
         for (int start = i + 1; start < arrayOfWord.size() && start <= i + 5; start++)
            after = after + " " + arrayOfWord[start];

         Concordance c;
         c.setKey(key);

         BSTNode<Concordance>* conBstNode = nullptr;
         //if concordance already exists
         if (concordanceBST.find(c, conBstNode) == true)
         {
            conBstNode->value.setValues(before, after);
         }
         else
         {
            c.setValues(before, after);
            concordanceBST.insert(c);
         }
      }
   }

   concordanceBST.printBST();

   return 0;
}