#include <iostream>

using namespace std;

#define MAX 987654321

int N, T;
int penaltiesSum = 0;
int days[1001];
int penalties[1001];
int dp[1001][1001];

void Solve()
{
    for (int leftDay = 0; leftDay <= T; ++leftDay)
    {
        for (int idx = 1; idx <= N; ++idx)
        {
            int day = days[idx];
            int penalty = penalties[idx];
            
            if (leftDay >= day)
                dp[idx][leftDay] = min(dp[idx - 1][leftDay], dp[idx - 1][leftDay - day] - penalty);
            else
                dp[idx][leftDay] = dp[idx - 1][leftDay];
        }
    }
}

int main()
{
    scanf("%d %d", &N, &T);
    
    for (int n = 1; n <= N; ++n)
    {
        scanf("%d %d", &days[n], &penalties[n]);
        penaltiesSum += penalties[n];
    }
    
    for (int a = 0; a < 1001; ++a)
    {
        for (int b = 0; b < 1001; ++b)
            dp[a][b] = penaltiesSum;
    }
    
    Solve();
    
    printf("%d\n", dp[N][T]);
    
    return 0;
}




