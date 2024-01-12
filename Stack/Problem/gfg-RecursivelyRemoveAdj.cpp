
// GFG - recursively remove all adjacent string

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string rremove(string s) {
    // code here
        string new_str ;
        int i = 0 ;
        int flag = 0 ;
        while(i<s.size()) {
            if(s[i]==s[i+1]) {
                while(s[i]==s[i+1]) {
                i++ ;
                flag = 1 ;
                }
            }
            else new_str += s[i] ;
            i++ ;
        }
        
        if(flag != 0) return rremove(new_str) ;
        return new_str ;
    
        
}

int main() {
    // Test cases
    cout << rremove("geeksforgeek") << endl;  // Output: "gksforgk"
    cout << rremove("abccbccba") << endl;     // Output: ""
    
    return 0;
}
