//https://open.kattis.com/problems/stack//

#include <iostream>
#include <string>
using namespace std;
int memo[300+1][300+1];

int function(const string &s, int start, int end){
  int &ans = memo[start][end];
  if (ans != -1)
    return ans;
  if (start == end)
    return ans = 2;
  ans = 2*(end-start+1);
  ans = min(ans, 2 + function(s, start, end-1));
  for (int i = start; i < end; i++) {
    if (s[i] == s[end])
      ans = min(ans, function(s, start, i) + function(s, i+1, end-1));
  }
  return ans;
}

void solution(){
  string s;
  getline(cin, s);
  int n = s.length();
  for (int i = 0; i <= n; i++) {
    fill(memo[i], memo[i]+n+1, -1);
  }
  cout << n + function(s, 0, n-1) << endl;
}

int main(){
  int T;
  cin >> T;
  string line;
  getline(cin, line);
  while (T--)
    solution();
  return 0;
}




