#include <iostream>
#include <cmath>
using namespace std;

int tc, n, res, i;
double  a, b, c, aux, tmp;

int main(){
    cin >> tc;
    while(tc--){
        cin >> n;
        aux = -999999.0;
        res = 0;
        for(i=0; i<n; i++){
            cin >> a >> b >> c;
            tmp = pow(b,2)/(4*a) + c;
            if(tmp > aux){aux = tmp;res = i;
            }
        }
        cout << res+1 << endl;
    }
    return 0;
}