#include <string>
#include <vector>

using namespace std;

#define MAX 1000111

int dp[MAX][2]; // dp[x][0]: 0번 집을 훔치는 경우
                // dp[x][1]: 0번 집은 놔두고 1번 집을 훔치는 경우

int solution(vector<int> money) {
    int lastHome = money.size() - 1;
    
    // 0번 집을 훔치고 1번 집은 안 훔치는 경우: dp[x][0]
    dp[0][0] = money[0];
    dp[1][0] = dp[0][0];
    
    // 0번 집은 안 훔치고 1번 집은 훔치는 경우: dp[x][1]
    dp[0][1] = 0;
    dp[1][1] = money[1];
    
    for (int home = 2; home < lastHome; ++home)
    {
        // dp[home][x] = max(현재 집 안 훔치기, 현재 집 훔치기)
        // 현재 집 안 훔치기: 이전 집까지의 결과랑 같음 => dp[이전집][x]
        // 현재 집 훔치기: 이전 집 안 훔쳐야만 훔칠 수 있음 => dp[이전 집의 이전 집][x] + 현재 집 돈
        dp[home][0] = max(dp[home - 1][0], dp[home - 2][0] + money[home]);
        dp[home][1] = max(dp[home - 1][1], dp[home - 2][1] + money[home]);
    }        
    
    // 집이 원 모양이라서 0번 집을 훔친 경우, 마지막 집은 훔칠 수 없다. (위의 반복문 범위)
    // 그렇기에 1번 집을 훔친 경우에서 마지막 집은 따로 해줘야 한다.
    dp[lastHome][1] = max(dp[lastHome - 1][1], dp[lastHome - 2][1] + money[lastHome]);
    
    // 0번 집을 훔치는 경우, 마지막 집은 안 훔쳤기에 마지막집-1번이랑 비교해야 한다.
    return max(dp[lastHome - 1][0], dp[lastHome][1]);
}
