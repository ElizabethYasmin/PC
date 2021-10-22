#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//Entrada:
//2
//1 2 2 1
//Salida:
//4
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v1(2*n), v2;
    for(auto& i : v1) {
        cin >> i;
    }

    int moves = 0;
    while(!v1.empty()) {
        moves++;

        if(v2.empty()) {
            v2.push_back(v1.back());
            v1.pop_back();
            continue;
        }

        if(v1.back() == v2.back()) {
            v1.pop_back();
            v2.pop_back();
            continue;
        }

        v2.push_back(v1.back());
        v1.pop_back();
    }

    if(v2.empty()) {
        cout << moves << endl;
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}