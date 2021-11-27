#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
queue<pair<int, int>> Queue;
int paths[1005][1005];
pair<int, int> from[1005][1005];

pair<int, int> A;
string rpt;
bool flag = false;

void retrace(pair<int, int> node){
	pair<int, int> origin = from[node.first][node.second];
	if(origin ==  pair<int, int>(0,0)) return;
	if(origin.first == node.first+1) rpt.push_back('U');
	if(origin.first == node.first-1) rpt.push_back('D');
	if(origin.second == node.second+1) rpt.push_back('L');
	if(origin.second==node.second-1) rpt.push_back('R');
	retrace(origin);

}
void verification(pair<int, int> origin, pair<int, int> dest){
	int pl = paths[origin.first][origin.second];
	if(pl+1<paths[dest.first][dest.second]){
		paths[dest.first][dest.second]  = pl+1;
		Queue.push(dest);
		from[dest.first][dest.second] = origin;
	}
}
bool mora = false; 
void BFS(){
	while(!Queue.empty()){
		pair<int, int> loc = Queue.front(), next; Queue.pop();
		next = loc; next.first++; verification(loc, next);
		next = loc; next.first--; verification(loc, next);
		next = loc; next.second++; verification(loc, next);
		next = loc; next.second--; verification(loc, next);
		if(mora && (loc.first == 1 || loc.second == 1 || loc.first == N || loc.second == M)){
			cout << "YES" << endl;
			cout << paths[loc.first][loc.second] << endl;
			retrace(loc);
			flag = true;
			return;
		}
	}
}
int main() {
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		string s;
		cin >> s;
		for(int j = 1; j <= M; j++){
			paths[i][j] = INT_MAX;
			if(s[j-1] == '#') paths[i][j] = 0;
			if(s[j-1] == 'M') {Queue.push(pair<int, int>(i,j)); paths[i][j]  = 0;}
			if(s[j-1] == 'A') {A.first = i; A.second = j;}
		}
	}
	BFS(); 
	mora = true; 
	from[A.first][A.second] = pair<int, int>(0,0);
	paths[A.first][A.second] = 0; Queue.push(A); 
	BFS();
	if(flag){
		reverse(rpt.begin(), rpt.end());
		cout << rpt << endl;
	}
	else cout << "NO" << endl;
}