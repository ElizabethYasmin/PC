#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

  int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    res=max(res,dfs(grid,i,j));
        return res;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1)+1;
    }

int main(){
    vector<vector<int>> grid = {{1,1},{1,1}};
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout <<"-------"<< maxAreaOfIsland(grid)<< "--------";
    return 0;
}