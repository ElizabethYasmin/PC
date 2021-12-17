#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;

//#define EPS  2.7182818284590452353602
//#define PI  3.1415926535897932384626
int num;
long double aux;
long long cantDigits2(int &n){
    if(n <= 1){return 1;}
    aux = 0;
    for(int i=1; i<=n; i++){aux += log10(i);}
    return (long long)floor(aux) + 1;
}

long long cantDigits(int n){
    if (n <= 1)
        return 1;
    long double x = ((n * log10(n / M_E) + log10(2 * M_PI  * n) / 2.0));
    return floor(x) + 1;
}


int main(){
    unordered_map <long long, long long> mp;
    while(cin >> num){
        if (mp[num]){cout << mp[num] << endl;}
        else{
            mp[num] = cantDigits(num);
            cout << mp[num] << endl;
        }
    }
    return 0;
}