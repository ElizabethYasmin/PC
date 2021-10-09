#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;
//entrada 
//4 8
//2 7 5 1
//salida
//1 3 4

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,x; cin >> n >> x;
	vector<pair<int, int>> arr;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		pair<int, int> p; p.first = a; p.second = i;
		arr.push_back(p);
	}
	sort(begin(arr), end(arr));
	for(int i = 0; i < n; i++){
		int l, r; l = 0; r = n-1;
		while(l != r){
			int target; target = x - arr.at(i).first;
			if(l != i && r != i && arr.at(l).first + arr.at(r).first == target){
				cout << arr.at(i).second << " " << arr.at(l).second
					 << " " << arr.at(r).second << endl;
				return 0;
			}
			if(arr.at(l).first + arr.at(r).first < target){
				l++;
			}
			else{
				r--;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}