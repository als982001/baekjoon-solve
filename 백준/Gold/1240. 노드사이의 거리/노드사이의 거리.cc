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
#pragma warning(disable:4996)

using namespace std;

#define SIZE 1111
#define MAX 10111

int N, M;
vector<pair<int, int>> links[SIZE];
bool visited[SIZE];

int Solve(int startNode, int endNode)
{
	for (int i = 0; i <= N; ++i)
		visited[i] = false;

	queue<pair<int, int>> q;
	q.push({ startNode, 0 });
	visited[startNode] = true;

	while (!q.empty())
	{
		int curNode = q.front().first;
		int curDist = q.front().second;
		q.pop();

		if (curNode == endNode)
			return curDist;

		for (int i = 0; i < links[curNode].size(); ++i)
		{
			int nxtNode = links[curNode][i].first;

			if (!visited[nxtNode])
			{
				int nxtDist = curDist + links[curNode][i].second;

				visited[nxtNode] = true;
				q.push({ nxtNode, nxtDist });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N - 1; ++i)
	{
		int nodeA, nodeB, dist;
		cin >> nodeA >> nodeB >> dist;

		links[nodeA].push_back({ nodeB, dist });
		links[nodeB].push_back({ nodeA, dist });
	}

	for (int i = 0; i < M; ++i)
	{
		int nodeA, nodeB;
		cin >> nodeA >> nodeB;

		cout << Solve(nodeA, nodeB) << endl;
	}

	return 0;
}
