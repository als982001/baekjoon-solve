#include <string>
#include <vector>
#include <queue>

#define MAX 101
#define INF 987654321

using namespace std;

int R, C;
int startR, startC;
int endR, endC;
int nxtDir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int visited[MAX][MAX];

bool IsIn(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

bool ValidCell(int r, int c, vector<string> board)
{
    return IsIn(r, c) && board[r][c] != 'D';
}

pair<int, int> Slide(int r, int c, int dirIdx, vector<string> board)
{
    pair<int, int> nxtPos = { r, c };
    
    while(ValidCell(nxtPos.first, nxtPos.second, board))
    {
        nxtPos.first += nxtDir[dirIdx][0];
        nxtPos.second += nxtDir[dirIdx][1];
    }
    
    nxtPos.first -= nxtDir[dirIdx][0];
    nxtPos.second -= nxtDir[dirIdx][1];
    
    return nxtPos;
}

int solution(vector<string> board) 
{
    int answer = INF;
    
    R = board.size();
    C = board[0].size();
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            visited[r][c] = INF;
    }
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (board[r][c] == 'R')
            {
                startR = r;
                startC = c;
            }
            else if (board[r][c] == 'G')
            {
                endR = r;
                endC = c;
            }
        }
    }
    
    queue<pair<pair<int, int>, int>> q;
    
    q.push({ { startR, startC }, 0 });
    visited[startR][startC] = 0;
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curT = q.front().second;
        
        q.pop();
        
        if (curR == endR && curC == endC)
        {
            answer = min(answer, curT);
            continue;
        }
        
        for (int idx = 0; idx < 4; ++idx)
        {
            pair<int, int> nxtPos = Slide(curR, curC, idx, board);
            
            if (ValidCell(nxtPos.first, nxtPos.second, board) && visited[nxtPos.first][nxtPos.second] > curT + 1)
            {
                visited[nxtPos.first][nxtPos.second] = curT + 1;
                q.push({ { nxtPos.first, nxtPos.second }, curT + 1 });
            }
        }
    }
    
    if (answer == INF)
        return -1;
    
    return answer;
}