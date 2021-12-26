
//https://open.kattis.com/problems/collatz
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

vector<ll> collatz(ll n) {
    vector<ll> v;
    v.push_back(n);
    while(n != 1) {
        if(n % 2 == 0)
            n /= 2;
        else
            n = 3*n +1;
        v.push_back(n);
    }
    return v;
}
int find(int n, vector<ll> v) {
    for(int i=0; i<v.size(); i++) {
        if(v[i] == n)
            return i;
    }
    return -1;
}
int main() {
    ll n1, n2;
    int i, j;
    vector<ll> v1, v2;

    while(cin >> n1 >> n2 && n1 && n2) {
        v1 = collatz(n1);
        v2 = collatz(n2);

        for(i=0; i<v1.size(); i++) {
            j = find(v1[i], v2);
            if(j != -1)
                break;
        }
        cout << n1 << " needs " << i << " steps, "<< n2 << " needs " << j << " steps, they meet at "<< v1[i] << '\n';
    }
}