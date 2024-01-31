// Leet Code - 394 String Decoding

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string decodeString(string s)
{
    stack<string> st;

    for (auto ch : s)
    {
        if (ch == ']')
        {
            // Step 1 : finding repeat string
            string repeateString = "";
            while (!st.empty() && st.top() != "[")
            {
                string top = st.top();
                repeateString += top;
                st.pop();
            }

            // for last breaket
            st.pop();

            // Step 2: finding how may times repeat
            string numString = "";
            while (!st.empty() && isdigit(st.top()[0])) //This checks whether the first character of the string at the top of the stack is a digit. when "bcbc" is push in stack
            {
                numString += st.top();
                st.pop();
            }
            reverse(numString.begin(), numString.end());
            int n = stoi(numString); // string to int    // >>>>... yahapar galti hogi

            // Step 3: final decoding
            string currentString = "";
            while (n--)
            {
                currentString += repeateString;
            }

            st.push(currentString);
        }
        else
        {
            string temp(1, ch);    // >>>>... yahapar galti hogi  // convert single char to string 
            st.push(temp);
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    string s = "3[a]2[bc]";

    cout << decodeString(s) << endl;

    return 0;
}

/* 

Certainly! In the provided C++ code, the line `string temp(1, ch);` is creating a string object named `temp` with a length of 1 and initializing it with the character `ch`.

Let's break down the syntax:

- `string`: This is the C++ standard string class, which is part of the Standard Template Library (STL).

- `temp`: This is the name given to the string object.

- `(1, ch)`: This is the constructor of the string class. The parameters inside the parentheses are used to initialize the string. In this case, it's initializing the string with a length of 1 and setting its content to the character `ch`.

So, essentially, the line `string temp(1, ch);` is creating a string object `temp` containing only the character `ch`. It's a way to convert a single character into a string representation with a length of 1. This is commonly done when you want to treat a character as a string or concatenate it with other strings. In this specific code, it's used to push each character onto a stack (`st`) for further processing in the decoding algorithm.

 */