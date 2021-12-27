//https://open.kattis.com/problems/excursion
#include <iostream>
#include<vector>
#define ll long long
using namespace std;

int main() {
    vector<ll> count(3, 0);
    string s;
    cin >> s;
    for(auto& i : s) { count[i-'0']++;}
    ll swaps = 0;
    for(auto& i : s) {
        if(i == '0') {count[0]--;}
        else {swaps += count[0];}
    }

    for(auto& i : s) {
        if(i == '1') {count[1]--;}
        if(i == '2') {swaps += count[1];}
    }
    cout << swaps << endl;
}