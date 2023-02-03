#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3
#define MAX 1001

int nodeNum, edgeNum, startNode;
bool visited[MAX];
vector<int> links[MAX];
vector<int> dfsResult;
vector<int> bfsResult;

void Init()
{
	for (int i = 0; i < MAX; ++i)
		visited[i] = false;
}

void DFS(int node)
{
	if (visited[node])
		return;
	visited[node] = true;

	dfsResult.push_back(node);

	for (int i = 0; i < links[node].size(); ++i)
	{
		int nxtNode = links[node][i];
		DFS(nxtNode);
	}
}

void BFS()
{
	queue<int> q;
	q.push(startNode);
	visited[startNode] = true;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		bfsResult.push_back(node);

		for (int i = 0; i < links[node].size(); ++i)
		{
			int nxtNode = links[node][i];

			if (!visited[nxtNode])
			{
				visited[nxtNode] = true;
				q.push(nxtNode);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> nodeNum >> edgeNum >> startNode;

	for (int e = 0; e < edgeNum; ++e)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;

		links[nodeA].push_back(nodeB);
		links[nodeB].push_back(nodeA);
	}

	for (int node = 1; node <= nodeNum; ++node)
		sort(links[node].begin(), links[node].end());

	Init();
	DFS(startNode);

	Init();
	BFS();

	for (int i = 0; i < dfsResult.size(); ++i)
		cout << dfsResult[i] << " ";
	cout << endl;
    
	for (int i = 0; i < bfsResult.size(); ++i)
		cout << bfsResult[i] << " ";
	cout << endl;

	return 0;
}