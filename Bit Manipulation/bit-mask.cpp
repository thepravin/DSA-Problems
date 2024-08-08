
// bit masking

#include <iostream>
using namespace std;

int getIthBit(int num, int i)
{
    /* after adding i zeros to right of 1
       let, i=3 so, 1000 in binary it is 8
     cout<<"digit : "<<mask<<endl; */
    int mask = 1 << i;
    int ans = num & mask; // 1&1 = 1
    if (ans == 0)
        return 0;
    else
        return 1;
}

int setIthBit(int num, int i)
{
    int mask = 1 << i;
    int ans = num | mask; // 0|1 = 1 , 1|0 = 1 , 1|1 = 1 , 0|0 = 0
    return ans;
}

int clearithBit(int num, int i)
{
    int mask = ~(1 << i); // convert all 0 to one and only that bit which change convert into 1
    int ans = num & mask; // 1&1 = 1 otherwise 0
    return ans;
}

// O(logN)
int countSetBit(int num)
{
    int count = 0;
    while (num != 0)
    {
        int lastBit = num & 1;
        if (lastBit == 1)
        {
            count++;
        }
        // right shift => remove last bit
        num = num >> 1;
    }
    return count;
}

int countSetBitFast(int n)
{
    int count = 0;
    while (n != 0)
    {
        // remove last set bit => (n & (n-1))
        n = (n & (n - 1));
        count++;
    }
    return count;
}

int main()
{
    int ans = getIthBit(10, 3);
    cout << "Get bit : " << ans << endl;

    int ans2 = setIthBit(10, 2); // or change bit
    cout << "After setting bit : " << ans2 << endl;

    int ans3 = clearithBit(10, 1);
    cout << "After clearing bit : " << ans3 << endl;

    int ans4 = countSetBit(8); // count all 1
    cout << "Count set bit : " << ans4 << endl;
}