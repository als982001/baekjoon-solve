#include <string>
#include <vector>
#include <algorithm>
#define MAX 100001
#define MOD 1000000007
using namespace std;

int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    sort(money.begin(), money.end());
    
    for (int i = 0; i < MAX; ++i)
        dp[i] = 0;
    dp[0] = 1;
    
    for (int i = 0; i < money.size(); ++i)
    {
        int curMoney = money[i];
        
        for (int val = curMoney; val <= n; ++val)
            dp[val] += dp[val - curMoney];
    }
    
    answer = dp[n];
    
    return answer;
}

