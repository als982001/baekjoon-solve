#include <string>
#include <vector>
#include <queue>

#define MAX 200003

using namespace std;

bool success = false; // 모두 방문할 수 있으면 true
int lastNode; // 마지막 노드
int visitedNodesCount = 0; // 방문한 노드 개수

bool visited[MAX]; // 방문 기록
int before[MAX]; // 선행 노드
int save[MAX]; // 조건이 안 맞아서 임시로 대기시킨 노드
vector<int> linkedNodes[MAX]; // 연결되어 있는 노드들

void Check(int startNode)
{
    // 예외 처리: 시작점에 선행 조건이 있으면 아예 시작 불가
    if (before[startNode] != startNode)
        return;
    
    queue<int> q;
    q.push(startNode);
    
    visited[startNode] = true;
    ++visitedNodesCount;
    
    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();
        
        // 만약 현재 노드의 후행 노드가 대기 중이라면
        if (save[curNode] != -1)
        {
            int waitingNode = save[curNode];
            
            q.push(waitingNode);
            visited[waitingNode] = true;
            ++visitedNodesCount;
        }
        
        for (int nextNode : linkedNodes[curNode])
        {
            if (visited[nextNode])
                continue;
            
            // 선행 노드가 존재하는 경우
            if (before[nextNode] != nextNode)
            {
                // 선행 노드를 방문했으면 다음 노드 그냥 방문하면 됨
                if (visited[before[nextNode]])
                {
                    q.push(nextNode);
                    visited[nextNode] = true;
                    ++visitedNodesCount;
                }
                else
                {
                    // 선행 노드 방문 안 했으면 대기 중임을 알림
                    save[before[nextNode]] = nextNode;
                }
            }
            else
            {
                // 선행 노드 없으면 그냥 방문하면 됨
                q.push(nextNode);
                visited[nextNode] = true;
                
                ++visitedNodesCount;
            }
        }
    }
    
    if (visitedNodesCount == lastNode + 1)
        success = true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) 
{    
    // 초기화
    lastNode = n - 1;
    
    for (int node = 0; node <= n; ++node)
    {
        before[node] = node;
        save[node] = -1;
    }
    
    for (vector<int> pathInfo : path)
    {
        int node1 = pathInfo[0];
        int node2 = pathInfo[1];
        
        linkedNodes[node1].push_back(node2);
        linkedNodes[node2].push_back(node1);
    }
    
    for (vector<int> orderInfo : order)
    {
        int befNode = orderInfo[0]; // 먼저 가야 하는 노드
        int aftNode = orderInfo[1]; // 나중에 가야 하는 노드
        
        before[aftNode] = befNode;
    }
    
    Check(0);
    
    return success;
}