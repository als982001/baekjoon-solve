#include <iostream>
#include <queue>

#define MAX 5

using namespace std;

int board[MAX][MAX];
bool success = false;
bool visited[MAX][MAX];
int nxtDir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool IsIn(int r, int c)
{
    return 0 <= r && r < MAX && 0 <= c && c < MAX;
}

void Check(int r, int c, int eatenApples, int moveCount)
{
    if (success)
        return;
    
    if (moveCount > 3)
        return;
        
    if (eatenApples >= 2)
    {
        success = true;
        return;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nxtR = r + nxtDir[i][0];
        int nxtC = c + nxtDir[i][1];
        
        if (IsIn(nxtR, nxtC) && board[nxtR][nxtC] != -1 && visited[nxtR][nxtC] == false)
        {
            visited[nxtR][nxtC] = true;
            
            // board[nxtR][nxtC]이 사과가 있으면 1이고 없으면 0 => eatenApples + board[nxtR][nxtC]
            Check(nxtR, nxtC, eatenApples + board[nxtR][nxtC], moveCount + 1);
            
            visited[nxtR][nxtC] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    int startR, startC;
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            cin >> board[r][c];
    }
    
    cin >> startR >> startC;
    
    visited[startR][startC] = true;
    Check(startR, startC, board[startR][startC], 0);
    
    if (success) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    
    return 0;
}