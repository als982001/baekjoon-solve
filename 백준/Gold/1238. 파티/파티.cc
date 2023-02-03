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
#define INF 987654321

int nodeNum, pathNum, startNode;
int reqTimes[MAX][MAX];
vector<pair<int, int>> pathes[MAX];

void Dijkstra(int start)
{
	reqTimes[start][start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int curNode = pq.top().first;
		int curReqTime = -pq.top().second;
		pq.pop();

		if (reqTimes[start][curNode] < curReqTime)
			continue;

		for (int i = 0; i < pathes[curNode].size(); ++i)
		{
			int nxtNode = pathes[curNode][i].first;
			int nxtReqTime = pathes[curNode][i].second + curReqTime;

			if (reqTimes[start][nxtNode] > nxtReqTime)
			{
				reqTimes[start][nxtNode] = nxtReqTime;
				pq.push({ nxtNode, -nxtReqTime });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	
	cin >> nodeNum >> pathNum >> startNode;

	for (int p = 0; p < pathNum; ++p)
	{
		int from, to, reqTime;
		cin >> from >> to >> reqTime;

		pathes[from].push_back({ to, reqTime });
	}

	for (int a = 0; a < MAX; ++a)
	{
		for (int b = 0; b < MAX; ++b)
			reqTimes[a][b] = INF;
	}

	for (int node = 1; node <= nodeNum; ++node)
		Dijkstra(node);

	int answer = -1;

	for (int node = 1; node <= nodeNum; ++node)
	{
		if (node == startNode)
			continue;

        int curReqTime = reqTimes[startNode][node] + reqTimes[node][startNode];

		if (answer < curReqTime)
			answer = curReqTime;
	}

	cout << answer << endl;
    
	return 0;
}