
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int scoreOfParentheses(string S) {
    stack<int> numero;
    stack<char> op,sta;
    for(int i = 0; i < S.length(); i++){
    	char tmp = S[i];
    	if(tmp == '('){
			sta.push(tmp);
			if(i-1>= 0 && S[i-1] == '(') op.push('*');
			else if(i-1>=0 && S[i-1] == ')') op.push('+');
		}
    	else if(tmp == ')' && sta.top() == '(')
    	{
    		sta.pop();
    		if(i-1>=0 && S[i-1] =='(') 
			{
				numero.push(1);
				while(!op.empty() && op.top() == '+')
				{
					int a = numero.top();
					numero.pop();
					int b = numero.top();
					numero.pop();
					numero.push(a+b);
					op.pop();
				}
			}
    		else 
    		{
    			if(op.top()=='*') 
				{
					int a = numero.top();
					numero.pop();
					numero.push(2*a); 
					op.pop();
				}
				while(!op.empty() && op.top() == '+')
				{
					int a = numero.top();
					numero.pop();
					int b = numero.top();
					numero.pop();
					numero.push(a+b);
					op.pop();
				}
			}
		}
	}
	
	return numero.top();
}

//Input: s = "(()(()))"
//Output: 6

int main(){
    string s ={"(()(()))"};
    cout<<scoreOfParentheses(s);
    return 0;
}