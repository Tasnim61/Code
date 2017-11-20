#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void printLastKLine(string filename, const int k)
{
    ifstream file(filename);
    if(!file)
        return;
        
    int size = 0;
    string str[k];

    while(file.peek() != EOF)
    {
        getline(file, str[size % k]);
        size++;
    }

    int start = (size > k)?  (size % k) : 0;
    for(int i = start; i < k; i++)
    {
        if(size == i)
        break;
        cout << str[i]<< endl;
    }

    if(size > k)
    {
        for(int i = 0; i < start;i++)
        {
            cout << str[i] << endl;
        }
    }
}

int main()
{
    printLastKLine("printLastKLineInput.txt", 7);
    return 0;
}