#include<iostream>
#include<vector>
#include<map>
//#include <bits/stdc++.h>
using namespace std;

vector<int> LPSA(string arr){
    int n=arr.length();
    map<string,int> sor;
    vector<int> lcp(n,0);
    string sub="";
    for(int i=n-1;i>=0;i--){
        sub=arr[i]+sub;
        sor[sub]=i;
    }
    int k=0,cont=0;
    lcp[0]=0;
    string prev;
    for(auto j: sor){
        if(k>=1){
            cont=0;
            string temp=j.first;
            for(int i=0;i<temp.length();i++){
                if(i>=prev.length()){
                    lcp[k]=cont;
                    break;}
                if(prev[i]==temp[i]){ 
                    cont++;
                }else{
                    lcp[k]=cont;break;}
            }
        } prev=j.first;k++;
    } return lcp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string arr;
    cout<<"";cin>>arr;
    vector<int> op= LPSA(arr);
    cout<<arr<<endl;
    for(auto&i : op){
        cout<<i<<" ";
    }
    return 0;
}