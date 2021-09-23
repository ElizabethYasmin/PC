/******************************************************************************
8.
Escriba una función que determine el número de bits requeridos para transformar un numero entero A en un
numero entero B. Ejemplo
Input: 31, 14
Output: 2
*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int bit(int a,int b){
    int temp=a^b;
    int cnt=0;
    while(temp){
        temp &=(temp-1);
        //usando, nun & (num-1) se puede eliminar num más a la derecha 1, calculado en el temp 1 Número.
        cnt++;
    }
    return cnt;
}
int main()
{
    //Entrada 3,14
    //Salida 2
    cout<<bit(31,14);

    return 0;
}

