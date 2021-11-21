#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> DFS; DFS.push(0);
        unordered_set<int> seen = {0};
        while (!DFS.empty()) {
            int i = DFS.top(); DFS.pop();
            for (int j : rooms[i])
                if (seen.count(j) == 0) {
                    DFS.push(j);
                    seen.insert(j);
                    if (rooms.size() == seen.size()) return true;
                }
        }
        return rooms.size() == seen.size();
    }

    int main(){

    }