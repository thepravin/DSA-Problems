// string subsequences

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;

void subSequences(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << output << endl;
        return;
    }

    // exclude
    subSequences(str, output, i + 1);

    // include
    output.push_back(str[i]);
    subSequences(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = " ";
    int i = 0;
    subSequences(str, output, i);

    return 0;
}