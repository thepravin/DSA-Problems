#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // array will be sorted
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << "Finding 5 => " << binary_search(v.begin(), v.end(), 5) << endl;

    // index from starting is +ve and is  -//- - v.end() gives -ve means index from end
    cout << "lower bound  => " << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl; 
    

    cout << "upper bound  => " << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;

}