#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


long fib(int n){
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

long fib(int n, vector<long>& memo){
    if(memo[n]) return memo[n];
    long result{};
    if(n <= 1)
        result = n;
    else
        result = fib(n-1, memo) + fib(n-2, memo);
    memo[n] = result;
    return result;
}

long fib_memoization(int n){
    vector<long> memo(n+1);
    return fib(n, memo);
}

long fib_bottomup(int n){
    if(n <= 1)
        return n;
    vector<long> F(n+1);
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i <= n; i++){
        F[i] = F[i-1] + F[i-2];
    }
    return F[n];
}

int main(int argc, char const *argv[])
{
    cout << fib(4) << endl;
    cout << fib_memoization(4) << endl;
    cout << fib_bottomup(4) << endl;
    return 0;
}