#include <iostream>

#define DAY_MAX 201
#define CHAPTER_MAX 21
using namespace std;

int N, M;
int days[CHAPTER_MAX];
int pages[CHAPTER_MAX];
int dp[CHAPTER_MAX][DAY_MAX];

void Solve()
{
    for (int leftDays = 0; leftDays <= N; ++leftDays)
    {
        for (int idx = 1; idx <= M; ++idx)
        {
            int day = days[idx];
            int page = pages[idx];
                        
            if (leftDays >= day)
                dp[idx][leftDays] = max(dp[idx - 1][leftDays], dp[idx - 1][leftDays - day] + page);
            else
                dp[idx][leftDays] = dp[idx - 1][leftDays];
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int m = 1; m <= M; ++m)
        scanf("%d %d", &days[m], &pages[m]);
        
    Solve();
    
    printf("%d\n", dp[M][N]);
    
    return 0;
}