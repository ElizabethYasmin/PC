//https://www.beecrowd.com.br/judge/en/problems/view/2792

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef map<ll, ll> um;

const int MAXN = 5e5 + 10;
um umap;
ll arr[MAXN];
ll N;

void solve(){
    for(int i=0; i<N; i++){
        int x = arr[i];
        um::iterator it, it2 = umap.find(x);
        it = it2;
        it++;
        for(; it != umap.end(); it++){
            it->second--;
        }
        cout << it2->second + 1 << " ";
        umap.erase(it2);
    }
    cout << endl;
}

int 
main(int argc, char const *argv[])
{
    cin >> N;
    for(int i=0; i<N; i++)
        umap[i+1] = i;
    //print umap
    /* for(auto it = umap.begin(); it != umap.end(); it++){
        cout << it->first << " " << it->second << endl;
    } */
    for(int i=0; i<N; i++)
        cin >> arr[i]; 
    solve();

    return 0;
}








