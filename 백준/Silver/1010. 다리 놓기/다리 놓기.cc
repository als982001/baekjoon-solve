#include <iostream>
#include <memory.h>
#define MAX 31

using namespace std;

int T, N, M;
int dp[MAX][MAX];

int Solve()
{
    for (int eastIdx = 1; eastIdx <= M; ++eastIdx)
        dp[1][eastIdx] = eastIdx;
        
    for (int westIdx = 2; westIdx <= N; ++westIdx)
    {
        for (int eastIdx = westIdx; eastIdx <= M; ++eastIdx)
        {
            for (int targetEastIdx = eastIdx; westIdx <= targetEastIdx; --targetEastIdx)
                dp[westIdx][eastIdx] += dp[westIdx - 1][targetEastIdx - 1];
        }
    }
    
    return dp[N][M];
}

int main()
{
    scanf("%d", &T);
    
    while(T--)
    {
        memset(dp, 0, sizeof(dp));
        
        scanf("%d %d", &N, &M);
        
        int answer = Solve();
        
        printf("%d\n", answer);
    }
    
    return 0;
}