#include<iostream>
#include<vector>
#include<map>
//#include <bits/stdc++.h>
using namespace std;

vector<int> suffix(string arr){
    int n=arr.length(),ans=0;
    map<string,int> sor;
    vector<int> suff(n,0);
    for(int i=0;i<n;i++){
        sor[arr.substr(i)]=i;
    }int k=0,cont=0;
    for(auto j: sor){
        suff[k]=j.second;
        k++;
    }return suff;
}

int main(){
    
    string arraY;
    cout<<" ";cin>>arraY;
    cout<<arraY<<endl;
    vector<int> op= suffix(arraY);
    for(auto&i : op){
        cout<<i<<",";
    }
    return 0;
}