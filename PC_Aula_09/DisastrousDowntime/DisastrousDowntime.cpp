//https://open.kattis.com/problems/downtime

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;

//Enttrada:
//2 1
//0
//1000
//Salida:
//1
int main(){
    int N, K, k=0, x;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    map<int, int> MAP;
    while (k++ < N){
        cin >> x;
        MAP[x] = (MAP[x] != 0) ? MAP[x] + 1 : 1;
        MAP[x+1000] = (MAP[x+1000] != 0) ? MAP[x+1000] -1 : -1;
    }
    vector<int> diff(MAP.size(), 0);
    int cont = 0;
    for(auto it = MAP.begin(); it != MAP.end(); it++){
        if(it == MAP.begin()) diff[cont] = it->second;
        else diff[cont] = diff[cont-1] + it->second;
        cont++;
    }
    cout << ceil(*max_element(diff.begin(), diff.end())/(float)K) << endl;
    return 0;
}