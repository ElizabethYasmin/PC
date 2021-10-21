
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;


    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); ++i){
            auto it = hash.find(target - nums[i]);
            if(it != hash.end()){
                ans[0] = it->second;
                ans[1] = i;
                break;
            }else{
                hash[nums[i]] = i;
            }
        }
        return ans;
    }


int main()
{
    vector<int> ans,numbers={5,6,7,8,9,10};
    int target=15;
    ans=twoSum(numbers,target);
    for(auto iter=ans.begin();iter!=ans.end();iter++)
    	cout<<*iter<<endl;
    system("pause");
    return 0;
    //entrada -> {5,6,7,8,9,10}
    //entrada -> 15
    //salida -> 2  3  
}