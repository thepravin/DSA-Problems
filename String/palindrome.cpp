//  eg . => non,lol,nitin right to left same
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{

    return 0;
}

/*
// timeCom = O(n) spacecom = O(n)

void palindrome(char name[])
{
    int start = 0;
    int n = strlen(name);
    int end = n - 1;

    while (start <= end)
    {
        int temp = name[start];
        name[start] = name[end];
        name[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    char name[100];
    cin.getline(name, 100);

    char newName[100];
    strcpy(newName, name);

    palindrome(name);
    if (strcmp(name, newName) == 0)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}

*/
