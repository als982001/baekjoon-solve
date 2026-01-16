#include <string>
#include <vector>
#include <queue>

#define MAX 20001
#define START 1

using namespace std;

int dist[MAX];
vector<pair<int, int>> linkedNodes[MAX];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for (int node = 1; node <= n; ++node)
        dist[node] = MAX;
    dist[START] = 1;
    
    for (vector<int> e : edge)
    {
        int node1 = e[0];
        int node2 = e[1];
        
        linkedNodes[node1].push_back({ node2, 1 });
        linkedNodes[node2].push_back({ node1, 1 });
    }
    
    queue<pair<int, int>> q;
    q.push({ START, 0 });
    
    while(!q.empty())
    {
        int curNode = q.front().first;
        int curDist = -q.front().second;
        
        q.pop();
        
        if (curDist > dist[curNode])
            continue;
        
        for (int i = 0; i < linkedNodes[curNode].size(); ++i)
        {
            int linkedNode = linkedNodes[curNode][i].first;
            int nxtDist = curDist + linkedNodes[curNode][i].second;
            
            if (dist[linkedNode] > nxtDist)
            {
                dist[linkedNode] = nxtDist;
                q.push({ linkedNode, -nxtDist });
            }
        }
            
    }
    
    int maxDist = -1;
    int nodesCnt = 0;
    
    for (int node = 2; node <= n; ++node)
    {
        if (maxDist < dist[node])
        {
            maxDist = dist[node];
            nodesCnt = 1;
        }
        else if (maxDist == dist[node])
            ++nodesCnt;
    }
    
    answer = nodesCnt;
    
    return answer;
}
