#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int evalRPN(vector<string>& tok) {
        stack<int> numeros;
        for(const string& s: tok){
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
//Input: tokens = ["2","1","+","3","*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9

int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    evalRPN(tokens);
    return 0;
}