#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>


int main()
{

    // creation
    unordered_map<string, int> m;

// insertion
    // 1
    pair<string, int> p = make_pair("pravin", 3);

    // 2
    pair<string, int> q("home", 2);

    // 3
    m["city"] = 2;
    cout<<m["city"]<<endl;

    // what will happen ???
    m["city"] = 5; // if key is present then update value
    cout<<m["city"]<<endl;


    return 0;
}