#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

void solution(vector<int> &array){
    deque<int> d;
    for(auto el : array) d.push_back(el);
    int sol = 0;
    while(d.front() != -1 && d.back() != -1){
        if(d.front() < d.back()){
            sol += d.front();
            d.pop_front();
        }else{
            sol += d.back();
            d.pop_back();
        }
    }
    cout << sol << endl;
}
int main(){
    vector<int> array = {4,-1,5,2,3};
    solution(array);
    return 0;
}