#include <string>
#include <vector>

using namespace std;

int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

int GetNextDirIdx(int dirIdx)
{
    if (dirIdx >= 3)
        return 0;
    
    return dirIdx + 1;
}

bool IsIn(int r, int c, int n)
{
    return 0 <= r && r < n && 0 <= c && c < n;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int r = 0;
    int c = 0;
    int dirIdx = 0;
    int num = 1;
    int maxNum = n * n;
    
    while(num <= maxNum)
    {
        answer[r][c] = num++;
        
        int nxtR = r + dir[dirIdx][0];
        int nxtC = c + dir[dirIdx][1];
        
        if (IsIn(nxtR, nxtC, n) == false || answer[nxtR][nxtC] > 0)
        {
            dirIdx = GetNextDirIdx(dirIdx);
            
            nxtR = r + dir[dirIdx][0];
            nxtC = c + dir[dirIdx][1];
        }
        
        r = nxtR;
        c = nxtC;
    }
    
    return answer;
}