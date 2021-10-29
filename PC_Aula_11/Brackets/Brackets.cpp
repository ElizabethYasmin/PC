#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int solution(string &S) {
    int N = S.length();
    if ( N == 0) {
        return 1;
    }
    if ( N%2 ) {
        return 0;
    }
    stack<char> nest;
    char c;
    for (int i=0; i<N; i++) {
        switch (S[i]) {
            case '{':
            case '[':
            case '(':
                nest.push(S[i]);
                break;
            case '}':
                c = nest.top();
                nest.pop();
                if ( c != '{') {
                    return 0;
                }
                break;
            case ']':
                c = nest.top();
                nest.pop();
                if ( c != '[') {
                    return 0;
                }
                break;
            case ')':
                c = nest.top();
                nest.pop();
                if ( c != '(') {
                    return 0;
                }
                break;
            default: break;
        }
    }
    if (nest.size() > 0 ) {
        return 0;
    }
    return 1;
}