
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
     vector<int> v{4,5,0,-2,-3,1};
     int k;
     cout<<"K ->";cin>>k;
     cout<<subarraysDivByK(v,k);
 }