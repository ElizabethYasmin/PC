//https://open.kattis.com/problems/dungeon

#include <iostream>
#include <queue>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int xX, yY, zZ;

bool validation(int nX, int nY, int nZ){
    return nX >= 0 && nX < xX && nY >= 0 && nY < yY && nZ >= 0 && nZ < zZ;
}

struct Position{
    Position(int x, int y, int z)
        :x(x), y(y), z(z)
        {}
        
    int x, y, z;
};

int timegood[35][35][35];
const int NumChanges = 6;
int Changex[] = {0, 0, -1, 1, 0, 0};
int Changey[] = {-1, 1, 0, 0, 0, 0};
int Changez[] = {0, 0, 0, 0, -1, 1};

int PushAlong(int xStart, int yStart, int zStart, int exitX, int exitY, int exitZ){  
    queue<Position> limit;
    limit.push(Position(xStart, yStart, zStart));
    
    while (!limit.empty())
    {
        Position current = limit.front();
        limit.pop();
        
        int nextTime = timegood[current.z][current.y][current.x] + 1;
        for (int c = 0; c < NumChanges; ++c)
        {
            int nX = current.x + Changex[c];
            int nY = current.y + Changey[c];
            int nZ = current.z + Changez[c];
            
            if (validation(nX, nY, nZ) && nextTime < timegood[nZ][nY][nX])
            {
                if (nX == exitX && nY == exitY && nZ == exitZ)
                    return nextTime;
                
                timegood[nZ][nY][nX] = nextTime;
                limit.push(Position(nX, nY, nZ));
            }
        }
    }
    return -1;
}

int main(){
    while (cin >> zZ >> yY >> xX, zZ) {
        const int size = zZ * yY * xX + 10;
        int startX, startY, startZ;
        int exitX=-1, exitY, exitZ;
        for (int z = 0; z < zZ; ++z)
        {
            for (int y = 0; y < yY; ++y)
            {
                string line;
                cin >> line;
                for (int x = 0; x < xX; ++x)
                {
                    if (line[x] == 'S')
                    {
                        startX = x;
                        startY = y;
                        startZ = z;
                        timegood[z][y][x] = 0;
                    }
                    else if (line[x] == 'E')
                    {
                        exitX = x;
                        exitY = y;
                        exitZ = z;
                        timegood[z][y][x] = size;
                    }
                    else if (line[x] == '.')
                        timegood[z][y][x] = size;
                    else
                        timegood[z][y][x] = 0;
                }
            }
        }
        
        int cost = PushAlong(startX, startY, startZ, exitX, exitY, exitZ);
        if (cost == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << cost << " minute(s)." << '\n';
    }
}