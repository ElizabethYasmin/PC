#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
const int MS = 10e5+10;
int n, x, arr[MS];

void SOLUTION(int *arr, int &N){
    int time = 0;
    vector<vector<int>> ans;
    vector<int> tmp;
    queue<int> q;
    while(true){
        int ops = 0;
        vector<int> aux;
        if(time != 0){
            N = q.size();
            for(int i=0; i<N; i++){
                arr[i] = q.front();
                q.pop();
                tmp.pop_back();
            }
        }

        for(int i=0; i<N; i++){
            bool isdel = false;
            if(i==0 && N > 1 && arr[i] < arr[i+1]){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }else if(i==N-1 && N > 1 && arr[i] < arr[i-1]){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }else if(N > 2 && (arr[i] < arr[i-1] || arr[i] < arr[i+1])){
                ops++;
                isdel = true;
                aux.push_back(arr[i]);
            }
            if(!isdel){
                q.push(arr[i]);
                tmp.push_back(arr[i]);
            }
        }
        if(ops == 0) break;
        else{
            time++;
            cout << endl;
            ans.push_back(aux);
        }
    }
    cout << time << endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0; i<tmp.size(); i++){
        cout << tmp[i] << " ";
    }
    cout << endl;
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    SOLUTION(arr, n);
    return 0;
}