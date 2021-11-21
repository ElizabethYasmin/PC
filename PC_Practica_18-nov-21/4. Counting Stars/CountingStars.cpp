#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

struct PIXEL {
    char c;
    bool used;
};

int floodfill(int m, int n, int i, int j, vector<vector<PIXEL>>& v) {
    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }
    if(v[i][j].used) {
        return 0;
    }
    v[i][j].used = true;
    floodfill(m, n, i, j+1, v);
    floodfill(m, n, i, j-1, v);
    floodfill(m, n, i+1, j, v);
    floodfill(m, n, i-1, j, v);

    return 1;
}

int main() {
    int m, n;
    int count = 1;
    while(cin >> m && cin >> n) {
        vector<vector<PIXEL>> v;
        for(int i = 0; i < m; i++) {
            vector<PIXEL> temp;
            for(int i = 0; i < n; i++) {
                char c;
                cin >> c;
                PIXEL p;
                p.c = c;
                p.used = (c == '#');
                temp.push_back(p);
            }
            v.push_back(temp);
        }
        int STARS = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                STARS += floodfill(m, n, i, j, v);
            }
        }
        cout << "Case " << count << ": " << STARS << endl;
        count++;
    }
}