//Prefix sums
//#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int a[100006];
int n;
int l,r;
int q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;
    }
    return 0;
}
