#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string>& token) {
        stack<int> numeros;
        for(const string& s: token){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int a = numeros.top();
                numeros.pop();
                int b = numeros.top();
                numeros.pop();
                if(s == "+"){
                    numeros.push(b + a);
                }else if(s == "-"){
                    numeros.push(b - a);
                }else if(s == "*"){
                    numeros.push(b * a);
                }else if(s == "/"){
                    numeros.push(b / a);
                }
             }else{
                numeros.push(atoi(s.c_str()));
            }
                
        }
        return numeros.top();
}

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    cout<<evalRPN(tokens);
    return 0;
}