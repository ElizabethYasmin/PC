
#include <stdio.h>
class Solution {
public:
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
};

int main()
{
    printf("Hello World");

    return 0;
}
