#include <string>
#define MAX 11
#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3
using namespace std;

bool visited[MAX][MAX][MAX][MAX];   // visited[a][b][x][y]: true => (a, b) => (x, y) 경로를 지났음
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

int Direction(char dir)
{
    switch(dir)
    {
        case 'D':
            return DOWN;
        case 'U':
            return UP;
        case 'L':
            return LEFT;
        case 'R':
            return RIGHT;
        default:
            return -1;
    }
}

bool IsInside(int r, int c)
{
    return 0 <= r && r < MAX && 0 <= c && c < MAX;
}

int solution(string dirs) {
    int answer = 0;
    
    int curR = 5;
    int curC = 5;
    
    for (int i = 0; i < dirs.length(); ++i)
    {
        int dir = Direction(dirs[i]);
        
        int nxtR = curR + nr[dir];
        int nxtC = curC + nc[dir];
        
        if (IsInside(nxtR, nxtC) == false)
            continue;
        
        if (visited[curR][curC][nxtR][nxtC] == false)
        {
            visited[curR][curC][nxtR][nxtC] = true;
            visited[nxtR][nxtC][curR][curC] = true;
            ++answer;
        }
        
        curR = nxtR;
        curC = nxtC;
    }
    
    return answer;
}