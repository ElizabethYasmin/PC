//https://open.kattis.com/problems/oddmanout
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int casos,caso,p;
    cin>>casos;
    for(int i=0;i<casos;i++){
        cin>>caso;vector<int> v;
        for(int j=0;j<caso;j++) {cin>>p;v.push_back(p);}
        sort(v.begin(),v.end());
        bool found=false;
        int j=0;
        while(j<=caso-1 && !found){
            if(j==0&&v[j]!=v[j+1]){cout<<"Case #"<<i+1<<": "<<v[j]<<"\n";found=true;}
            else if(j>0&&j<caso-2&&v[j-1]!=v[j]&&v[j]!=v[j+1]){cout<<"Case #"<<i+1<<": "<<v[j]<<"\n";found=true;}
            else if(j==caso-1&&v[j]!=v[j-1]){cout<<"Case #"<<i+1<<": "<<v[j]<<"\n";found=true;}j++;
        }
    }
    return 0;
}