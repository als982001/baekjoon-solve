#include <string>
#include <vector>

#define MAX 100001

using namespace std;

int dp[MAX];

int Check(int idx)
{
    if (dp[idx] > 0)
        return dp[idx];
    
    dp[idx] = (Check(idx - 1) + Check(idx - 2)) % 1234567;
    
    return dp[idx];
}

int solution(int n)
{    
    for (int num = 0; num <= n; ++num)
        dp[num] = 0;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3; 
    dp[5] = 5;
    
    return Check(n);
}