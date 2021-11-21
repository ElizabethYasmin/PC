#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std; 

#define pb push_back

int main() {
    int cases;
    cin >> cases;
    while(cases--) {
        string command;
        cin >> command;

        int n;
        cin >> n;

        deque<int> d;
        cin.ignore();
        for(int i = 0; i < n; i++) {
            cin.ignore();
            int t;
            cin >> t;
            d.pb(t);
        }
        cin.ignore();
        if(n == 0) {
            cin.ignore();
        }

        bool beg = true;
        bool printed = false;
        for(auto i : command) {
            if(i == 'R') {
                beg = !beg;
            }
            if(i == 'D') {
                if(d.size() == 0) {
                    printed = true;
                    cout << "error" << endl;
                    break;
                }
                else {
                    if(beg) {
                        d.pop_front();
                    }
                    else {
                        d.pop_back();
                    }
                }
            }
        }

        if(!printed) {
            cout << "[";
            while(!d.empty()) {
                if(beg) {
                    cout << d.front();
                    d.pop_front();
                }
                else {
                    cout << d.back();
                    d.pop_back();
                }

                if(d.size() != 0) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}
