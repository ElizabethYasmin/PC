#include <iostream> 
#include <string.h> 
using namespace std;
int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        bool win[n + 1];
        memset(win, 0, sizeof win);
        int moves[m];
        for(int i = 0; i < m; i++) {cin >> moves[i];}
        for(int i = 0; i < (n + 1); i++){
            if(!win[i]){
                for(int j = 0; j < m; j++){
                    if(i + moves[j] < (n + 1)){
                        win[i + moves[j]] = true;
                    }
                }
            }
        }
        if(win[n]){cout << "Stan wins" << endl;} 
		else{cout << "Ollie wins" << endl;}
    }
    return 0;
}