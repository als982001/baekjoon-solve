#include <string>
#include <vector>

using namespace std;

#define MAX 101
#define MOD 1000000007

int R, C;
bool isPuddle[MAX][MAX];
int dp[MAX][MAX];

bool IsIn(int r, int c)
{
    return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Go(int r, int c)
{
    if (IsIn(r, c) == false)
        return 0;
    
    if (isPuddle[r][c] == true)
        return 0;
    
    if (dp[r][c] > -1)
        return dp[r][c];
    
    if (r == 1 && c == 1)
        return 1;
    
    int& curDp = dp[r][c];
    curDp = 0;
    
    curDp += (Go(r - 1, c) + Go(r, c - 1)) % MOD;
    
    return curDp % MOD;
    
}

int solution(int m, int n, vector<vector<int>> puddles) {
    R = n;
    C = m;
    
    for (int i = 0; i < puddles.size(); ++i)
    {
        int puddleR = puddles[i][1];
        int puddleC = puddles[i][0];
        
        isPuddle[puddleR][puddleC] = true;
    }
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            dp[r][c] = -1;
    }
    
    int answer = Go(R, C);
    
    return answer;
}