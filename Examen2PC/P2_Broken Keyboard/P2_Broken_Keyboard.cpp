///https://www.beecrowd.com.br/judge/en/problems/view/1642

#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
typedef map<char,int> tMCI;

int main(){
	int m;
	while (cin >> m && m){
		cin.ignore();
		string line;
		getline(cin, line);
		int si = 0;
		int ei = 0;
		int diff = 0;
		int res = 0;
		tMCI mp;
		while (1){
			if (si >= (int) line.length()) break;
			char c = line[si];
			if (diff < m){
				if (mp.find(c) == mp.end()){
					++diff;
				}
				++mp[c];
			}
			else{
				if (mp.find(c) != mp.end()){	
					++mp[c];
				}else{
					while (diff == m){
						char ec = line[ei];
						--mp[ec];
						if (mp[ec] == 0){
							mp.erase(mp.find(ec));
							--diff;
						}
						++ei;
					}
					++mp[c];
					++diff;
				}
			}
			++si;
			res = max(si-ei, res);
		}
		cout << res << endl;
	}
}