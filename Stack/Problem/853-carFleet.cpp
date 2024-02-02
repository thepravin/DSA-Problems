// LeetCode 853 : Car Fleet

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Car
{
public:
    int pos, speed;

    Car(int p, int s) : pos(p), speed(s){};

   
};

 static bool myComp(Car &a, Car &b)
    {
        return a.pos < b.pos;
    }

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    // Step 1: sort position
    /*
    - create own data structur (class)
    -which can have position ans speed and this two combine create one car

     */
    vector<Car> cars;
    for (int i = 0; i < position.size(); ++i)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }
    sort(cars.begin(), cars.end(),myComp);

    // Step 2: create time array
    stack<float> st;
    for (auto car : cars)
    {
        float time = (target - car.pos) / ((float)car.speed);
        while (!st.empty() && time >= st.top())
        {
            st.pop();
        }
        st.push(time);
    }

    return st.size();
}

int main()
{
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    cout << carFleet(target, position, speed) << endl;
}