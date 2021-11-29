//https://www.beecrowd.com.br/judge/en/problems/view/2917

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;
    while(cin>>n){
        vector<long long> S(n*10,0);
        for(int i=0; i<n*10;i++){cin>>S[i];}
        long long St=n*20, MaxxLocal=0,Maxxglobal=INT_MIN,i=0,k=0,posx=0; bool again=false;
        while(i<St){
            if(k==(n*10)){ k=0;again=true;}
            MaxxLocal=MaxxLocal+S[k];

            if(posx==k && again==true)break;
            else{ if(Maxxglobal<MaxxLocal) {Maxxglobal=MaxxLocal;}}

            if(MaxxLocal<=0){ 
                if(k==(n*10)-1)posx=0;
                else posx=k+1; 
                MaxxLocal=0;
            }
            i++;k++;
        }
        cout<<Maxxglobal<<"\n";
    }

    return 0;
}