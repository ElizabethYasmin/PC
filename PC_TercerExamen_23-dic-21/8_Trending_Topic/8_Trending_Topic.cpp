//https://open.kattis.com/problems/trendingtopic

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define vs vector<string>
#define psi pair<string,int>
#define msi map<string,int>

bool cmp(psi p1, psi p2) {
    if(p1.second == p2.second) { return p1.first < p2.first;}return p1.second > p2.second;
}

void runquery(msi cnt, int top) {
    map<int,vs> rev;
    for(auto i : cnt) {rev[i.second].push_back(i.first);}

    auto it = prev(rev.end());

    vector<psi> res;
    while(res.size() < top) {
        for(auto j : it->second) {
            res.push_back({j,it->first});
        }
        if(it == rev.begin()) break;
        it--;
    }

    sort(res.begin(),res.end(),cmp);
    for(auto i : res) {
        cout << i.first << " " << i.second << endl;
    }

}

int main() {
    string s;
    vector<vs> days;
    map<int,vector<int>> queries;
    int currday = 0;
    days.push_back({});
    while(cin >> s) {
        if(s == "<text>") {days.push_back({});currday++;continue;}
        if(s == "</text>") {continue;}
        if(s == "<top") {int n;cin >> n;string g;cin >> g;queries[currday].push_back(n);continue;}
        if(s.size() < 4) {continue;}
        days[currday].push_back(s);
    }
    days.push_back({});
    currday++;msi cnt;

    for(int i = 0; i < currday; i++) {
        for(auto j : days[i]) {cnt[j]++;}
        if(i >= 7) {
            for(auto j : days[i-7]) {cnt[j]--;
                if(cnt[j] == 0) {cnt.erase(j);}
            }
        }
        for(auto j : queries[i]) {
            cout << "<top " << j << ">" << endl;
            runquery(cnt,j);
            cout << "</top>" << endl;
        }
    }
}