#include <string>
#include <vector>

#define MAX 300002
#define INF 987654321

using namespace std;

int dp[MAX][2]; // dp[node][0]: node가 불참할 때 최소 비용. dp[node][1]: node가 참석할 때 최소 비용
vector<int> sales;
vector<int> childNodes[MAX];

void Dfs(int node)
{  
    dp[node][0] = 0;
    dp[node][1] = sales[node - 1];
    
    if (childNodes[node].empty())
        return;
    
    bool childAttend = false; // 자식 노드 참여 여부
    int costSum = 0; // 자식 노드들의 최선 선택시의 비용 합
    int minChildAttendCost = INF; // 만약 모든 자식 노드가 참석하지 않는 경우, 억지로 참석시킨 경우의 최소 비용
    
    for (int childNode : childNodes[node])
    {
        Dfs(childNode);
        
        // 자식 노드별 최소 비용을 구한 후, 비용 합에 더한다.
        int minChildCost = min(dp[childNode][0], dp[childNode][1]);
        costSum += minChildCost;
        
        // 만약 자식 노드가 참석하면 참석하다고 기록
        // 자식 노드가 참석하는 경우: dp[childNode][0] >= dp[childNode][1]
        if (dp[childNode][0] >= dp[childNode][1])
            childAttend = true;
        else
        {
            // 만약 자식 노드가 전부 참석하지 않는 경우, 억지로 노드 하나 참석시켜야 할 수 있다.
            // 이를 위해 자식 노드의 불참 비용을 빼고 자식 노드 참석 비용만큼 더한다
            minChildAttendCost = min(minChildAttendCost, dp[childNode][1] - dp[childNode][0]);
        }
    }
    
    // 현재 노드가 참석하는 경우
    // 자식 노드 참석 여부랑은 상관 없이 최소 비용 저장하면 됨
    dp[node][1] += costSum;
    
    // 현재 노드가 참석하지 않는 경우
    
    if (childAttend)
    {
        // 자식 노드가 참석하므로 최소 비용 그냥 저장해도 됨
        dp[node][0] = costSum;
    }
    else
    {
        // 자식 노드 중 하나를 억지로 참석시켜야 함
        // 자식 노드 중 하나를 억지로 참석시키는 경우 최소 비용: minChildAttendCost
        dp[node][0] = costSum + minChildAttendCost;
    }
}

int solution(vector<int> _sales, vector<vector<int>> links) {
    sales = _sales;
    
    for (vector<int> link : links)
        childNodes[link[0]].push_back(link[1]);
    
    Dfs(1);
    
    return min(dp[1][0], dp[1][1]);
}