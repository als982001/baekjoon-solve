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
#define MAX 10001

int pathTotalCost;
int startCost = MAX;
int nodeNum, pathNum;
int costs[MAX];
int parentNode[MAX];
vector<pair<int, pair<int, int>>> pathes;


int ParentNode(int n)
{
	if (parentNode[n] == n)
		return n;

	return parentNode[n] = ParentNode(parentNode[n]);
}

bool IsSame(int a, int b)
{
	a = ParentNode(a);
	b = ParentNode(b);

	if (a == b)
		return true;
	else
		return false;
}

void MakeSame(int a, int b)
{
	a = ParentNode(a);
	b = ParentNode(b);

	if (a < b)
		parentNode[b] = a;
	else
		parentNode[a] = b;
}
 
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> nodeNum >> pathNum;

	for (int node = 1; node <= nodeNum; ++node)
	{
		cin >> costs[node];

		if (startCost > costs[node])
			startCost = costs[node];
	}

	for (int p = 0; p < pathNum; ++p)
	{
		int pathCost, nodeA, nodeB;
		cin >> nodeA >> nodeB >> pathCost;

		int roundTripCost = pathCost * 2 + costs[nodeA] + costs[nodeB];
		pathes.push_back({ roundTripCost, { nodeA, nodeB} });
	}

	sort(pathes.begin(), pathes.end());

	for (int node = 1; node < MAX; ++node)
		parentNode[node] = node;
	pathTotalCost = 0;

	for (int p = 0; p < pathes.size(); ++p)
	{
		int nodeA = pathes[p].second.first;
		int nodeB = pathes[p].second.second;
		int pathCost = pathes[p].first;

		if (IsSame(nodeA, nodeB) == false)
		{
			MakeSame(nodeA, nodeB);
			pathTotalCost += pathCost;
		}
	}

	int answer = pathTotalCost + startCost;

	cout << answer << endl;

	return 0;
}