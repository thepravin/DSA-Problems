
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string binary = "1010";

    for (int i = 0; i < binary.size(); i++)
    {
        binary[i] = binary[i] ^ 1;
    }

    cout << binary << endl;

    return 0;
}