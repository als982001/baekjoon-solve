#include <iostream>
#include <vector>
#include <queue>
#define START 1
#define MAX 51
#define INF 987654321
using namespace std;

int dist[MAX];
vector<pair<int, int>> roads[MAX];

void Check()
{
    dist[START] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push({ START, 0 });
    
    while(!pq.empty())
    {
        int curNode = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();
        
        if (dist[curNode] < curDist)
            continue;
        
        for (int i = 0; i < roads[curNode].size(); ++i)
        {
            int nxtNode = roads[curNode][i].first;
            int nxtDist = roads[curNode][i].second + curDist;
            
            if (dist[nxtNode] > nxtDist)
            {
                dist[nxtNode] = nxtDist;
                pq.push({ nxtNode, -nxtDist });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    for (int i = 0; i < MAX; ++i)
        dist[i] = INF;

    for (int i = 0; i < road.size(); ++i)
    {
        int node1 = road[i][0];
        int node2 = road[i][1];
        int curDist = road[i][2];
        
        roads[node1].push_back({ node2, curDist });
        roads[node2].push_back({ node1, curDist });
    }
    
    Check();
    
    for (int node = 1; node <= N; ++node)
    {
        if (dist[node] <= K)
            ++answer;
    }
    

    return answer;
}