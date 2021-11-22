
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
void dfs(vector<vector<int> >& grid, int x, int y, int& n, int k) { 
        grid[x][y] = k;
        n++;
        if(x - 1 >= 0 && grid[x - 1][y] == -1) {
            dfs(grid, x - 1, y, n, k);
        }
        if(x + 1 < grid.size() && grid[x + 1][y] == -1) {
            dfs(grid, x + 1, y, n, k);
        }
        if(y - 1 >= 0 && grid[x][y - 1] == -1) {
            dfs(grid, x, y - 1, n, k);
        }
        if(y + 1 < grid[x].size() && grid[x][y + 1] == -1) {
            dfs(grid, x, y + 1, n, k);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        vector<int>  iNum;
        iNum.push_back(0);
        bool pand = false;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1)
                grid[i][j] = -1;
                if(grid[i][j] == 0)
                pand = true;
            }
        }
        if(!pand) return grid.size() * grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == -1) {
                    int n = 0;
                    int k = iNum.size();
                    dfs(grid, i, j, n, k);
                    iNum.push_back(n);
                }
            }
        }
        int maxc = INT_MIN;
        int c = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    int up, down, left, right;
                    up = down = left = right = 0;
                    if(i - 1 >= 0 && grid[i - 1][j] != 0) {
                        up = grid[i - 1][j];
                    }
                    if(i + 1 < grid.size() && grid[i + 1][j] != 0) {
                        if(grid[i + 1][j] != up)
                        down = grid[i + 1][j];
                    }
                    if(j - 1 >= 0 && grid[i][j - 1] != 0) {
                        if(grid[i][j - 1] != up && grid[i][j - 1] != down)
                        left = grid[i][j - 1];
                    }
                    if(j + 1 < grid[i].size() && grid[i][j + 1] != 0) {
                        if(grid[i][j + 1] != up && grid[i][j + 1] != down && grid[i][j + 1]!= left)
                        right = grid[i][j + 1];
                    }
                    maxc = max(maxc, iNum[up] + iNum[down] + iNum[left] + iNum[right]);
                    c++;
                    
                }
            }
        }
        if(maxc == 0) return 1;
        return maxc + 1;
    }

    int main(){
        return 0;
    }