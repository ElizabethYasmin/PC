
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;


int minAddToMakeValid(string S) {
    int ans = 0;
    stack<int> s;
    for(int i=0;i<S.size();i++){
        if(S[i] == '(')
            s.push(i);
        else if(s.empty())
            ans++;
        else
            s.pop();
    }
    ans += s.size();
    return ans;
}
//Input: s = "())"
//Output: 1

int main()
{
    string s ={"())"};
    cout<<minAddToMakeValid(s);
    return 0;
}
