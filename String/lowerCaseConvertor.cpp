// conver into LowerCase
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

void upperCaseConvert(char name[])
{
    for (int i = 0; i < strlen(name); i++)
    {
        name[i] = name[i] + 32; // or name[i]+'a'-'A'
    }
}

int main()
{
    char name[100] = "PRAVIN";
    upperCaseConvert(name);
    cout << name << endl;

    return 0;
}