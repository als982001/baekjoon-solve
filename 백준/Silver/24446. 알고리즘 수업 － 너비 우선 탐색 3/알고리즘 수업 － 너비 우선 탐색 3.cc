#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001

using namespace std;

int nodesNum, edgesNum, startNode, visitOrder = 1;
int depths[MAX];
vector<int> linkedNodes[MAX];

void BFS()
{
    queue<int> q;
    
    q.push(startNode);
    depths[startNode] = 0;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (int i = 0; i < linkedNodes[node].size(); ++i)
        {
            int nextNode = linkedNodes[node][i];
            
            if (depths[nextNode] == -1)
            {
                depths[nextNode] = depths[node] + 1;
                q.push(nextNode);
            } 
        }
    }
    
    return;
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
        depths[node] = -1;

    BFS();
    
    for (int node = 1; node <= nodesNum; ++node)
        printf("%d\n", depths[node]);

    return 0;
}