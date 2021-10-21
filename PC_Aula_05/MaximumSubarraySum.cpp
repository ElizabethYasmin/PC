#include <iostream>
#include <climits>
using namespace std;
typedef long long LL;
LL n, i=0, Array[200002];

void maxSumSubarray(LL *Array, LL n){
    LL bs = LLONG_MIN, cs = 0;
    for (LL i = 0; i < n; i++){
        cs = cs + Array[i];
        bs = max(bs, cs);
        cs = (cs < 0) ? 0 : cs;
    }
    cout << bs << endl;
}

//Entrada:
//8
//-1 3 -2 5 3 -5 2 2

//Salida:
//9
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (i < n){
        cin >> Array[i++];
    }
    maxSumSubarray(Array, n);
    return 0;
}