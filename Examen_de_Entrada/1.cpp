//#include <bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;

int Anagrama(string c1,string c2){
    int arreglo1[26]={0};
    int arreglo2[26]={0};
    if(c1.length()!=c2.length()){
        return 0;
    }
    for(int i=0;c1[i]!='\0';i++){
        arreglo1[c1[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(arreglo1[i]!=arreglo2[i]){
            return 0;
        }
    }
    return 1;
}
//Entrada: Sergio
          //Mano
//Salida : No anagramas
int main(){
    int n;
    string c1,c2;
    cout<<"caracter1";cin>>c1;
    cout<<"caracter2";cin>>c2;
    if(Anagrama(c1,c2)){
        cout<<"anagramas";
    }else{
        cout<<"no anagramas";
    }
}