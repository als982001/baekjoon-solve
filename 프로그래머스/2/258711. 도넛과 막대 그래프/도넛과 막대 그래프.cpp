#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 1000011

using namespace std;

// 힙 메모리(전역)에 선언해서 초기화 및 스택 오버플로우 방지
int inDegree[MAX];  
int outDegree[MAX]; 

vector<int> solution(vector<vector<int>> edges) {
    int maxNode = 0;
    int additionalNode = -1;
    int donutGraphNum = 0;
    int stickGraphNum = 0;
    int eightGraphNum = 0;

    // 1. 간선 정보 채우기
    for (const auto& edge : edges)
    {
        outDegree[edge[0]]++;
        inDegree[edge[1]]++;
        maxNode = max(maxNode, max(edge[0], edge[1]));
    }
    
    // 2. 생성된 정점 찾기
    // 조건: 들어오는 건 없고(0), 나가는 건 2개 이상 (그래프가 2개 이상이므로)
    for (int node = 1; node <= maxNode; ++node)
    {
        if (inDegree[node] == 0 && outDegree[node] >= 2)
        {
            additionalNode = node;
            break;
        }
    }
    
    int totalGraphs = outDegree[additionalNode];
    
    // 3. 각 그래프의 "유니크한 특징"을 가진 노드 찾기
    for (int node = 1; node <= maxNode; ++node)
    {
        // 생성된 정점은 카운트 대상에서 제외
        if (node == additionalNode) continue;

        // [막대 그래프] 
        // 특징: 나가는 간선이 없음 (Out == 0)
        // 필수조건: 그래프의 일부여야 함 -> 들어오는 간선은 있어야 함 (In > 0)
        // 이 조건(In > 0)이 35번 케이스(존재하지 않는 노드)를 걸러줍니다.
        if (outDegree[node] == 0 && inDegree[node] > 0)
        {
            stickGraphNum++;
        }
        // [8자 그래프]
        // 특징: 나가는 간선이 2개 (Out == 2)
        // 필수조건: 들어오는 간선이 2개 이상 (In >= 2)
        // 원래는 2개지만, 생성 정점이 여기로 연결되면 3개가 될 수 있음.
        else if (outDegree[node] == 2 && inDegree[node] >= 2)
        {
            eightGraphNum++;
        }
    }
    
    // [도넛 그래프]
    // 특징점 잡기가 애매하므로 소거법으로 계산
    donutGraphNum = totalGraphs - (stickGraphNum + eightGraphNum);
    
    return { additionalNode, donutGraphNum, stickGraphNum, eightGraphNum };
}