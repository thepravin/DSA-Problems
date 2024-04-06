#include <stack>
#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if(s.size() == 0) return s;

        stack<int> st;
        vector<bool> toRemove(s.size(), false); // Initialize a vector to keep track of characters to remove

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')' && !st.empty()) {
                st.pop();
            } else if(s[i] == ')') {
                toRemove[i] = true; // Mark ')' characters for removal
            }
        }

        // Mark '(' characters for removal for which there are no matching ')'
        while(!st.empty()) {
            toRemove[st.top()] = true;
            st.pop();
        }

        // Construct the final string by skipping characters marked for removal
        string result = "";
        for(int i = 0; i < s.size(); i++) {
            if(!toRemove[i]) {
                result += s[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "))((";
    cout << sol.minRemoveToMakeValid(s) << endl;
    return 0;
}
