//DynamicRangeSumQueries
//Elizabeth Yasmin Huanca Parqui
//20190748
//----------------------------------------------------------------
//Given an array of n integers, your task is to process q queries of the following types:
//1.update the value at position k to u
//2.what is the sum of values in range [a,b]?
//----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stack>
using namespace std;

typedef long long ll;

const int NMAX = 200005;
int n, q;
ll a[NMAX], tree[NMAX];


ll sum(int k){
    ll s = 0;
    while(k>0){
        s+=tree[k];
        k-=k&-k;
    }
    return s;
}

void add(int k, ll x){
    while(k<=n){
        tree[k]+=x;
        k+=k&-k;
    }
}
//Entrada:
//8 4
//3 2 4 5 1 1 5 3
//2 1 4
//2 5 6
//1 3 1
//2 1 4

//Saliada:
//14
//2
//11


int main(){
    cin>>n>>q;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        add(i, a[i]);
    }
    while(q--){
        int type; cin>>type;
        if(type==1){
            int k; 
            ll p;
            cin>>k>>p;
            add(k, p-a[k]);
            a[k] = p;

        }
        else{
            int l, r; cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<'\n';
        }
    }
    return 0;
}