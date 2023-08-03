#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int R, C;
int id = 0;
int islandId[MAX][MAX];
vector<string> islands;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

int IslandDay(int r, int c)
{
    int daySum = 0;
    int currentId = id++;
    
    queue<pair<int, int>> q;
    q.push({ r, c });
    
    islandId[r][c] = currentId;
    
    while(!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        
        daySum += (islands[curR][curC] - '0');
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nr[i];
            int nxtC = curC + nc[i];
            
            if (IsIn(nxtR, nxtC))
            {
                if (islandId[nxtR][nxtC] == -1 && islands[nxtR][nxtC] != 'X')
                {
                    islandId[nxtR][nxtC] = currentId;
                    q.push({ nxtR, nxtC });
                }
            }
        }
    }
    
    return daySum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    islands = maps;
    
    R = maps.size();
    C = maps[0].size();
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            islandId[r][c] = -1;
    }
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (islandId[r][c] == -1 && islands[r][c] != 'X')
            {
                int daySum = IslandDay(r, c);
                
                answer.push_back(daySum);
            }
        }
    }
    
    if (answer.size() == 0)
        return { -1 };
    
    sort(answer.begin(), answer.end());
    
    return answer;
}