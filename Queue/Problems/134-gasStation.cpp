
// LeetCode 134 : gas station

#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // kitna gas kam h
    int deficit=0;
    // kitna gas h
    int balance =0;
    // kahase chlu kare
    int start =0;

    for (int i = 0; i < gas.size(); i++)
    {
        balance = balance+gas[i]-cost[i];

        if (balance <0)
        {
            // ********** yar par galti hogi *****************
            deficit = deficit+balance; // ab tak ka total deficit
            start = i+1 ; // next index
            balance=0; // firse chalu
        }
        
    }

    if (deficit+balance >=0)
    {
        return start; // you have to return index of start circuit
    }else{
        return -1;
    }
    
    
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout << canCompleteCircuit(gas, cost) << endl;
}