#include <string>
#include <vector>

#define MAX 101

using namespace std;

int maxInfectedNum;
int lastNode;
bool infected[MAX];
vector<int> linkedNodes[MAX][3];
vector<int> currentInfectedNodes; // 현재 감염된 노드들 (완전탐색 원복용)


void Infect(int node, int pipe)
{
    // 감염되지 않았다면 이번에 감염되었다는 것이므로 감염 + 원복위해 기록
    if (infected[node] == false)
    {
        infected[node] = true;
        currentInfectedNodes.push_back(node);
    }
    
    // 파이프 따라 이어진 거 감염
    for (int linkedNode : linkedNodes[node][pipe])
    {
        if (infected[linkedNode] == false)
        {
            Infect(linkedNode, pipe);
        }
    }
}

// 현재 pipe, 남은 횟수에 따라 체크하는 함수
// pipe: 현재 열어놓은 파이프
// leftTurn: 남은 파이프 열고 닫을 수 있는 횟수
void Check(int pipe, int leftTurn)
{
    // 만약 열고 닫을 수 있는 횟수가 없다면 답 체크
    if (leftTurn == 0)
    {
        int infectedNum = 0;
        
        for (int node = 1; node <= lastNode; ++node)
        {
            if (infected[node])
                ++infectedNum;
        }
        
        // 감염된 수 갱신 가능하면 갱신
        if (maxInfectedNum < infectedNum)
            maxInfectedNum = infectedNum;
        
        return;
    }
    
    // 다음 파이프 열고 닫을 차례
    for (int nxtPipe = 0; nxtPipe < 3; ++nxtPipe)
    {
        // 이전 턴에 열었던 파이프랑 같으면 넘어감 (연속 열기 불가)
        if (nxtPipe == pipe)
            continue;
        
        // 이번 턴에 새로 감염된 노드만 원복하기 위해 현재 크기 저장
        int beforeSize = currentInfectedNodes.size();
        
        // 감염된 노드가 있으면 감염시킴
        for (int node = 1; node <= lastNode; ++node)
        {
            if (infected[node])
            {
                Infect(node, nxtPipe);
            }
        }
        
        // 방금 nxtPipe 사용했으므로 이를 넘겨주고 턴 감소
        Check(nxtPipe, leftTurn - 1);
        
        // 방금 전 상태로 정확히 복구
        while(currentInfectedNodes.size() > beforeSize)
        {
            int currentInfectedNode = currentInfectedNodes.back();
            infected[currentInfectedNode] = false;
            currentInfectedNodes.pop_back();
            
        }
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    // 1. 초기화
    lastNode = n;
    maxInfectedNum = -1;
    currentInfectedNodes.clear();
    
    for (int node = 1; node <= n; ++node)
        infected[node] = false;
    
    // 시작 노드 감염
    infected[infection] = true;
    
    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < 3; ++b)
        {
            linkedNodes[a][b].clear();
        }
    }
    
    for (vector<int> edge : edges)
    {
        int node1 = edge[0];
        int node2 = edge[1];
        int pipe = edge[2] - 1;
        
        linkedNodes[node1][pipe].push_back(node2);
        linkedNodes[node2][pipe].push_back(node1);
    }
    
    // 이전에 어떠한 파이프도 열지 않았다는 의미로 -1 전달
    Check(-1, k);

    return maxInfectedNum;
}