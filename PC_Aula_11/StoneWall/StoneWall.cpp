
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> &H) {
    int N = H.size();
    std::stack<int> heights;
    int blocks = 0;
    for (int i=0; i<N; i++) {
        if ( !heights.size() ) {
            heights.push(H[i]);
        } else if ( H[i] == heights.top() ) {
        } else if ( H[i] > heights.top() ) {
            heights.push(H[i]);
        } else {
            while ( heights.size() && (heights.top() > H[i]) ) {
                blocks++;
                heights.pop();
            }
            if ( !heights.size() || (heights.top() != H[i]) ) {
                heights.push(H[i]);
            }
        }
    }
    
    while ( heights.size() ) {
        blocks++;
        heights.pop();
    }
    
    return blocks;
}