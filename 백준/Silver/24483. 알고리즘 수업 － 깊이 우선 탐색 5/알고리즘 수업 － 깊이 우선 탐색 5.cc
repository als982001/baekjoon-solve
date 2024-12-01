#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

long long nodesNum, edgesNum, startNode, visitOrder = 1, sum = 0;
long long depths[MAX];
long long visitOrders[MAX];
vector<long long> linkedNodes[MAX];

void DFS(long long node, long long befNode)
{
    if (visitOrders[node] > 0)
        return;
    
    depths[node] = befNode == -1 ? 0 : depths[befNode] + 1;
    visitOrders[node] = visitOrder++;

    for (long long i = 0; i < linkedNodes[node].size(); ++i)
    {
        long long nextNode = linkedNodes[node][i];
        DFS(nextNode, node);
    }
}

int main()
{
    scanf("%lld %lld %lld", &nodesNum, &edgesNum, &startNode);
    
    for (int i = 0; i < edgesNum; ++i)
    {
        long long nodeA, nodeB;
        
        scanf("%lld %lld", &nodeA, &nodeB);
        
        linkedNodes[nodeA].push_back(nodeB);
        linkedNodes[nodeB].push_back(nodeA);
    }
    
    for (int node = 1; node <= nodesNum; ++node)
    {
        sort(linkedNodes[node].begin(), linkedNodes[node].end());
        visitOrders[node] = 0;
        depths[node] = -1;
    }
        
    DFS(startNode, -1);
    
    for (int node = 1; node <= nodesNum; ++node)
    {
        sum += (visitOrders[node] * depths[node]);
    }
        
    printf("%lld\n", sum);

    return 0;
}