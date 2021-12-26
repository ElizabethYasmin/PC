#include <bits/stdc++.h>
using namespace std;
struct SuffixArray {
	string s;
	int n;
	vector < vector <int> > P;
	SuffixArray(string &_s) : s(_s), n(_s.length()) {
    construct();
  }

void construct() {
		P.push_back(vector <int> (n, 0));
		compress();
		vector <int> occ(n + 1, 0), s1(n, 0), s2(n, 0);
		for ( int k = 1, cnt = 1; cnt / 2 < n; ++k, cnt *= 2 ) {
			P.push_back(vector <int> (n, 0));
			fill(occ.begin(), occ.end(), 0);
			for ( int i = 0; i < n; ++i )
				occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]++;

			partial_sum(occ.begin(), occ.end(), occ.begin());

			for ( int i = n - 1; i >= 0; --i )
				s1[--occ[i+cnt<n ? P[k-1][i+cnt]+1 : 0]] = i;

			fill(occ.begin(), occ.end(), 0);

			for ( int i = 0; i < n; ++i )
				occ[P[k-1][s1[i]]]++;

			partial_sum(occ.begin(), occ.end(), occ.begin());

			for ( int i = n - 1; i >= 0; --i )
				s2[--occ[P[k-1][s1[i]]]] = s1[i];

			for ( int i = 1; i < n; ++i ) {
				P[k][s2[i]] = same(s2[i], s2[i - 1], k, cnt)
					? P[k][s2[i - 1]] : i;
			}
		}
	}

bool same(int i, int j, int k, int l) {
	return P[k - 1][i] == P[k - 1][j]
		&& (i + l < n ? P[k - 1][i + l] : -1)
		== (j + l < n ? P[k - 1][j + l] : -1);
}

void compress() {
	vector <int> cnt(256, 0);
	for ( int i = 0; i < n; ++i )
    cnt[s[i]]++;

	for ( int i = 0, mp = 0; i < 256; ++i )
		  if (cnt[i] > 0) cnt[i] = mp++;
	for ( int i = 0; i < n; ++i )
       P[0][i] = cnt[s[i]];
}

vector <int> &get_array() {
      return P.back();
}

int lcp(int x, int y) {
	int ret = 0;
	if (x == y)
     return n - x;
	for ( int k = P.size() - 1; k >= 0 && x < n && y < n; --k )
     if (P[k][x] == P[k][y]) {
         x += 1 << k;
         y += 1 << k;
         ret += 1 << k;
		}
	return ret;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = s.length();
		SuffixArray sa(s);

		vector <int> &arr = sa.get_array();

		vector <int> inv(n, -1);
		for ( int i = 0; i < n; ++i ) {
			inv[arr[i]] = i;
		}

		vector <int> lcp(n, 0);
		for ( int i = 1; i < n; ++i ) {
			lcp[i] = sa.lcp(inv[i - 1], inv[i]);
		}

		long long ans = 0;
		for ( int i = 1; i < n; ++i ) {
        if ( lcp[i] > lcp[i - 1] )
          ans += lcp[i] - lcp[i - 1];
		}

		cout << ans << endl;
	}
	return 0;
}