#include <iostream>
using namespace std;

bool is_eq(string arr,int pos,int j){
    int n=arr.length();
    for(int i=0;i<n;i++){
        if(arr[(pos+i)%n] != arr[(j+i)%n]){
            if(arr[(pos+i)%n]<arr[(j+i)%n]){return true;}return false;}
    }return false;
}

int main(){
    int t=0;
    string arr,out;
    cin>>t;
    for(int i=0; i<t;i++){
        out="";
        cin>>arr;
        int pos=0;
        for(int j=0; j<arr.length();j++){
            if(is_eq(arr,j,pos)==true){pos=j;}
        }
        for(int j=0;j<arr.length();j++){
            out+=arr[(pos+j)%arr.length()];
        }cout<<out<<"\n";
    }
    return 0;
}