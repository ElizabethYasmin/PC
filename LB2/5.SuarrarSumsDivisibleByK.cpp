
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <unordered_map>
using namespace std;


int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> count;
        count[0] = 1;
        int prefix = 0, result = 0;
        for (const auto& a : A) {
            prefix = (prefix + (a % K + K)) % K;
            result += count[prefix]++;
        }
        return result;
}

int main(){
    //Input: nums = [4,5,0,-2,-3,1], k = 5
    //Output: 7
    //Explanation: There are 7 subarrays with a sum divisible by k = 5: [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

     vector<int> v{4,5,0,-2,-3,1};
     int k;
     cout<<"K ->";cin>>k;
     cout<<subarraysDivByK(v,k);
 }