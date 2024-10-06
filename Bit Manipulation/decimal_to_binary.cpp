
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Decimal : ";
    cin >> n;

    string binary = "";

    while (n != 0)
    {
        binary = to_string(n & 1) + binary; // Build binary string
        n = n >> 1; // right shift
    }

    cout << binary << endl;

    return 0;
}