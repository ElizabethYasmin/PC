/******************************************************************************

Dados dos arrays ordenados A y B con n y m valores respectivamente. Considere que el array A tiene espacio
suficiente para contener a los elementos de B. Escriba una función que copie los elementos de B en A
manteniendo el orden

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

void merge(int A[],int m, int B[],int n){
    
    //int tamanio = sizeof A/sizeof A[0];
    int index = A.length - 1;
    int curA=m-1;
    int curB=n-1;
    while(curA>=0 && curB>=0){
        if(A[curA]>B[curB]){
            A[index--]=A[curA--];
        }else{
            A[index--]=B[curB--];
        }
    }
    
    while(curA>=0){
        A[index--]=A[curA--];
    }
    
    while(curB>=0){
        A[index--]=B[curB--];
    }
    
}

int main()
{

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    merge(array,10,array2,10);

    return 0;
}
