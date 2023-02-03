#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

#define MAX 100111
#define INF 987654321

int V;
int maxDist;
int maxNode;
bool visited[MAX];
vector<pair<int, int>> links[MAX];

void DFS(int node, int dist)
{
	if (visited[node])
		return;
	visited[node] = true;

	if (maxDist < dist)
	{
		maxDist = dist;
		maxNode = node;
	}

	for (int i = 0; i < links[node].size(); ++i)
	{
		int nxt = links[node][i].first;
		int nxtDist = dist + links[node][i].second;

		DFS(nxt, nxtDist);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> V;

	int node, linked, dist;
	for (int i = 1; i <= V; ++i)
	{
		cin >> node;

		cin >> linked;

		while (linked != -1)
		{
			cin >> dist;

			links[node].push_back({ linked, dist });

			cin >> linked;
		}
	}

	DFS(1, 0);
	
	for (int i = 0; i < MAX; ++i)
		visited[i] = false;

	DFS(maxNode, 0);

	cout << maxDist << endl;

	return 0;
}
