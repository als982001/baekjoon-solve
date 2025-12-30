#include<vector>
#include <queue>

#define MAX 101

using namespace std;

int R, C;
int visited[MAX][MAX];
int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool IsIn(int r, int c)
{
    return 0 <= r && r <= R && 0 <= c && c <= C;
}

int Visit(vector<vector<int>>& maps)
{
    int minTimes = 0;
    
    queue<pair<pair<int, int>, int>> q;
    
    q.push({ { 0, 0 }, 0 });
    
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int times = q.front().second;
        
        q.pop();
        
        if (r == R && c == C)
        {
            minTimes = times;
            break;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = r + dirs[i][0];
            int nxtC = c + dirs[i][1];
            int nxtTimes = times + 1;
            
            if (IsIn(nxtR, nxtC) && maps[nxtR][nxtC] == 1 && visited[nxtR][nxtC] > nxtTimes)
            {
                visited[nxtR][nxtC] = nxtTimes;
                q.push({ { nxtR, nxtC }, nxtTimes });
            }
        }
    }
    
    return minTimes;
}

int solution(vector<vector<int> > maps)
{    
    R = maps.size() - 1;
    C = maps[0].size() - 1;
    
    for (int r = 0; r <= R; ++r)
    {
        for (int c = 0; c <= C; ++c)
        {
            visited[r][c] = MAX * MAX;   
        }
    }
    
    visited[0][0] = 0;
    
    int answer = Visit(maps);
    
    if (answer == 0)
        return -1;
    
    return answer + 1;
}






















/*

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

*/