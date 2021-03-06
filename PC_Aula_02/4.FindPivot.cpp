
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
using namespace std;


int pivotIndex(vector<int>& nums) {
        const auto total = accumulate(nums.begin(), nums.end(), 0);
        auto left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (left_sum == (total - left_sum - nums[i])) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
}

int main(){
     vector<int> v{1,7,3,6,5,6};
     //Input: nums = [1,7,3,6,5,6]
    //Output: 3
    //Explanation:
    //  The pivot index is 3.
    //Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    //Right sum = nums[4] + nums[5] = 5 + 6 = 11

     cout<<pivotIndex(v);
 }