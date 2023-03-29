#include <string>
#include <vector>

using namespace std;

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


// 처음에 했을 때 시간초과 났던 코드
/*
int Check(int n)
{
    if (dp[n] >= 0)
        return dp[n];
    
    int& curDp = dp[n];
    curDp = 0;

    curDp = Check(n - 2) * dp[2];

    for (int befN = n - 4; befN >= 0; befN -= 2)
        curDp += (Check(befN) * 2);

    return curDp;
}

int solution(int n) 
{
    for (int i = 0; i < MAX; ++i)
        dp[i] = -1;

    if (n % 2 == 1)
        return 0;
        
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;

    int answer = Check(n);

    return answer;
}
*/