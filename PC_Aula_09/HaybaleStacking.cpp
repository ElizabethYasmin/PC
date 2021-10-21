#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k, x, y;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    vector<int> diff(n, 0);
    vector<int> array(n, 0);

    while(k--){
        cin >> x >> y;
        diff[x-1]++; diff[y]--;
    }
    
    array[0] = diff[0];
    for(int i=1; i<n; i++){
        array[i] = array[i-1] + diff[i];
    }

    sort(array.begin(), array.end());

    if(n%2==0){
        cout << (array[(n/2) - 1] + array[n/2])/2.0 << endl; 
    } 
    else{
        cout << array[(n+1)/2 -1] << endl;
    } 

    return 0;
}