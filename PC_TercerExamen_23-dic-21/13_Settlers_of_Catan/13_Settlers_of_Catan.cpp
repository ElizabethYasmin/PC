//https://open.kattis.com/problems/settlers2

#include <iostream>
#include<vector>
using namespace std;

int val[400][400];
int mem[20000];
int cont[6] = {0, 0, 0, 0, 0, 0};

int small(int y, int x) {
	bool used[6];
	for (int i = 0; i < 6; i++) used[i] = false;
	used[val[y][x + 1]] = true;
	used[val[y + 1][x]] = true;
	used[val[y + 1][x - 1]] = true;
	used[val[y][x - 1]] = true;
	used[val[y - 1][x]] = true;
	used[val[y - 1][x + 1]] = true;
	int r = 0;
	int m = 200 * 200;
	for (int i = 1; i < 6; i++) {if (!used[i] && cont[i] < m) {r = i;m = cont[i];}}
	cont[r]++;
	return r;
}

int main() {
	for (int i = 0; i < 400; i++) for (int j = 0; j < 400; j++) val[i][j] = 0;
	for (int i = 0; i < 20000; i++) mem[i] = 0;
	int c;
	cin >> c;
	int i = 0, t = 0,y = 200,x = 200;
	val[y][x] = small(y, x);;
	mem[t] = val[y][x];
	t++;
	for (int k = 0; k < c; k++) {int n;cin >> n;
		while (t < n) {
			for (int j = 1; j < i; j++) {y++;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			for (int j = 0; j < i; j++) {y++;x--;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			for (int j = 0; j < i; j++) {x--;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			for (int j = 0; j < i; j++) {y--;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			for (int j = 0; j < i; j++) {y--;x++;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			for (int j = 0; j <= i; j++) {x++;val[y][x] = small(y, x);mem[t] = val[y][x];t++;}
			i++;
		}
		cout << mem[n - 1] << endl;
	}
}