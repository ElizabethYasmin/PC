#include <iostream>
using namespace std;
int maxSum(int arr[], int n, int k){
    if (n < k){
       cout << "Invalido";
       return -1;
    }
    int res = 0;
    for (int i=0; i<k; i++)
       res += arr[i];
 
    int curr_sum = res;
    for (int i=k; i<n; i++){
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    }
 
    return res;
}
//Entrada: [2, 3, 4, 1, 5]
//Entrada: k: 3
//Salida: 10

int main()
{
    int arr[] = {2, 3, 4, 1, 5};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n, k);
    return 0;
}
