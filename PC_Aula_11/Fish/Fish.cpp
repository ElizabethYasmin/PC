#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    struct FishStruct {
      int size;
      int direction;
    };

    std::stack<FishStruct> fishes;

    int N = A.size();
    
    for (int i=0; i<N; i++) {
        if ( fishes.empty() ) {
            FishStruct fish{A[i], B[i]};
            fishes.push(fish);
            continue;
        }
        
        bool eaten = false;
        do {
            FishStruct lastFish = fishes.top();
            if ( lastFish.direction == B[i] ) {
                break;
            }
            if ( !lastFish.direction && B[i] ) {
                break;
            }
             eaten = false;
            if ( A[i] > lastFish.size ) {
                fishes.pop();
            } else {
                eaten = true;
            }
        } while (!fishes.empty() && !eaten);
        if ( !eaten) {
            FishStruct fish{A[i], B[i]};
            fishes.push(fish);
        }
        
    }

    return fishes.size();
}