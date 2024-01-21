
// first non repeating character in stream

#include <iostream>
#include <queue>
using namespace std;

//************************* GFG *********************
string FirstNonRepeating(string A)
{
    int freq[26] = {0}; // create 26 size array for storing freq of char.
    queue<char> q;
    string ans = " ";
    
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // increase freq
        freq[ch - 'a']++;

        // push into q
        q.push(ch);

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1) // repeated char
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string A = "aabc";

    cout << FirstNonRepeating(A) << endl;
    return 0;
}