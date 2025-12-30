#include <string>
#include <vector>

#define MAX 1000001
#define INF 987654321

using namespace std;

// dp[x][y]: x번째 집을 털었거나(y == 1) 털지 않았을(y == 0) 경우의 최댓값
int includeFirstHome[MAX][2];  
int excludeFirstHome[MAX][2]; 

int solution(vector<int> money) {    
    int lastHomeIdx = money.size() - 1;
    
    // 첫 번째 집을 턴 경우, dp[0]은 첫 번째 집의 돈 액수와 같다.
    includeFirstHome[0][0] = 0; // 이 dp 배열은 첫 번째 집을 턴 경우이기 때문에, 이 dp[0][0]은 잘못된 케이스라 0을 임시 저장
    includeFirstHome[0][1] = money[0];
    
    // 첫 번째 집을 털지 않은 경우, dp[0]은 0이다.
    excludeFirstHome[0][0] = 0;
    excludeFirstHome[0][1] = 0; // 이 dp 배열은 첫 번째 집을 털지 않은 경우이기 때문에, 이 dp[0][1]은 잘못된 케이스라 0을 임시 저장
    
    for (int homeIdx = 1; homeIdx < lastHomeIdx; ++homeIdx)
    {
        // homeIdx번째 집을 턴 경우: 이전 집을 털지 않아야 한다.
        includeFirstHome[homeIdx][1] = includeFirstHome[homeIdx - 1][0] + money[homeIdx];
        excludeFirstHome[homeIdx][1] = excludeFirstHome[homeIdx - 1][0] + money[homeIdx];
        
        // homeIdx번째 집을 털지 않은 경우: 이전 집을 털든 말든 상관 없음
        includeFirstHome[homeIdx][0] = max(includeFirstHome[homeIdx - 1][0], includeFirstHome[homeIdx - 1][1]);
        excludeFirstHome[homeIdx][0] = max(excludeFirstHome[homeIdx - 1][0], excludeFirstHome[homeIdx - 1][1]);
    }
    
    // 마지막 집을 터는 경우: 이전 집, 첫 번째 집을 털지 말아야 한다.
    includeFirstHome[lastHomeIdx][1] = 0; // 이 dp 배열은 첫 번째 집을 턴 경우에 대한 배열이기 때문에 0 저장
    excludeFirstHome[lastHomeIdx][1] = excludeFirstHome[lastHomeIdx - 1][0] + money[lastHomeIdx];
    
    // 마지막 집을 털지 않는 경우: 이전 집, 첫 번째 집을 털든 말든 상관 없음
    includeFirstHome[lastHomeIdx][0] = max(includeFirstHome[lastHomeIdx - 1][0], includeFirstHome[lastHomeIdx - 1][1]);
    excludeFirstHome[lastHomeIdx][0] = max(excludeFirstHome[lastHomeIdx - 1][0], excludeFirstHome[lastHomeIdx - 1][1]);
    
    int maxValueOfIncludeFirstHome = max(includeFirstHome[lastHomeIdx][0], includeFirstHome[lastHomeIdx][1]);
    int maxValueOfExcludeFirstHome = max(excludeFirstHome[lastHomeIdx][0], excludeFirstHome[lastHomeIdx][1]);
    
    int answer = max(maxValueOfIncludeFirstHome, maxValueOfExcludeFirstHome);
    
    return answer;
}