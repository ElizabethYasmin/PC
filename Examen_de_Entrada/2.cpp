/******************************************************************************
2. Escriba una función para eliminar elementos
duplicados de una lista enlazada no ordenada.
*******************************************************************************/
#include<iostream>
#include<string.h>
using namespace std;
int n, elem[30],elemen_n[50];
void ascending(){
    int k=0;
    for(int i=0;i<50;i++){
        if(elemen_n[i]){
            elem[k]=i;
            k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<elem[i]<<" ";

    }

}
void disorderly(){
    for(int i=0;i<n;i++){
        if(elemen_n[elem[i]]){
            cout<<elem[i]<<" ";
            elemen_n[elem[i]]--;
        }
    }
}
int main(){
    cin>>n;
    memset(elemen_n,0,sizeof(elemen_n));
    for(int i=0;i<n;i++){
        cin>>elem[i];
        if(! elemen_n[elem[i]]){
            elemen_n[elem[i]]++;
        }
    }
    
    //Entrada n-> 5
    // 1 2 4 4 8
    //Salida 1 2 4 8
    disorderly();
}

