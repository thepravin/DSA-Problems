#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int pref (char ch){
    if(ch=='^')return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-')return 1;
    else 
        return -1;
}

string infixToPrefix(string exp){
    stack<char>st;

    // 1. reverse and make postfix express
        // Type 1 : reverse
        reverse(exp.begin(),exp.end());
        cout<<"EXP : "<<exp<<endl;
       
        string postfix;
        for(int i=0;i<exp.length();i++){
            char ch = exp[i];          
            if(isalpha(ch)){
                postfix.push_back(ch);
            }else{
                while (!st.empty()&&pref(ch)<=pref(st.top()))
                {
                   postfix.push_back(st.top());
                   st.pop();
                }
                st.push(ch);                
            }
        }

        while (!st.empty())
        {
            postfix.push_back(st.top());
            st.pop();
        }
        cout<<"Postfix : "<<postfix<<endl;
       // 2. postfix to prefix
        // so, reverse expression
        reverse(postfix.begin(),postfix.end());
        string prefix = postfix;
 

        return prefix;        

}

int main(){
    string exp = "x+y*z/w+u";

    string ans = infixToPrefix(exp);

    cout<<"Infix : "<<exp<<endl;
    cout<<"Prefix : "<<ans<<endl;

    return 0;
}