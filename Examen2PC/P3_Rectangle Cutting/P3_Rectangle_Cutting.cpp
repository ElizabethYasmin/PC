//https://cses.fi/problemset/task/1744


#include <iostream>
#include <vector>
using namespace std;

int a,b;

void Rectangle_Cutting(){
    vector<vector<int>> memo(a+1, vector<int>(b+1));
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==j){
                memo[i][j] = 0;
            }else{
                memo[i][j] = 200000;
                for(int k=1; k<i; k++){
                    memo[i][j] = min(memo[i][j], memo[k][j] + memo[i-k][j] + 1);
                }
                for(int k=1; k<j; k++){
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[i][j-k] + 1);
                }
            }
        }
    }
    cout << memo[a][b] << endl;
}

int main(){
    cin >> a >> b;
    Rectangle_Cutting();
    return 0;
}


