#include <iostream>

using namespace std;

#define MAX 10001

int N;                  // N: 최대 공부 시간
int K;                  // K: 과목 수
int importances[MAX];   // 중요도
int times[MAX];         // 필요한 공부 시간
int dp[1001][MAX];

void Init()
{
    for (int b = 0; b < MAX; ++b)
    {
        importances[b] = 0;
        times[b] = 0;
        
        for (int a = 0; a < 1001; ++a)
            dp[a][b] = 0;
    }
}

void Solve()
{
    for (int maxStudyTime = 0; maxStudyTime <= N; ++maxStudyTime)
    {
        for (int idx = 1; idx <=  K; ++idx)
        {
            int currentImportance = importances[idx];
            int currentTime = times[idx];
            
            if (maxStudyTime >= currentTime)
                dp[idx][maxStudyTime] = max(dp[idx - 1][maxStudyTime], dp[idx - 1][maxStudyTime - currentTime] + currentImportance);
            else
                dp[idx][maxStudyTime] = dp[idx - 1][maxStudyTime];
        }
    }
}

int main()
{
    Init();
    
    scanf("%d %d", &N, &K);
    
    for (int idx = 1; idx <= K; ++idx)
        scanf("%d %d", &importances[idx], &times[idx]);
  
    Solve();
    
    printf("%d\n", dp[K][N]);

    return 0;
}