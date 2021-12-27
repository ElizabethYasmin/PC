//https://open.kattis.com/problems/megainversions

#include <iostream>
#include <vector>
#define ll long long
#define vl vector<long long>
using namespace std;

void Inversion(vl& F, ll i, ll d) {
    for(; i < F.size(); i |= i+1) {F[i] += d;}
}

ll sum(vl& F, ll i) {
    ll total = 0;
    for(; i > 0; i &= i-1) { total += F[i-1];}return total;
}

ll count(vl& F, ll i) {return sum(F, F.size()) - sum(F, i);}

int main() {
    ll n;
    cin >> n;
    vl F1(n+1, 0);vl F2(n+1, 0);vl F3(n+1, 0);
    for(ll i = 0; i < n; i++) {int num; cin >> num;
        ll s1 = count(F1, num+1);
        ll s2 = count(F2, num+1);
        Inversion(F1, num, 1);Inversion(F2, num, s1);Inversion(F3, num, s2);
    }
    cout << count(F3, 0) << endl;
}