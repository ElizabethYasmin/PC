
#include <iostream>
#include <string>
using namespace std;

int R,C, j, T;
string rowstr;
int grid[55][55];
int t[3025][2];

void DFS(int x, int y){
    if(x < 0 || x >= R || y < 0 || y >= C) return;
    if(grid[x][y] == 4 || grid[x][y] == 2) return;
    grid[x][y] = 4;
    DFS(x-1,y);
    DFS(x+1,y);
    DFS(x,y-1);
    DFS(x,y+1);
}

int main()
{
    T = 0;
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> rowstr;
        j = 0;
        for(auto car : rowstr){
            if(car == 'L'){
                t[T][0] = i;
                t[T][1] = j;
                grid[i][j++] = 1;
                T++;
            }
            else if(car == 'W') grid[i][j++] = 2;
            else grid[i][j++] = 3;
        }
    }
    if(T == 0){
        cout << "0" << endl;
        return 0;
    }
    int islas = 0;
    for(int i=0; i<T; i++){
        if(grid[t[i][0]][t[i][1]] == 1){
            DFS(t[i][0],t[i][1]);
            islas++;
        }
    }
    cout << islas << endl;
    return 0;
}