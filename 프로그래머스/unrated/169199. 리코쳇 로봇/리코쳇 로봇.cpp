#include <string>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int R, C;
int startR, startC, endR, endC;
bool visited[MAX][MAX];
vector<string> originalBoard;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

void Init(vector<string> board)
{
    R = board.size();
    C = board[0].size();
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
            visited[r][c] = false;
    }
}

bool IsInside(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

int Check(vector<string> board)
{
    queue<pair<pair<int, int>, int>> q;
    q.push({ { startR, startC }, 0 });
    
    visited[startR][startC] = true;
    
    while(!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curMove = q.front().second;
        q.pop();
        
        if (curR == endR && curC == endC)
            return curMove;
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR;
            int nxtC = curC;
            
            while(true)
            {
                if (IsInside(nxtR, nxtC) == false)
                    break;
                if (board[nxtR][nxtC] == 'D')
                    break;
                    
                nxtR += nr[i];
                nxtC += nc[i];
            }
  
            nxtR -= nr[i];
            nxtC -= nc[i];
            
            if (IsInside(nxtR, nxtC))
            {
                if (visited[nxtR][nxtC] == false && board[nxtR][nxtC] != 'D')
                {
                    visited[nxtR][nxtC] = true;
                    q.push({ { nxtR, nxtC }, curMove + 1 });
                }
            }
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    
    Init(board);
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (board[r][c] == 'R')
            {
                startR = r;
                startC = c;
            }
            if (board[r][c] == 'G')
            {
                endR = r;
                endC = c;
            }
        }
    }
    
    answer = Check(board);
    
    return answer;
}