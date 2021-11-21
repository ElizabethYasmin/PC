#include <iostream>
#include <string>
#include <vector>
using namespace std;


void spread(int i, int x, int j, int y, vector<bool> &v){
    v[i * y + j] = false;
    for(int k = -1; k < 2; k++){
        for(int l = -1; l < 2; l++){
            if(k == 0 && l == 0){
                continue;
            }
            i += k;
            j += l;
            if(i < x && i >= 0 && j < y && j >= 0 && v[i * y + j]){
                spread(i, x, j, y, v);
            }
            i -= k;
            j -= l;
        }
    }
}

int main(){
    // #ifndef TESTING
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int x, y;
    cin >> x >> y;
    char pixel;
    vector<bool> dish(x * y);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> pixel;
            dish[i * y + j] = (pixel == '#');
        }
    }
    int amoebaCount = 0;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(dish[i * y + j]){
                amoebaCount++;
                spread(i, x, j, y, dish);
            }
        }
    }
    cout << amoebaCount << endl;
    
    return 0;   
}
