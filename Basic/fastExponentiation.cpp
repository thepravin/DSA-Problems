
#include <iostream>
using namespace std;

int fastExponentiation(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            // odd
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;  // right shift  1/2
    }
    return ans;

} // O(log b)

int main()
{
    int a = 5;
    int b = 4;

    int ans = fastExponentiation(a, b);

    cout << ans << endl;

    return 0;
}