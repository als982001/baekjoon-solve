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

















/*

#include <string>
#include <vector>
#include <queue>
#define MAX 20
#define BIT_MAX 140001
#define SHEEP 0
#define WOLF 1

using namespace std;

typedef struct INFO
{
    int wolf;
    int sheep;
    int passedNodes;
    
    INFO(int _sheep, int _wolf, int _passedNodes): sheep(_sheep), wolf(_wolf), passedNodes(_passedNodes) {}
} Info;

int nodesNum;
bool visited[MAX];
vector<int> links[MAX];
vector<int> sheepOrWolf;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;
    
    sheepOrWolf = info;
    nodesNum = sheepOrWolf.size();
    
    for (int i = 0; i < edges.size(); ++i)
    {   
        int parentNode = edges[i][0];
        int childNode = edges[i][1];
        
        links[parentNode].push_back(childNode);
    }
    
    Info startNode(1, 0, (1 << 0));
    
    queue<Info> q;
    q.push(startNode);
    
    while(!q.empty())
    {
        Info current = q.front();
        q.pop();
        
        for (int node = 0; node < nodesNum; ++node)
        {
            if (current.passedNodes & (1 << node))
            {
                int currentNode = node;
                
                for (int i = 0; i < links[currentNode].size(); ++i)
                {
                    int nextNode = links[currentNode][i];
                    int nextPassedNodes = current.passedNodes | (1 << nextNode);
                        
                    if (visited[nextPassedNodes])
                        continue;
                    
                    if (sheepOrWolf[nextNode] == SHEEP)
                    {
                        visited[nextPassedNodes] = true;
                        Info nextInfo(current.sheep + 1, current.wolf, nextPassedNodes);
                        
                        if (answer  < nextInfo.sheep)
                            answer = nextInfo.sheep;
                        
                        q.push(nextInfo);
                    }
                    else if (current.sheep > current.wolf + 1)
                    {
                        visited[nextPassedNodes] = true;
                        Info nextInfo(current.sheep, current.wolf + 1, nextPassedNodes);
                        
                        q.push(nextInfo);
                    }
                }
            }
        }
    }
    
    return answer;
}
*/
/*
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 140000

typedef struct NODE {
	int sheep;
	int wolf;
	int route;

	NODE(int _sheep, int _wolf, int _route) : sheep(_sheep), wolf(_wolf), route(_route) {}
}Node;

bool check[MAX];
vector<int> links[20];

int solution(vector<int> info, vector<vector<int>> edges)
{
	int answer = 1;
	int nodeNum = info.size();
	
	for (int i = 0; i < edges.size(); ++i)
	{
		vector<int> edge = edges[i];

		int from = edge[0];
		int to = edge[1];

		links[from].push_back(to);
	}

	queue<Node> q;
	Node start(1, 0, (1 << 0));
	q.push(start);

	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		for (int idx = 0; idx < nodeNum; ++idx)
		{
			if (node.route & (1 << idx))
			{
				int cur = idx;
				
				for (int i = 0; i < links[cur].size(); ++i)
				{
					int nxt = links[cur][i];
					int nxtRoute = node.route | (1 << nxt);

					if (check[nxtRoute])
						continue;

					if (info[nxt] == 0)
					{
						Node nxtNode(node.sheep + 1, node.wolf, nxtRoute);
						check[nxtRoute] = true;
                        
						if (answer < nxtNode.sheep)
							answer = nxtNode.sheep;
						
						q.push(nxtNode);
					}
					else if (node.sheep > node.wolf + 1)
					{
                        Node nxtNode(node.sheep, node.wolf + 1, nxtRoute);
						check[nxtRoute] = true;
						q.push(nxtNode);
					}
				}
			}
		}
	}

	return answer;
}

*/

