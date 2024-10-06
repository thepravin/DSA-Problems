/*

Joseph is learning digital logic subject which will be for his next semester. He usually tries to solve unit assignment problems before the
lecture. Today he got one tricky question. The problem statement is "A positive integer has been given as an input. Convert decimal valuele
to binary representation. Toggle all bits of it after the most significant bit including the most significant bit. Print the positive integer
value after toggling all bits".
Constrains-
Example 1:
Input :
10 - Integer
Output :
5 -> result- Integer

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Decimal : ";
    cin >> n;

    // Step 1: Convert to binary
    string binary = "";
    int original = n;

    while (n != 0)
    {
        binary = to_string(n & 1) + binary; // Build binary string
        n = n >> 1;
    }
   

    // Step 2 :  Toggle
    for (int i = 0; i < binary.size(); i++)
    {
        binary[i] = binary[i] ^ 1;
    }

    // Step 3 : convert binary to int
    int res = stoi(binary,nullptr,2);
    cout<<res<<endl;
   

    return 0;
}