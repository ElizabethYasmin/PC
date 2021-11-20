
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int n,m;
int result=0;

void DFS(vector<vector<int>>& A,int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || A[i][j]==0)
        return;
    A[i][j]=0;
    DFS(A,i+1,j);
    DFS(A,i-1,j);
    DFS(A,i,j+1);
    DFS(A,i+1,j);
    DFS(A,i,j-1);
    return; 
    
}
int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
              if(grid[i][j]==1){
                  if(i==0 || i==n-1 || j==0 || j==m-1){
                      DFS(grid,i,j);
                  }
              }
            }
            
        }
        int result=0;
        for (int i = 0; i < n; i++){
           for (int j = 0; j < m; j++){
               if(grid[i][j]==1){
                   result++;
               }
           }
        
        } return result;
}

int main(){
    vector<vector<int>> g = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout<<numEnclaves(g);
}