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
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define MAX 10011

int nodeNum, pathNum;
int id;
bool finished[MAX];
int nodeId[MAX];
vector<int> links[MAX];
vector<vector<int>> scces;
stack<int> stk;

bool CompareScc(vector<int> a, vector<int> b)
{
	if (a[0] < b[0])
		return true;
	else
		return false;
}

int Smaller(int a, int b)
{
	return a < b ? a : b;
}

int DFS(int node)
{
	nodeId[node] = ++id;
	stk.push(node);

	int parentNode = nodeId[node];

	for (int i = 0; i < links[node].size(); ++i)
	{
		int nxtNode=  links[node][i];

		if (nodeId[nxtNode] == 0)
			parentNode = Smaller(parentNode, DFS(nxtNode));
		else if (finished[nxtNode] == false)
			parentNode = Smaller(parentNode, nodeId[nxtNode]);
	}

	if (parentNode == nodeId[node])
	{
		vector<int> scc;

		while(true)
		{
			int pushedNode = stk.top();
			stk.pop();

			scc.push_back(pushedNode);
			finished[pushedNode] = true;

			if (pushedNode == node)
				break;
		}

		scces.push_back(scc);
	}

	return parentNode;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> nodeNum >> pathNum;

	for (int i = 0; i < pathNum; ++i)
	{
		int from, to;
		cin >> from >> to;

		links[from].push_back(to);
	}

	for (int node = 1; node <= nodeNum; ++node)
	{
		if (nodeId[node] == 0)
			DFS(node);
	}
	
	for (int i = 0; i < scces.size(); ++i)
	{
		sort(scces[i].begin(), scces[i].end());
	}

	sort(scces.begin(), scces.end(), CompareScc);
	
	cout << scces.size() << endl;
	
	for (int i = 0; i < scces.size(); ++i)
	{
		for (int k = 0; k < scces[i].size(); ++k)
		{
			cout << scces[i][k] << " ";
		}
		cout << -1 << endl;
	}

	return 0;
}