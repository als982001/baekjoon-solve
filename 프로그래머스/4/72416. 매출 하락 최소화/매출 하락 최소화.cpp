#include <string>
#include <vector>

#define MAX 300002
#define INF 987654321 

using namespace std;

int saleValue[MAX]; // sales 인덱스를 일일이 idx + 1하기 귀찮아서 복사하기 위한 배열
int dp[MAX][2]; // dp[x][0]: x번 노드가 참석했을 때 최솟값, dp[x][1]: x번 노드가 불참했을 때 최솟값
vector<int> linkedNodes[MAX];

void Check(int node)
{ 
    dp[node][0] = saleValue[node];
    dp[node][1] = 0;
    
    if (linkedNodes[node].size() == 0)
        return;
    
    bool childAttend = false;
    int costSum = 0;
    
    int minChildAttendCost = INF; // 자식 노드가 하나도 참석하지 않는 경우, 꼭 하나 참가시킬 때의 비용
    
    for (int linkedNode : linkedNodes[node])
    {
        Check(linkedNode);
        
        int minLinkedNodeCost = min(dp[linkedNode][0], dp[linkedNode][1]);
        costSum += minLinkedNodeCost;
        
        // 자식 노드 참석 비용 < 불참 비용인 경우, 참석 시켜버림
        if (dp[linkedNode][0] < dp[linkedNode][1])
        {
            childAttend = true;
        }
        else
        {
            minChildAttendCost = min(minChildAttendCost, dp[linkedNode][0] - dp[linkedNode][1]);
        }
    }
    
    // 현재 노드 참석 시에는 신경쓸 거 없음
    dp[node][0] += costSum;
    
    // 현재 노드가 참석하지 않은 경우는 자식 노드를 참석시켰을 때를 고려해야 함
    if (childAttend)
    {
        // 자식이 참여하는 경우
        dp[node][1] = costSum;
    }
    else
    {
        // 자식이 참여하지 않는 경우
        dp[node][1] = costSum + minChildAttendCost;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) 
{    
    for (int idx = 0; idx < sales.size(); ++idx)
        saleValue[idx + 1] = sales[idx];
    
    for (vector<int> link : links)
    {
        int a = link[0];
        int b = link[1];
        
        linkedNodes[a].push_back(b);
    }
    
    Check(1);
    
    return min(dp[1][0], dp[1][1]);
}












/*

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
    
    bool childAttend = false; // 자식 노드 중 한 명이라도 참석하는지 여부
    int costSum = 0; // 자식 노드들이 각자 최선의 선택(가장 싼 비용)을 했을 때의 비용 합
    
    // 모든 자식이 불참할 때, 그나마 손해가 가장 적은 자식 1명을 억지로 참석시킬 때 발생하는 '추가 손해 비용'
    int minChildAttendCost = INF;
    
    for (int childNode : childNodes[node])
    {
        Dfs(childNode);
        
        // 1. 자식 노드 각자의 최선의 선택(참석 vs 불참 중 싼 것)을 비용 합에 무조건 더함
        int minChildCost = min(dp[childNode][0], dp[childNode][1]);
        costSum += minChildCost;
        
        // 2. 만약 이 자식이 '참석'하는 게 더 싸거나 같다면, 자발적으로 참석한다고 기록
        // 자식 노드가 참석하는 경우: dp[childNode][0] >= dp[childNode][1]
        if (dp[childNode][0] >= dp[childNode][1])
            childAttend = true;
        else
        {
            // 3. 이 자식은 '불참'하는 것이 더 싼 상황
            // 하지만 팀장이 안 갈 경우 이 자식을 억지로 참석시켜야 할 수도 있으므로, 
            // 그때 발생할 '손해(패널티)'를 미리 계산해둠
            // 추가 손해 = (억지로 참석할 때의 비용) - (원래 안 갈 때의 비용)
            // 나중에 나오는  costSum + minChildAttendCost의 minChildAttendCost에 해당.
            minChildAttendCost = min(minChildAttendCost, dp[childNode][1] - dp[childNode][0]);
        }
    }
    
    // [팀장이 참석하는 경우]
    // 팀의 필수 조건(팀장 or 팀원 1명 이상 참석)이 만족되었으므로, 
    // 자식들은 본인들 최선의 선택(costSum)을 유지하면 됨
    dp[node][1] += costSum;

    // [팀장이 참석하지 않는 경우]
    if (childAttend)
    {
        // 자식 중 이미 자발적으로 가는 사람이 있으므로 필수 조건 만족
        // 현재 구해진 최선의 선택(costSum)을 그대로 사용
        dp[node][0] = costSum;
    }
    else
    {
        // 팀장도 안 가고, 자식들도 모두 안 간다고 한 상황 (필수 조건 위반)
        // 무조건 자식 중 한 명은 손해를 보더라도 억지로 보내야 함
        // 전체 비용 = 모두 안 갈 때의 최적 비용(costSum) + 한 명을 억지로 보낼 때의 최소 손해(minChildAttendCost)
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

*/