#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; 
        int sum = 0; 
        int subLength = 0; 
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            for (int j = i; j < nums.size(); j++) { 
                sum += nums[j];
                if (sum >= s) { 
                    subLength = j - i + 1; 
                    result = result < subLength ? result : subLength;
                    break; 
                    
                }
            }
        }
         return result == INT32_MAX ? 0 : result;
    }

//Entrada: [2, 4, 2, 5, 1]
//Entrada: S: 7
//Salida: 2

int main(){
    vector<int> ar={2, 4, 2, 5, 1};
    int S=7;
   cout<<minSubArrayLen(S,ar);
}







