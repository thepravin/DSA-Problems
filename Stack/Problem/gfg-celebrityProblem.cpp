// GFG - the Celebrity Problem

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int celebrity(vector<vector<int>>&M,int n)
{
    stack<int>st;

    // Step 1: put all person in stack
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // Step 2: discard method, to get might be celebrit
    while (st.size()!=1)
    {
        int a=st.top(); st.pop();
        int b=st.top();st.pop();

        // if a knows b
        if (M[a][b])
        {
            // a is not celebrity , b might be celebrity
            st.push(b);
        }else{
            // b is not celebrity, a might be 
            st.push(a);
        }

        
    }

    // Step 3: Check that single person is actual celebrity
    int mightCelebrity = st.top(); st.pop();

    // Step 4:
    // celebrity should not know anyone
    for (int i = 0; i < n; i++)
    {
        if (M[mightCelebrity][i]!=0)
        {
            return -1;
        }
        
    }

    // everyone know celebrity
    for (int i = 0; i < n; i++)
    {
        // celebrity know celebrity is 0 i.e 
        if (M[i][mightCelebrity]==0 && i != mightCelebrity)
        {
            return -1;
        }
        
    }
    
    
    return mightCelebrity;
    
}


int main()
{
    int n =3;
    vector<vector<int>> m = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    cout<<celebrity(m,n)<<endl;
}