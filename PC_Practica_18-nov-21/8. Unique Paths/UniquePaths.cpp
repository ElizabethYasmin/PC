#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n, 0));

    for(int i=0; i<m; i++) memo[i][0] = 1;
    for(int j=0; j<n; j++) memo[0][j] = 1;

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            memo[i][j] = memo[i-1][j] + memo[i][j-1];
        }
    }

    return memo[m-1][n-1];      
}

int main(){
    cout << uniquePaths(3, 7) << endl;
    return 0;
}