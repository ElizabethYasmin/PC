#include <iostream>
#include <climits>
using namespace std;

const int ms = 5e04 + 10;

int T,c,P,M,p, arr[ms] = {0};

void megatronRage(int *arr, int M, int P){
    
    int i, max_sum = INT_MAX, sum = 0, start = 0, max_len = 0, len=0;
    for(i=0; i<P; i++)
    {
        sum = sum + arr[i];
        len++;
        if((max_len < len && sum <=M) || (max_len == len && max_sum > sum))
        {
            max_len = len;
            max_sum = sum;
        }
        while(sum>M)
        {
            sum = sum - arr[start];
            len--;
            start++;
        }
        if ((max_len < len && sum <=M) || (max_len == len && max_sum > sum))
        {
            max_len = len;
            max_sum = sum;
        }
    }
    cout << max_sum << " " << max_len << endl;
}

//Entrada:
//3
//5 0
//1 2 3 5 6
//4 6
//1 10 2 9
//10 1
//1 7 8 9 19 11 21 8 11 0 
//Salida:
//2
//9
//13

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    cin >> T;

    while(c++ < T){
        cin >> P >> M;
        while(p < P) cin >> arr[p++];
        megatronRage(arr, M, P);
        p = 0;
    }
    
    return 0;
}