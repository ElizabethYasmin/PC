
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>

using namespace std;

bool comparar(pair<int,int> &a, pair<int,int> &b){
    return (a.first < b.first);
}

void threeSum(vector<int> &nums){
    int n=nums.size();
    vector<vector<int>> sol;

    sort(nums.begin(), nums.end());

    int i,j,k;
    for(i=0; i<n; i++){
        j=i+1; k=n-1;
        while(j<k){
            if((nums[j] + nums[k]) == -1*nums[i]){
                vector<int> aux;
                aux.push_back(nums[i]);
                aux.push_back(nums[j]);
                aux.push_back(nums[k]);

                sol.push_back(aux);
                break;
            }
            else if((nums[j] + nums[k]) > -1*nums[i]) k--;
            else if((nums[j] + nums[k]) < -1*nums[i]) j++;
        }
    }
    for(i=0; i<sol.size(); i++){
        for(j=0; j<sol[i].size(); j++) cout << sol[i][j] << " ";
        cout << endl;
    }

}


//Entrada:  [-1,0,1,2,-1,-4]
//Salida: [[-1,-1,2],[-1,0,1]]

int main(){
    vector<int> v = {-1,0,1,2,-1,-4};
    threeSum(v);
    return 0;
}