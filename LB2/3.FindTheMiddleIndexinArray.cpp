#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
using namespace std;



 int findMiddleIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
		int prefix = 0;  
        for (int i = 0; i < nums.size(); ++i) {
            if (2*prefix == total - nums[i]) return i; 
            prefix += nums[i]; 
        }
        return -1; 
}   
 int main(){
     vector<int> v{2,3, -1, 8 , 4};
     cout<<findMiddleIndex(v);
 }