#include <string>
#include <vector>
#include <iostream>

using namespace std;

int LEN = 0;

int dir[9][2] = { 
    { -1, -1 }, { -1, 0 }, { -1, 1 }, 
    { 0, -1 }, { 0, 0 }, { 0, 1 }, 
    { 1, -1 }, { 1, 0 }, { 1, 1 }
};

bool safeZone[101][101];

bool IsIn(int r, int c)
{
    return 0 <= r && r < LEN && 0 <= c && c < LEN;
}

void CheckDangerousZone(int r, int c)
{
    
    for (int i = 0; i < 9; ++i)
    {
        int targetR = r + dir[i][0];
        int targetC = c + dir[i][1];
        
        if (IsIn(targetR, targetC))
            safeZone[targetR][targetC] = false;       
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    LEN = board.size();
    
    for (int r = 0; r < LEN; ++r)
    {
        for (int c = 0; c < LEN; ++c)
            safeZone[r][c] = true;
    }
    
    for (int r = 0; r < LEN; ++r)
    {
        for (int c = 0; c < LEN; ++c)
        {
            if(board[r][c] == 1)
                CheckDangerousZone(r, c);
        }
    }
    
    for (int r = 0; r < LEN; ++r)
    {
        for (int c = 0; c < LEN; ++c)
        {
            if (safeZone[r][c])
                ++answer;
        }
    }
    
    return answer;
}