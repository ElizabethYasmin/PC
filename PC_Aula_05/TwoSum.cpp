#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
typedef vector<int> VectorI;
typedef unordered_map<int, int> ii;

VectorI twoSum(VectorI& nums, int target){
    ii tmp;
    for(int i = 0; i < nums.size(); i++){
        if(tmp.count(target - nums[i])){
            return {tmp[target - nums[i]], i};
        }
        tmp[nums[i]] = i;
    }
    return {-1, -1};
}
//Entrada: Input: nums = [2,7,11,15], target = 9

//Salida : [0,1]

//Salida: Because nums[0] + nums[1] == 9, we return [0, 1].
int main(){
    VectorI nums = {2, 7, 11, 15};
    int target = 9;

    VectorI solution = twoSum(nums, target);
    cout << solution[0] << " " << solution[1] << endl;

    return 0;
}