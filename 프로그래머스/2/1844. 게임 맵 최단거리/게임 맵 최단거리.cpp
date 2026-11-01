#include <vector>
#include <queue>
#include <iostream>
#define MAX 101

using namespace std;

int R, C;
int visited[MAX][MAX];
int nxtDir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool IsIn(int r, int c)
{
    return 0 <= r && r <= R && 0 <= c && c <= C;
}

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    
    R = maps.size() - 1;
    C = maps[0].size() - 1;
    
    for (int r = 0; r <= R; ++r)
    {
        for (int c = 0; c <= C; ++c)
            visited[r][c] = 0;
    }
    
    queue<pair<pair<int, int>, int>> q;
    q.push({ { 0, 0 }, 1 });
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curTime = q.front().second;
        
        q.pop();
        
        if (curR == R && curC == C)
        {   
            answer = curTime;
            break;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nxtDir[i][0];
            int nxtC = curC + nxtDir[i][1];
            int nxtTime = curTime + 1;
            
            if (IsIn(nxtR, nxtC)
               && (visited[nxtR][nxtC] == 0 || visited[nxtR][nxtC] > nxtTime)
               && maps[nxtR][nxtC] == 1)
            {
                visited[nxtR][nxtC] = nxtTime;
                q.push({ { nxtR, nxtC }, nxtTime });
            }
            
        }
    }
    
    
    return answer;
}