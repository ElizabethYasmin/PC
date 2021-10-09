#include <bits/stdc++.h>
using namespace std;
 
void sortSquares(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];
 
    sort(arr, arr + n);
}

//Entrada: [-4, -3, 1, 2, 3]
//Salida: [1, 4, 9, 9, 16]

int main()
{
    int arr[] = { -4, -3, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Sin ordenar" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    sortSquares(arr, n);
 
    cout << "\nOrdenado" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}