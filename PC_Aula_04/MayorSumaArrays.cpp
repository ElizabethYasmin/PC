
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;


 int maxSubArray(vector<int>& nums){
     int res=nums[0];
     int n=nums.size();
     for(int i=1;i<n;i++){
         nums[i] += nums[i-1]>0 ?nums [i-1]:0;
         res=res>nums[i] ? res:nums[i];
     }
     return res;
 }
int main(){
vector<int> numbers={1, -2, 3, 10, -4, 7, 2, -5};
cout<<maxSubArray(numbers);

//entrada -> {1, -2, 3, 10, -4, 7, 2, -5}
//salida -> 18 
}
