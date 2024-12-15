#include <iostream>
#include <vector>

using namespace std;

int casesNum, coinsNum, targetValue;
int coins[21];
int dp[21][10001];
vector<int> answers;

void Init()
{
    for (int a = 0; a < 21; ++a)
    {
        coins[a] = 0;
        
        for (int b = 0; b < 10001; ++b)
            dp[a][b] = 0;
    }
}

int Solve(int coinIndex, int requiredValue)
{
    int coin = coins[coinIndex];
    
    // 마지막 동전인 경우
    if (coinIndex == coinsNum)
    {
        // 현재 동전으로 딱 맞게 만들 수 있으면 1, 아니면 0을 return
        return requiredValue % coin > 0 ? 0 : 1;
    }
    
    if (dp[coinIndex][requiredValue] > 0)
        return dp[coinIndex][requiredValue];
    
    dp[coinIndex][requiredValue] = 0;
    
    for (int coinCount = 0; (coinCount * coin) <= requiredValue; ++coinCount)
    {
        int leftValue = requiredValue - (coinCount * coin);
        
        dp[coinIndex][requiredValue] += Solve(coinIndex + 1, leftValue);
    }
    
    
    return dp[coinIndex][requiredValue];
}

int main()
{
    scanf("%d", &casesNum);
    
    for (int c = 0; c < casesNum; ++c)
    {
        Init();
        
        scanf("%d", &coinsNum);
    
        // 오름차순으로 입력되는 것을 내림차순으로 정리하기 위함
        for (int i = coinsNum; i >= 1; --i)
            scanf("%d", &coins[i]);
            
        scanf("%d", &targetValue);
       
        int answer = Solve(1, targetValue);
        
        answers.push_back(answer);
    }
    
    for (int i = 0; i < answers.size(); ++i)
        printf("%d\n", answers[i]);

    return 0;
}




/*

10, 5, 1

30

dp[x][0] = 1;

10원 동전으로
30 = (10 x 3) + (20 x 2 + 10원) + (10 x 1 + 20원) + (30원)
    = 1 + dp[5][10] + dp[5][20] + dp[5][30]
    = 

5원 동전
10 = 5 x 2 + (5 x 1 + 5원) + (10원) = 1 + dp[1][5] + dp[1][10] = 3 => dp[5][10] = 3
20 = (5 x 4 + 0원) + (5 x 3 + 5원) + (5 x 2 + 10원) + (5 x 1 + 15원) + (20원)
    = 1 + dp[1][5] + dp[1][10] + dp[1][15] + dp[1][20] = 4


1원 동전
5 = 1 x 5 = dp[1][5] = 1
10원 = 1 x 10 = dp[1][10] = 1



*/

