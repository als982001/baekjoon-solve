#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

long long nodesNum, edgesNum, startNode, visitOrder = 1, answer = 0;
long long depths[MAX];
long long visitOrders[MAX];
vector<long long> linkedNodes[MAX];

void BFS()
{
    queue<long long> q;
    
    q.push(startNode);
    depths[startNode] = 0;
    visitOrders[startNode] = visitOrder++;
    
    while(!q.empty())
    {
        long long node = q.front();
        q.pop();
        
        for (long long i = 0; i < linkedNodes[node].size(); ++i)
        {
            long long nextNode = linkedNodes[node][i];
            
            if (depths[nextNode] == -1)
            {
                depths[nextNode] = depths[node] + 1;
                visitOrders[nextNode] = visitOrder++;
                
                q.push(nextNode);
            } 
        }
    }
    
    return;
}

int main()
{
    scanf("%lld %lld %lld", &nodesNum, &edgesNum, &startNode);
    
    for (long long i = 0; i < edgesNum; ++i)
    {
        long long nodeA, nodeB;
        
        scanf("%lld %lld", &nodeA, &nodeB);
        
        linkedNodes[nodeA].push_back(nodeB);
        linkedNodes[nodeB].push_back(nodeA);
    }

    for (long long node = 1; node <= nodesNum; ++node)
    {
        depths[node] = -1;
        sort(linkedNodes[node].begin(), linkedNodes[node].end());
    }
        
    BFS();
    
    for (long long node = 1; node <= nodesNum; ++node)
    {
        answer += (visitOrders[node] * depths[node]);
    }
        
    printf("%lld\n", answer);

    return 0;
}