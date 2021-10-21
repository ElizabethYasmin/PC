
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <iterator>
#include <unordered_map>
using namespace std;

typedef long long v;
typedef vector<int> vi;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair


//entrada 
//4 8
//2 7 5 1

//salida
//4 2

int main() {
    v N, X;
    cin >> N >> X;
    vector<pair<int,int>> a;

    for (int i = 0; i < N; i++) {
        v x;
        cin >> x;
        a.pb({x, i + 1});
    }
    
    sort(a.begin(), a.end());
    int i = 0, j = N - 1;
    
  bool check = false;
    while (i < j) {
        if(a[i].f + a[j].f > X)
            j--;
        else if (a[i].f + a[j].f < X)
            i++;
        else if (a[i].f + a[j].f == X) {
            cout << a[i].s << " " << a[j].s;
            check = true;
      break;
        }
    }
  if(!check)
      cout << "IMPOSSIBLE" << endl;
}
