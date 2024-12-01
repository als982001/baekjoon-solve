#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

int nodesNum, edgesNum, startNode, visitOrder = 1;
int visitOrders[MAX];
vector<int> linkedNodes[MAX];

void DFS(int node)
{
    if (visitOrders[node] > 0)
        return;
        
    visitOrders[node] = visitOrder++;
        
    for (int i = 0; i < linkedNodes[node].size(); ++i)
    {
        int nextNode = linkedNodes[node][i];
        DFS(nextNode);
    }
}

int main()
{
    scanf("%d %d %d", &nodesNum, &edgesNum, &startNode);
    
    for (int i = 0; i < edgesNum; ++i)
    {
        int nodeA, nodeB;
        
        scanf("%d %d", &nodeA, &nodeB);
        
        linkedNodes[nodeA].push_back(nodeB);
        linkedNodes[nodeB].push_back(nodeA);
    }
    
    for (int node = 1; node <= nodesNum; ++node)
    {
        sort(linkedNodes[node].begin(), linkedNodes[node].end());
        visitOrders[node] = 0;
    }
        
    DFS(startNode);
    
    for (int node = 1; node <= nodesNum; ++node)
        printf("%d\n", visitOrders[node]);

    return 0;
}