#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}
int main(){
    vector<int>  nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << findKthLargest(nums, k) << endl;
    return 0;
}