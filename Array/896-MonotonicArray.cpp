// Leet code - 896

#include <iostream>
#include<vector>
using namespace std;

  bool isMonotonic(vector<int>& nums) {
  bool increasing = true;
  bool decreasing = true;


for(int i=1;i<nums.size();i++){
  // condition for not increasing
  if(nums[i] < nums[i-1]){
  increasing = false;
  break;
  }
}

for(int i=1;i<nums.size();i++){
  // condition for not decreasing
  if(nums[i] > nums[i-1]){
  decreasing = false;
  break;
  }
}

      // true is any one is true
      return increasing || decreasing;
  }

int main() {

vector<int> nums {1,2,4,3};

bool ans = isMonotonic(nums);

if(ans){
  cout<<"true";
}else{
  cout<<"false";
}


return 0;
}