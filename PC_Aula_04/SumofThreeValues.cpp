#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;

 
int threeSum(vector<int>& nums, int target){
    sort(nums.begin(),nums.end());
    int distance =INT_MAX;
    int flag =1;
    for(int i=0;i<nums.size()-2;++i){
        int j=i+1,k=nums.size()-1;
        while(j<k){
            int tmp=nums[i]+nums[j]+nums[k]-target;
            if(tmp==0) return target;
            tmp>0 ? --k : ++j;
            if(abs(tmp)<distance){
                flag=tmp<0 ? 1 : -1;
                distance=abs(tmp);
            }


        }
    }
    return target +flag*distance;
}
