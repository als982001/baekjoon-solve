#include <string>
#include <vector>

#define MAX 7

using namespace std;

int R, C;
int dirs[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int board[MAX][MAX];

bool IsIn(int r, int c)
{
    return 0 <= r && r < R && 0 <= c && c < C;
}

pair<bool, int> Solve(pair<int, int> myLoc, pair<int, int> enemyLoc)
{
    int r = myLoc.first;
    int c = myLoc.second;
    
    // 발판이 사라진 곳이라면 이길 수 없는 곳
    if (board[r][c] == 0)
        return { false, 0 };
    
    bool canWin = false; // 이길 수 있는 루트가 하나라도 있는지
    int minTurn = 9999; // 이기는 경우 최소 턴
    int maxTurn = 0; // 지는 경우 최대 턴
    
    bool canGo = false; // 갈 곳이 한 군데라도 있는지
    
    for (int i = 0; i < 4; ++i)
    {
        int nxtR = r + dirs[i][0];
        int nxtC = c + dirs[i][1];
        
        if (IsIn(nxtR, nxtC) && board[nxtR][nxtC] == 1)
        {
            canGo = true;
            
            // 현재 내 발판을 지우고 이동
            board[r][c] = 0;
            
            // 턴 넘기기: (상대 위치, 내 새로운 위치)
            pair<bool, int> result = Solve(enemyLoc, { nxtR, nxtC });
            
            // 백트래킹 (발판 복구)
            board[r][c] = 1;
            
            if (result.first == false)
            {
                // 상대방이 지는 경우 -> 내가 이기는 경우
                canWin = true;
                
                // 이길 때는 가장 빠르게 이겨야 한다.
                minTurn = min(minTurn, result.second);
            }
            else 
            {
                // 상대방이 이기는 경우 -> 내가 지는 경우
                // (이미 canWin이 true라면, 굳이 지는 경우인 maxTurn을 갱신할 필요도 사실 없음.
                //  나는 어차피 이기는 길(minTurn)을 택할 거니까.)
                
                // 지는 경우 최대 턴으로 버텨야 한다.
                maxTurn = max(maxTurn, result.second);
            }
        }
    }
    
    // 갈 곳이 없으면 패배
    if (canGo == false)
        return { false, 0 };
    
    // 이번 턴 +1을 해서 반환 (result.second는 다음 턴부터의 횟수. 이번에는 내가 움직였으니 리턴할 때 +1해야 함)
    if (canWin)
        return { true, minTurn + 1 };
    else
        return { false, maxTurn + 1 };
}

int solution(vector<vector<int>> inputBoard, vector<int> aloc, vector<int> bloc) {
    R = inputBoard.size();
    C = inputBoard[0].size();
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
            board[r][c] = inputBoard[r][c];
    }
    
    pair<bool, int> result = Solve({ aloc[0], aloc[1] }, { bloc[0], bloc[1] });
    
    return result.second;
}