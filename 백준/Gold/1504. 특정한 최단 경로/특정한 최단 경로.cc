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
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define MAX 811
#define INF 333333333

int N, E;
int u, v, c;
int v1, v2;
long long dist[MAX];
vector<pair<int, long long>> links[MAX];

int Distance(int startNode, int endNode)
{
	for (int i = 0; i < MAX; ++i)
		dist[i] = INF;
	dist[startNode] = 0;

	priority_queue<pair<int, long long>> pq;
	pq.push({ startNode, 0 });

	while (!pq.empty())
	{
		int curNode = pq.top().first;
		long long curDist = -pq.top().second;
		pq.pop();

		if (dist[curNode] < curDist)
			continue;

		for (int i = 0; i < links[curNode].size(); ++i)
		{
			int nxtNode = links[curNode][i].first;
			long long nxtDist = curDist + links[curNode][i].second;

			if (dist[nxtNode] > nxtDist)
			{
				dist[nxtNode] = nxtDist;
				pq.push({ nxtNode, -nxtDist });
			}
		}
	}
	
	return dist[endNode];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> E;

	for (int i = 0; i < E; ++i)
	{
		cin >> u >> v >> c;
		
		links[u].push_back({ v, c });
		links[v].push_back({ u, c });
	}
	
	cin >> v1 >> v2;

	long long answer = min(Distance(1, v1) + Distance(v1, v2) + Distance(v2, N), Distance(1, v2) + Distance(v2, v1) + Distance(v1, N));

	if (answer < INF)
		cout << answer << endl;
	else
		cout << -1 << endl;

	
	return 0;
}
