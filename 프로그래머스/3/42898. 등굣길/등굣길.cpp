#include <string>
#include <vector>
#include <iostream>

#define MAX 101
#define MOD 1000000007

using namespace std;

int dp[MAX][MAX]; // (r, c)를 갈 수 있는 횟수 저장. -1이면 못 가는 곳

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    int maxR = n;
    int maxC = m;
    
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            dp[r][c] = 0;
    }
    
    for (vector<int> puddle : puddles)
    {
        int r = puddle[1];
        int c = puddle[0];
        
        dp[r][c] = -1; // -1이면 못 가는 곳
    }
    
    dp[1][1] = 1;
    
    for (int r = 1; r <= maxR; ++r)
    {
        for (int c = 1; c <= maxC; ++c)
        {  
            if (dp[r][c] == -1)
                continue;
            
            if (dp[r - 1][c] != -1)
                dp[r][c] = (dp[r][c] + dp[r - 1][c]) % MOD;
            
            if (dp[r][c - 1] != -1)
                dp[r][c] = (dp[r][c] + dp[r][c - 1]) % MOD;
        }
    }
    
    answer = dp[maxR][maxC];
    
    
    return answer;
}