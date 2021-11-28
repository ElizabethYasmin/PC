//https://cses.fi/problemset/task/1653

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long maxWeight;
    cin >> n >> maxWeight;
    vector<long long> people(n);
    for (int i = 0; i < n; i++) cin >> people[i];
    int limit = 1 << n;
    vector<pair<long long, long long>> dp(limit); 
    dp[0] = {1, 0};
    for (int mask = 1; mask < limit; mask++) {
        pair<long long, long long> bestResult = {20000, 20000};
        for (int i = 0; i < n; i++) {
            if (((1 << i) & mask) == 0) continue;
            auto res = dp[(1 << i) ^ mask];
            if (res.second + people[i] <= maxWeight) {
                res.second += people[i];
            } else {
                res.first += 1;
                res.second = people[i];
            }
            bestResult = min(bestResult, res);
        }
        dp[mask] = bestResult;
    }
    cout << dp[limit - 1].first;
    return 0;
}