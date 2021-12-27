
//https://open.kattis.com/problems/fire2
#include<iostream>
#include <vector>
#include<string>
#include <queue>
#define qpii queue<pair<int,int>>
#define vvc vector<vector<char>>
using namespace std;

int n, m;

bool rangeguys(int x, int y) {return x >= 0 && x <= n+1 && y >= 0 && y <= m+1;}

bool rangefire(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m;}

void bfs(vvc& v, qpii& oldq, qpii& newq, bool fire) {
    vector<pair<int,int>> movement = {{1,0},{-1,0},{0,1},{0,-1}};
    while(!oldq.empty()) {
        int currx = oldq.front().first;
        int curry = oldq.front().second;
        oldq.pop();
        for(auto i : movement) {int nextx = currx + i.first;int nexty = curry + i.second;
            if(fire) {
                if(rangefire(nextx,nexty)) {
                    if(v[nextx][nexty] == '.' || v[nextx][nexty] == '@') {v[nextx][nexty] = '*';newq.push({nextx,nexty});}
                }
            }
            else {
                if(rangeguys(nextx,nexty)) {
                    if(v[nextx][nexty] == '.') {v[nextx][nexty] = '@';newq.push({nextx,nexty});}
                }
            }
        }
    }
}

void checkguys(vvc& v, qpii& guys) {
    qpii newguys;
    while(!guys.empty()) {
        pair<int,int> i = guys.front();
        guys.pop();
        if(v[i.first][i.second] != '*') {newguys.push(i);}
    }
    guys = newguys;
}

void solve() {
    cin >> m >> n;

    vvc v;
    v.resize(n+2, vector<char>(m+2, '.'));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {cin >> v[i][j];}
    }

    qpii guys;
    qpii fire;

    for(int i = 0; i < n+2; i++) {
        for(int j = 0; j < m+2; j++) {
            if(v[i][j] == '@') {guys.push({i,j});}
            if(v[i][j] == '*') {fire.push({i,j});}
        }
    }

    int time = 0;
    bool works = false;
    while(!fire.empty() || !guys.empty()) {
        qpii newguys;
        qpii newfire;
        bfs(v, guys, newguys, false);
        bfs(v, fire, newfire, true);

        for(int i = 0; i < n+2; i++) {if(v[i][0] == '@' || v[i][m+1] == '@') works = true;}
        for(int j = 0; j < m+2; j++) {if(v[0][j] == '@' || v[n+1][j] == '@') works = true;}
        checkguys(v, newguys);
        guys = newguys;fire = newfire;time++;
        if(works) break;
    }
    if(works) {cout << time << endl;}
    else {cout << "IMPOSSIBLE" << endl;}
}

int main() {
    int cases;
    cin >> cases;
    while(cases--) {solve();}
    return 0;
}