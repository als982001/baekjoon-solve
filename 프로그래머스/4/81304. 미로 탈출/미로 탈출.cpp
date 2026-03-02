#include <string>
#include <vector>
#include <queue>

#define MAX 1001
#define INF 987654321
#define TRAP_COND_MAX 1025

using namespace std;

struct Edge
{
    int to; // 향하는 노드
    int weight; // 걸리는 시간
    bool isReverse; // 역방향 간선인지 여부
};

int trapIndexes[MAX]; // 주어진 traps에서 노드별 인덱스
int minTimes[MAX][TRAP_COND_MAX]; // 노드별 방문 기록
vector<Edge> linkedNodes[MAX];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;
    
    // 초기화
    for (int node = 1; node <= n; ++node)
    {
        trapIndexes[node] = -1;
        
        for (int t = 0; t < TRAP_COND_MAX; ++t)
            minTimes[node][t] = INF;
    }
    
    for (vector<int> road : roads)
    {
        int a = road[0];
        int b = road[1];
        int w = road[2];
        
        linkedNodes[a].push_back({ b, w, false });
        linkedNodes[b].push_back({ a, w, true });
    }
    
    for (int idx = 0; idx < traps.size(); ++idx)
        trapIndexes[traps[idx]] = idx;
    
    // 다익스트라 알고리즘
    priority_queue<pair<int, pair<int, int>>> pq; // { 시간, { 노드, 함정 활성 기록 }}
    pq.push({ 0, { start, 0 }});
    
    minTimes[start][0] = 0;
    
    while(!pq.empty())
    {
        int curTime = -pq.top().first; // 첫 번째 원소(시간) 기준 정렬 복구
        int curNode = pq.top().second.first;
        int curTrapsCond = pq.top().second.second;
        
        pq.pop();
        
        // 우선순위 큐이므로 처음 도달한 게 최단 시간일 것
        if (curNode == end)
        {
            answer = curTime;
            break;
        }
        
        // 이미 더 빠른 경로로 방문한 적이 있다면 스킵
        if (minTimes[curNode][curTrapsCond] < curTime) 
            continue;
        
        // 현재 노드가 활성화된 함정인지 확인
        bool isCurActive = false;
        
        if (trapIndexes[curNode] != -1)
            isCurActive = (curTrapsCond & (1 << trapIndexes[curNode])) != 0;

        
        for (Edge edge : linkedNodes[curNode]) 
        {
            int nextNode = edge.to;
            int weight = edge.weight;
            bool isReverseEdge = edge.isReverse;
            
            // 다음 노드가 활성화된 함정인지 확인
            bool isNextActive = false;
            if (trapIndexes[nextNode] != -1)
                isNextActive = (curTrapsCond & (1 << trapIndexes[nextNode])) != 0;
            
            // ★ 방향 판별 로직 (XOR 활용)
            // 둘 중 하나만 활성화되어 있으면(true) 간선 방향이 뒤집힘
            bool isReversedState = isCurActive ^ isNextActive;
            
            // 현재 간선이 갈 수 없는 방향이면 스킵
            // (정방향 간선인데 뒤집혔거나, 역방향 간선인데 안 뒤집혔으면 통과 불가)
            if (isReverseEdge != isReversedState) 
                continue;
            
            // 다음 노드가 함정이라면 상태 토글(XOR)
            int nextTrapsCond = curTrapsCond;
            if (trapIndexes[nextNode] != -1)
                nextTrapsCond ^= (1 << trapIndexes[nextNode]);
            
            // 최단 시간 갱신
            int nextTime = curTime + weight;
            if (nextTime < minTimes[nextNode][nextTrapsCond]) 
            {
                minTimes[nextNode][nextTrapsCond] = nextTime;
                pq.push({-nextTime, {nextNode, nextTrapsCond}});
            }
        }
    }
    
    return answer;
}