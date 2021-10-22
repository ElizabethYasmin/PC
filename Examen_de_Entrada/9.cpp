
/*Escriba una función que genere el numero n de la secuencia Fibonacci
*/
#include <stdlib.h>
#include <iostream>
using namespace std;
 int fibonacc(int n){
     if(n<=2){
         return 1;
     }else{
         return fibonacc(n-1)+fibonacc(n-2);
     }
 }
 int main(){
     int n=0;
     cout<<"fibonacci";cin>>n;
     int respuesta=fibonacc(n);
     cout<<n<<"->"<<respuesta;
     //Caso prueba
     //Entrada 10
     //Salida 55
     return 0;
 }
