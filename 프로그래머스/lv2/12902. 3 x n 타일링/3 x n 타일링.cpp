#include <string>
#include <vector>

using namespace std;

#define MAX 5001
#define MOD 1000000007

long long dp[MAX];

long long Check(int n)
{
    if (dp[n] >= 0)
        return dp[n];

    dp[n] = Check(n - 2) * dp[2];
    dp[n] %= MOD;

    for (int x = 4; x <= n; x += 2)
    {
        dp[n] += (Check(n - x) * 2);
        dp[n] %= MOD;
    }
    
    return dp[n];
}

int solution(int n)
{
    for (int x = 0; x < MAX; ++x)
        dp[x] = -1;

    if (n % 2 == 1)
        return 0;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[4] = 11;

    long long answer = Check(n);

    return answer;
}


/*
#define MAX 5001
#define MOD 1000000007

long long dp[MAX];

void Check(int n)
{
    for (int x = 6; x <= n; x += 2)
    {
        dp[x] = dp[x - 2] * dp[2];
        dp[x] %= MOD;

        for (int befX = x - 4; befX >= 0; befX -= 2)
        {
            dp[x] += (dp[befX] * 2);
            dp[x] %= MOD;
        }
    }
}

int solution(int n)
{
    if (n % 2 == 1)
        return 0;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[4] = 11;

    Check(n);

    return dp[n];
}
*/
