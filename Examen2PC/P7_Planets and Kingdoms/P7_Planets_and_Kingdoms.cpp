//https://cses.fi/problemset/task/1683


#include<iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>// std::min
using namespace std;

//Tarjan's algorithm
struct SCC {
	int N, ti = 0; vector<vector<int>> adj;
	vector<int> disc, comp, st, comps;
	void init(int _N) {
		N = _N;
		adj.resize(N), disc.resize(N), comp = vector<int>(N,-1);
	}
	void ae(int x, int y) {
		adj[x].push_back(y);
	}
	int DFS(int x) {
		int low = disc[x] = ++ti; st.push_back(x); 
		for(int y : adj[x]){
			if (comp[y] == -1){
				low = min(low, disc[y]? : DFS(y));
			} 
		} 
		if (low == disc[x]) { 
			comps.push_back(x); for (int y = -1; y != x;)
				comp[y = st.back()] = x, st.pop_back();
		}
		return low;
	}
	/*void gen() {
		for(int i=0; i<N; i++) if (!disc[i]) DFS(i);
		reverse(begin(comps), end(comps));
	}*/
	void gen(){
		for(int i=0; i<N; i++) if (!disc[i]) DFS(i);
			begin(comps), end(comps);
	}
};

int main() {
	int n, m, a, b;
	cin >> n >> m;

	SCC graph;
	graph.init(n);
	while(m--) {
		cin >> a >> b;
		graph.ae(--a, --b);
	}
	graph.gen();

	int ID[200000]{};
	int ids = 0;
	for(int i=0; i<n; i++) {
		if(!ID[graph.comp[i]]) {
			ID[graph.comp[i]] = ++ids;
		}
	}
	cout << ids << '\n';
	for(int i=0; i<n; i++) {
		cout << ID[graph.comp[i]] << " \n"[i==n-1];
	}

}


