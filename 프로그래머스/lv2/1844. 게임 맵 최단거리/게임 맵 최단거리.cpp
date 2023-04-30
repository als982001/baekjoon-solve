#include <vector>
#include <queue>
using namespace std;

#define MAX 101

int R, C;
bool visited[MAX][MAX];
vector<vector<int>> map;
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

int Go()
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ { 0, 0 }, 1 });
    visited[0][0] = true;
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curTime = q.front().second;
        q.pop();
        
        if (curR == R - 1 && curC == C - 1)
            return curTime;
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nr[i];
            int nxtC = curC + nc[i];
            
            if (IsIn(nxtR, nxtC))
            {
                if (!visited[nxtR][nxtC] && map[nxtR][nxtC] == 1)
                {
                    visited[nxtR][nxtC] = true;
                    q.push({ { nxtR, nxtC }, curTime + 1});
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<vector<int>> maps)
{
    R = maps.size();
    C = maps[0].size();
    map = maps;
    
    int answer = Go();
    
    return answer;
}