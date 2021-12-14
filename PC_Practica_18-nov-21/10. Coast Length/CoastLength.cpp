/* #include <stdio.h>


int edgeCount(int, int, char*);
int topToBottomCount(int, int, char*);
int leftToRightCount(int, int, char*);
int removingInsides(int, int, char*);

int main()
{
    int n = 0; // number of strings
    int m = 0; // strings lenghts
    //printf("Enter N(number of strings) x M(strings lenght): ");
    scanf("%d", &n);
    scanf("%d", &m);

    char coast[1024];
    for(int i = 0; i < n; i++){ 
        scanf("%s", coast+i*m); // adding strings to char coast[1024], making array of ones and zeroes // e.g we are adding 3x4 strings - 111100001111
    }                                                                                                  // it can also be looked as  1111
                                                                                                                            //      0000        - matrix
    int coasts = edgeCount(n, m, coast);                                                                                    //      1111 
    coasts += topToBottomCount(n, m, coast);
    coasts += leftToRightCount(n, m, coast);
    coasts -= removingInsides(n, m, coast);

    printf("%d - coasts\n", coasts);

    return 0;
}

int edgeCount(int n, int m, char *coast){ // if 1 is placed at the edge of the "map", it is 1 coast (2 if it is at corner)
    int edgeCoast = 0;

    for(int i = 0; i < m; i++){     // top edges
        if(coast[i] == '1')
            edgeCoast++;
    }

    for(int i = m*n - m; i < m*n; i++){  // bottom edges (m*n - m = first char in the last string, it can be also looked as the last row in matrix)
        if(coast[i] == '1')
            edgeCoast++;
    }

    for(int i = 0; i <m*n; i+=m){   // left side edges (first column in matrix)
        if(coast[i] == '1')
            edgeCoast++;
    }

    for(int i = m-1; i < m*n; i+=m){ // right side edges (last column in matrix)
        if(coast[i] == '1')
            edgeCoast++;
    }

    return edgeCoast;
}

int topToBottomCount(int n, int m, char *coast){
    int coasts = 0;
    for(int i = 0; i < m*n - m; i++){   // we start from first char in "matrix", and move to the (m*n - m = 2nd last "row")
        if(coast[i] ^ coast[i+m])   // we are checking if zero is placed above one or via versa
            coasts++;
    }

    return coasts;
}

int leftToRightCount(int n, int m, char* coast){
    int coasts = 0;
    int p = m-1;
    for(int i = 0; i < n*m; i++){       // we start from the first charr, and we are going trough whole matrix, but the last column
        if(i == p){                     // p = m - 1 (last char in first row)
            p+=m;                       // p+=m (last char in next column, and so on)
            continue;                   // we move to next iteration
        }#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

void coastLength(vector<vector<int>> &mmap, int n, int m){
    static vector<vector<int>> offsets = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    vector<pair<int, int>> unvisited;
    unvisited.push_back(make_pair(0, 0));
    int sccount = 0;
    while(!unvisited.empty()){
        int posY = unvisited.back().first;
        int posX = unvisited.back().second;
        unvisited.pop_back();
        mmap[posY][posX] = 2;
        for(auto &offset : offsets){
            pair<int,int> tloc = make_pair(posY + offset[0], posX + offset[1]);
            if(tloc.first < 0 || tloc.first >= n || tloc.second < 0 || tloc.second >= m) continue;
            else{
                if (mmap[tloc.first][tloc.second] == 0 && (find(unvisited.begin(), unvisited.end(), tloc) == unvisited.end())){
                    unvisited.push_back(tloc);
                }else if(mmap[tloc.first][tloc.second] == 1){
                    sccount++;
                }
            }
            
        }
    }

    cout << sccount << endl;
}

int main(){
    int n, m;
    string strLine;
    cin >> n >> m;
    vector<vector<int>> mmap(n+2, vector<int>(m+2, 0));
    for(int i=1; i<=n; i++){
        cin >> strLine;
        int j=1;
        for(auto car : strLine)
            mmap[i][j++] = (car == '0') ? 0 : 1;
    }
    coastLength(mmap, n + 2, m + 2);
    return 0;
}

        if(i == m*n - 1)                //if we are at last char in matrix, we break out from loop
            break;

        if(coast[i] ^ coast[i+1])
            coasts++;
    }

    return coasts;
}

int removingInsides(int n, int m, char* coast){ // Lakes and islands in lakes are not contributing to the sea coast. we are checking if they exist.
    int innerCoasts = 0;
    for(int i = m + 1; i < n*m - m - 1; i ++){
        if( coast[i] == '0' && coast[i] ^ coast[i-1] && coast[i] ^ coast[i+1] && coast[i] ^ coast[i-m] && coast[i] ^ coast[i+m]) // char has to be 0, and to hist left, right, above and under there has to be 1
            innerCoasts++;
    }

    return innerCoasts * 4; // *4 because we added 4 coasts before for each island.
} */