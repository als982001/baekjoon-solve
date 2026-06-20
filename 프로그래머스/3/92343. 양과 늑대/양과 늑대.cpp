#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX 20

using namespace std;

struct Info 
{
    int sheep; // 양 수
    int wolf; // 늑대 수
    int nodeHistory; // 지금까지 간 노드 정보
    
    Info (int _sheep, int _wolf, int _nodeHistory): wolf(_wolf), sheep(_sheep), nodeHistory(_nodeHistory) {};
};

int lastNode;
vector<int> linkedNodes[MAX];

int UpdateNodeHistory(int nodeHistory, int node)
{
    return (nodeHistory | (1 << node));
}

bool Visited(int nodeHistory, int node)
{
    return (nodeHistory & (1 << node)) != 0;
}

int solution(vector<int> sheepWolfInfo, vector<vector<int>> edges) 
{
    int answer = 0;
    
    lastNode = sheepWolfInfo.size() - 1;
    
    for (vector<int> edge : edges)
    {
        linkedNodes[edge[0]].push_back(edge[1]);
    }
    
    int initSheep = 1;  
    int initWolf = 0;
    int initNodeHistory = UpdateNodeHistory(0, 0);
    
    Info initInfo(initSheep, initWolf, initNodeHistory);
    
    queue<Info> q;
    q.push(initInfo);
    
    while(!q.empty())
    {
        Info curInfo = q.front();
        q.pop();
        
        int curSheep = curInfo.sheep;
        int curWolf = curInfo.wolf;
        int curNodeHistory = curInfo.nodeHistory;
        
        if (answer < curSheep)
            answer = curSheep;
        
        for (int node = 0; node <= lastNode; ++node)
        {
            if (Visited(curNodeHistory, node) == true)
            {
                int visitedNode = node;
                
                for (int nxtNode : linkedNodes[visitedNode])
                {
                    if (Visited(curNodeHistory, nxtNode))
                        continue;
                    
                    int nxtSheep = curSheep;
                    int nxtWolf = curWolf;
                    
                    if (sheepWolfInfo[nxtNode] == 0)
                        ++nxtSheep;
                    else
                        ++nxtWolf;
                    
                    if (nxtSheep > nxtWolf)
                    {
                        int nxtNodeHistory = curNodeHistory;
                        nxtNodeHistory = UpdateNodeHistory(nxtNodeHistory, nxtNode);
                        
                        Info nxtInfo(nxtSheep, nxtWolf, nxtNodeHistory);
                        q.push(nxtInfo);
                    }
                }
            }
        }
    }
   
    return answer;
}










/*

#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define MAX 20

using namespace std;

typedef struct INFO
{
    int wolf;
    int sheep;
    int passedNodes;
    
    INFO(int _sheep, int _wolf, int _passedNodes): sheep(_sheep), wolf(_wolf), passedNodes(_passedNodes) {}
} Info;

vector<int> linkedNodes[MAX];

bool Visited(int node, int passedNodes)
{
    return passedNodes & (1 << node);
}

int GetPassedNodes(int node, int passedNodes)
{
    return passedNodes | (1 << node);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    int lastNode = info.size() - 1;
    
    for (vector<int> edge : edges)
    {
        int node1 = edge[0];
        int node2 = edge[1];
        
        linkedNodes[node1].push_back(node2);
        // linkedNodes[node2].push_back(node1);
    }
    
    queue<Info> q;
    
    Info startInfo(1, 0, GetPassedNodes(0, 0));
    
    q.push(startInfo);
    
    while(!q.empty())
    {
        Info curInfo = q.front();
        q.pop();
        
        int sheep = curInfo.sheep;
        int wolf = curInfo.wolf;
        int passedNodes = curInfo.passedNodes;
        
        if (answer < sheep)
            answer = sheep;
        
        for (int node = 0; node <= lastNode; ++node)
        {
            if (Visited(node, passedNodes))
            {
                for (int linkedNode : linkedNodes[node])
                {
                    if (Visited(linkedNode, passedNodes))
                        continue;
                    
                    int nxtSheep = sheep;
                    int nxtWolf = wolf;
                    
                    if (info[linkedNode] == 0)
                        ++nxtSheep;
                    else 
                        ++nxtWolf;
                    
                    if (nxtSheep > nxtWolf)
                    {
                        int nxtPassedNodes = GetPassedNodes(linkedNode, passedNodes);
                        
                        Info nxtInfo(nxtSheep, nxtWolf, nxtPassedNodes);
                        
                        q.push(nxtInfo);
                    }
                }
            }
        }
    }
    
    
    
    return answer;
}




*/