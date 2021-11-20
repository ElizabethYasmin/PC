#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

void solution(string &S){
    queue<char> q;
    string rpt = "";
    bool isCap = false;
    for(int i=0; i<S.length(); i++){
        if(S[i] == '$'){
            while(!q.empty()){
                rpt += (isCap) ? toupper(q.front()) : tolower(q.front());
                q.pop();
            }
        }else if(S[i] == '@'){
            isCap = (isCap) ? false : true;
        }else{
            q.push(S[i]);
        }
    }
    cout << rpt << endl;
}

int main(){
    string S = "abc$d@ef$@g$"; 
    solution(S);
    return 0;
}