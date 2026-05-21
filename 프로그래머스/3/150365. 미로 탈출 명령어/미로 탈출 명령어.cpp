#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

#define MAX 51

using namespace std;

map<char, pair<int, int>> dirToCoord;
char dirs[4] = { 'd', 'l', 'r', 'u' };
string visited[MAX][MAX];

bool IsIn(int r, int c, int R, int C)
{
    return 1 <= r && r <= R && 1 <= c && c <= C;
}

bool CanVisit(int r, int c, string path)
{
    if (visited[r][c] == "")
        return true;
    
    if (visited[r][c].size() < path.size())
        return true;
    
    return visited[r][c] > path;
}

string solution(int R, int C, int startR, int startC, int endR, int endC, int targetMove) {
    string answer = "";
    
    dirToCoord['l'] = { 0, -1 };
    dirToCoord['r'] = { 0, 1 };
    dirToCoord['u'] = { -1, 0 };
    dirToCoord['d'] = { 1, 0 };
    
    queue<pair<pair<int, int>, pair<int, string>>> q;
    q.push({ { startR, startC }, { 0, "" } });
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curMove = -q.front().second.first;
        string curPath = q.front().second.second;
    
        q.pop();
        
        if (curMove == targetMove)
        {
            if (curR == endR && curC == endC)
            {
                if (answer == "" || answer > curPath)
                    answer = curPath;
            }
            
            continue;
        }
        
        // 만약 현재 -> 목표 지점까지 최단으로 가도 targetMove 내에 못 갈 경우 제외
        if (abs(endR - curR) + abs(endC - curC) + curMove > targetMove)
            continue;
           
        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> dirCoord = dirToCoord[dirs[i]];
            
            int nxtR = curR + dirCoord.first;
            int nxtC = curC + dirCoord.second;
            string nxtPath = curPath + dirs[i];
            
            if (IsIn(nxtR, nxtC, R, C) && CanVisit(nxtR, nxtC, nxtPath))
            {
                q.push({ { nxtR, nxtC }, { -(nxtPath.size()), nxtPath }});
                visited[nxtR][nxtC] = nxtPath;
            }
        }
    }
    
    if (answer == "")
        answer = "impossible";
    
    return answer;
}