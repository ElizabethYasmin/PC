#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;

const long long int limi=1e5+5;
int n=0,t=0,ans=0;
string arr;
int sa[limi],lcp[limi];
int tmp[limi],pos[limi];

bool COMPAR(int i, int j){
    if(pos[i]!=pos[j]) return (pos[i]<pos[j]);
    i+=t;j+=t;
    if(i<n && j<n) return (pos[i]<pos[j]);
    return (i>j);
}
void SUFFIXARRAY(){
    for(int i=0; i<n;i++){
        sa[i]=i;
        pos[i]=arr[i]; }
    for(t=1;t<2*n+1;t*=2){
        sort(sa,sa+n,COMPAR);
        for(int i=0; i<n-1;i++){
            tmp[i+1]=tmp[i];
            if(COMPAR(sa[i],sa[i+1])) tmp[i+1]++; }
        for(int i=0; i<n;i++){
            pos[sa[i]]=tmp[i];}
        if(tmp[n-1]==n-1) break; }
}

void LCP_FIND(){
    int p=0;
    for(int i=0; i<n;i++){
        if(pos[i]!=n-1){
            int j=sa[pos[i]+1];
            while(arr[i+p]==arr[j+p])p++;
            lcp[pos[i]]=p;
            if(p>0) p--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x=0;
    cin>>x;
    
    for(int i=0;i<x;i++){
        cin>>arr;
        n=arr.length();
        ans=lcp[0];
        for(int j=1; j<n;j++){
            if(lcp[j]>lcp[j-1]) {
                ans+=(lcp[j]-lcp[j-1]); }
        }
        cout<<ans<<"\n";
    }
    return 0;
}