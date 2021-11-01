#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

string newString(string S){
    deque<char> q;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] != '#')
            q.push_back(S[i]);
        else if (!q.empty())
            q.pop_back();
    }
    string ans = "";
    while (!q.empty()) {
        ans += q.front();
        q.pop_front();
    }
    return ans;
}
//Input: abc#de##f#ghi#jklmn#op#
//Output: abghjklmo

int main(){
    string S = "abc#de##f#ghi#jklmn#op#";
    cout << newString(S);
 
    return 0;
}