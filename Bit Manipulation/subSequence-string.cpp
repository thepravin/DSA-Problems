#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string>findSubSequence(string str){
    vector<string>ans;
    int n = str.length();

    // (1 << n) = 2^n
    for(int num = 0; num< (1<<n);num++){
        string temp = "";
        // create subsequence string in this temp string
        for(int i=0; i<n ; i++){
            char ch = str[i];
            if(num & (1 << i)){
                // for non-zero value -> include current char
                temp.push_back(ch);
            }
        }
        if(temp.length()>=0){
            ans.push_back(temp);
        }
    }
    return ans;
}

int main()
{
    string str = "ab";

    vector<string>ans = findSubSequence(str); 

    for(auto& i : ans){
        cout<<i<<endl; // " " is also sub string
    }
}