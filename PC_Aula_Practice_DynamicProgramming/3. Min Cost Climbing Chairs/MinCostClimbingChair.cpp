#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minCost(vector<int>& cost) {
    int n = cost.size();
    int m = cost[0];
    vector<int> dp(n,0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++) {dp[i] = min(dp[i-1], dp[i-2]) + cost[i];}
    return min(dp[n-1], dp[n-2]);
}

int main(){
    vector<int> cost = {10, 15, 20};
    cout << minCost(cost) << endl;
    return 0;
}