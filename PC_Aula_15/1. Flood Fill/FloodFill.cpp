
#include <iostream>
#include <vector>
#define OSIZE 4

using namespace std;

static int offsets[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void _floodFill(vector<vector<int>> &grid, int i, int j, int color, int oldCol){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        return;
    if(grid[i][j] != oldCol) return;

    grid[i][j] = color;
    for(int k=0; k<OSIZE; ++k){
        _floodFill(grid, i+offsets[k][0], j+offsets[k][1], color, oldCol);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &grid, int i, int j, int color){
    if(grid[i][j] == color) return grid;

    _floodFill(grid, i, j, color, grid[i][j]);
    return grid;
}




int main(){
    //vector<vector<int>> grid = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> grid = {{0,0,0},{0,1,1}};
    cout << "Original Grid:\n";
    for(auto i : grid){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << "Flood fill Grid:\n";
    vector<vector<int>> newGrid = floodFill(grid, 1, 1, 2);

    for(auto i : newGrid){
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}