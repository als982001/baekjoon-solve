#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001

using namespace std;

int nodesNum, edgesNum, startNode;
int depths[MAX];
vector<int> linkedNodes[MAX];

void DFS(int node, int befNode)
{
    if (depths[node] > -1)
        return;
    
    depths[node] = befNode == -1 ? 0 : depths[befNode] + 1;

    for (int i = 0; i < linkedNodes[node].size(); ++i)
    {
        int nextNode = linkedNodes[node][i];
        DFS(nextNode, node);
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
        depths[node] = -1;
    }
        
    DFS(startNode, -1);
    
    for (int node = 1; node <= nodesNum; ++node)
        printf("%d\n", depths[node]);

    return 0;
}