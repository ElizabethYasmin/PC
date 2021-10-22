//MaximumSubarraySumII
//Elizabeth Yasmin Huanca Parqui
//20190748
//----------------------------------------------------------------
//Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.
//----------------------------------------------------------------


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stdio.h>
#include <set>
using namespace std;
#define int long long
 
//Entrada: 8 1 2
//         n a b
//Entrada: -1 3 -2 5 3 -5 2 2

//Salida: 8

signed main(){
    //Ingreso de datos
    int n,x,y; cin>>n>>x>>y;
    int a[n];
    //array
    for (int i = 0; i < n; i++){
        cout<<"Value["<<i+1<<"] -> ";cin>>a[i];}
    int pre[n+1] = {0};
    for (int i = 1; i <= n; i++) 
        pre[i] = pre[i-1] + a[i-1];
    int s = 0, len = x;
    set<pair<int,int>> st;
    for (int i = 0; i < x; i++)
        s += a[i];
    st.insert({pre[1], 0});
    int mx = s;
    for (int i = x; i < n; i++) {
        int z = pre[i+1] - pre[i+1-x];
        if (len == y) {
            auto it = st.begin();
            //devuleve el maximo
            s = max(z, s + a[i] - (it->first - pre[i-len]));
            if (s == z) len = x, st.clear();
            else {
                for (int k = i-y; k <= it->second; k++)
                    st.erase({pre[k+1], k});
                len = i - it->second;
            }
            st.insert({pre[i-x+2], i-x+1});
        }
        else {
            s = max(z, s + a[i]);
            if (s == z) len = x, st.clear();
            else len++;
            st.insert({pre[i-x+2], i-x+1});
        }
        mx = max(mx, s);
    }
    cout<<mx;
}

