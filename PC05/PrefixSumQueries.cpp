#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;

 
const int N = 200010;
const int S = 1 << 18;
 
int n, q, a[N];
 
struct node {
	long long sum, pref;
	node(long long sum, long long pref) : sum(sum), pref(pref) {}
	node(long long x = 0) : sum(x), pref(max(0LL, x)) {}
	friend node operator+(const node& a, const node& b) {
		return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
	}
} tt[S << 1];
 
void build(int k = 1, int l = 1, int r = n) {
	if (l == r) { tt[k] = node(a[l]); return; }
	int m = (l + r) >> 1;
	build(k << 1, l, m);
	build(k << 1 | 1, m + 1, r);
	tt[k] = tt[k << 1] + tt[k << 1 | 1];
}
 
void update(int i, int x, int k = 1, int l = 1, int r = n) {
	if (l == r) { tt[k] = node(x); return; }
	int m = (l + r) >> 1;
	if (i <= m) update(i, x, k << 1, l, m);
	else update(i, x, k << 1 | 1, m + 1, r);
	tt[k] = tt[k << 1] + tt[k << 1 | 1];
}
 
node query(int ql, int qr, int k = 1, int l = 1, int r = n) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return tt[k];
	int m = (l + r) >> 1;
	node q1 = query(ql, qr, k << 1, l, m);
	node q2 = query(ql, qr, k << 1 | 1, m + 1, r);
	return q1 + q2;
}

//Entrada:
//8 4
//1 2 -1 3 1 -5 1 4
//2 2 6
//1 4 -2
//2 2 6
//2 3 4

//Salida:
//5
//2
//0
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

	for (int i = 1; i <= n; ++i)
        cin >> a[i];
	build();
	for (int i = 0, t, x, y; i < q; ++i) {
        cin >> t >> x >> y;
		if (t == 1) update(x, a[x] = y);
        else cout << query(x, y).pref << '\n';
	}
}