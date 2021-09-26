#include <iostream>
#include <stdlib.h>
using namespace std;
 

void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
 
   // Añadiendo el elemento presente  con elemento anterior
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}
 

int main()
{
    //Entrada: 10,4,16,20
    //Salida : 10,14,30,50
    int arr[] = { 10, 4, 16, 20 };
    const int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];
 
    fillPrefixSum(arr, n, prefixSum);
    for (int i = 0; i < n; i++)
        cout << prefixSum[i] << " ";
}