#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321
#define MAX 100001

int N, K;
int caffeines[101];
int dp[MAX];

void Init()
{
    for (int i = 0; i < MAX; ++i)
        dp[i] = INF;
        
    dp[0] = 0;
}


int main()
{
    Init();

    scanf("%d %d", &N, &K);
    
    for (int n = 1; n <= N; ++n)
        scanf("%d", &caffeines[n]);
    
    for (int coffeeIndex = 1; coffeeIndex <= N; ++coffeeIndex)
    {
        int currentCafffeine = caffeines[coffeeIndex];
        
        for (int requiredCaffeine = K; requiredCaffeine >= currentCafffeine; --requiredCaffeine)
            dp[requiredCaffeine] = min(dp[requiredCaffeine], dp[requiredCaffeine - currentCafffeine] + 1);
    }

    int answer = dp[K] == INF ? -1 : dp[K];
    
    printf("%d\n", answer);
   
    return 0;
}




