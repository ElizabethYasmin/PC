//NearestSmallerValues
//Elizabeth Yasmin Huanca Parqui
//20190748
//----------------------------------------------------------------
//Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
//----------------------------------------------------------------


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stack>
using namespace std;



int main() {

    int N;
	cin >> N;
	stack<pair<int, int>> stack;
	stack.push({0, 0});

	for(int i = 1; i <= N; ++i) {
		int a; cin >> a;
		while(!stack.empty() && stack.top().first >= a) stack.pop();
		cout << stack.top().second << " ";
		stack.push({a, i});
	}
}