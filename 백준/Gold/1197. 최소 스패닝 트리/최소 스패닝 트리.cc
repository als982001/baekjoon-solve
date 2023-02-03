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

int answer;
int nodeNum, edgeNum;
int parentNode[MAX];
vector<pair<int, pair<int, int>>> edges;

int ParentNode(int num)
{
	if (parentNode[num] == num)
		return num;

	return parentNode[num] = ParentNode(parentNode[num]);
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

	cin >> nodeNum >> edgeNum;

	for (int e = 0; e < edgeNum; ++e)
	{
		int nodeA, nodeB, cost;
		cin >> nodeA >> nodeB >> cost;

		edges.push_back({ cost, { nodeA, nodeB} });
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < MAX; ++i)
		parentNode[i] = i;

	for (int i = 0; i < edges.size(); ++i)
	{
		int cost = edges[i].first;
		int nodeA = edges[i].second.first;
		int nodeB = edges[i].second.second;

		if (IsSame(nodeA, nodeB) == false)
		{
			MakeSame(nodeA, nodeB);
			answer += cost;
		}
	}

	cout << answer << endl;
	
	return 0;
}