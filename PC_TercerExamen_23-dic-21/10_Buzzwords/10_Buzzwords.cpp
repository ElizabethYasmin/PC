//https://open.kattis.com/problems/buzzwords
#include<iostream>
#include <vector>
#include<string>
#define vec vector<int>
using namespace std;

const int TamAlfabet = 26;
inline int mp(char c) { return c - 'A'; }

struct Node {
	Node *ch[TamAlfabet];
	int c = 0;
	int d = 0;
	Node() {for (int i = 0; i < TamAlfabet; ++i) ch[i] = NULL;}

	void insert(string &s, int i = 0) {
		while (i < s.length() && s[i] == ' ') i++;
		if (i == s.length()) { c++; return; }
		else {c++;int v = mp(s[i]);
			if (ch[v] == NULL) {ch[v] = new Node();ch[v]->d = d + 1;}
			ch[v]->insert(s, i + 1);
		}
	}
	void cleanup() {
		for (int i = 0; i < TamAlfabet; ++i) {
			if (ch[i] != NULL) ch[i]->cleanup();delete ch[i];
		}
	}
	void count(vec &count) {
		count[d] = max(c, count[d]);
		for (int i = 0; i < TamAlfabet; ++i)
			if (ch[i] != NULL)ch[i]->count(count);}
};

int main() {
	string s;
	while (getline(cin, s)) {
		if (s.length() == 0) break;Node root;
		for (int i = 0; i < s.length(); ++i)
			if (s[i] != ' ')root.insert(s, i);

		vec dpth(s.length() + 3, 0);
		root.count(dpth);
		for (int i = 1; i <= s.length() + 1; ++i) {
			if (dpth[i] > 1) cout << dpth[i] << '\n';
			else {cout << endl;break;}
		}
	}
	return 0;
}