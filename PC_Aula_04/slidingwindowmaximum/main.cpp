#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1)return vector<int>(nums.begin(),nums.end()-k+1);
        
        deque<int> q;
        vector<int> res;
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            while(!q.empty() && i-q.front()>=k) q.pop_front();
            q.push_back(i);
            if(i>=k-1)   res.push_back(nums[q.front()]);
           
        }
        
        return res;
        
    
    }

//Entrada: [1, 3, -1, -3, 5, 3, 6, 7]
//Entrada: k = 3
//Salida: [3, 3, 5, 5, 6, 7]

int main(){
    vector<int> ar={1, 3, -1, -3, 5, 3, 6, 7};
    int K=3;
    //maxSlidingWindow(ar,K);
   
    for (int i = 0; i < maxSlidingWindow(ar,K).size(); ++i) {
        cout << maxSlidingWindow(ar,K)[i] << " , ";
    }
    cout << endl;
  
}
