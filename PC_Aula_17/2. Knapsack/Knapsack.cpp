#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt, int n){
    if (n == 0 || W == 0) return 0;
    if(wt[n-1] > W) return knapsack(W, val, wt, n-1);
    else
        return max(val[n-1] + knapsack(W-wt[n-1], val, wt, n-1), knapsack(W, val, wt, n-1));
}

int knapsack_aux(int W, vector<int> val, vector<int> wt, int i, vector<vector<int>> &memo){
    if(i < 0 ) return 0;
    if(memo[i][W] != -1) return memo[i][W];
    if(wt[i] > W){
        memo[i][W] = knapsack_aux(W, val, wt, i-1, memo);
        return memo[i][W];
    }
    else{
        memo[i][W] = max(val[i] + knapsack_aux(W-wt[i], val, wt, i-1, memo), knapsack_aux(W, val, wt, i-1, memo));
        return memo[i][W];
    }   
}


int knapsack_mem(int W, vector<int> &val, vector<int> &wt, int n){
    if (n == 0 || W == 0) return 0;

    vector<vector<int>> memo(n, vector<int>(W+1, -1));

    return knapsack_aux(W, val, wt, n-1, memo);
}

int knapsack_bu(int W, vector<int> &val, vector<int> &wt, int n){
    vector<vector<int>> memo(n+1, vector<int>(W+1, -1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(i == 0 || j == 0)
                memo[i][j] = 0;
            else if(wt[i-1] <= j){
                memo[i][j] = max(val[i-1] + memo[i-1][j-wt[i-1]], memo[i-1][j]);
            }
            else{
                memo[i][j] = memo[i-1][j];
            }
        }
    }

    return memo[n][W];
}


int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;
    int n = val.size();
    cout << knapsack(W, val, wt, n) << endl;
    cout << knapsack_mem(W, val, wt, n) << endl;
    cout << knapsack_bu(W, val, wt, n) << endl;
    return 0;
}