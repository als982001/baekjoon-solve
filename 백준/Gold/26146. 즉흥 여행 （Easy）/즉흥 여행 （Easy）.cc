#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 200001

int N, M;
int id = 1;
int parentNode[MAX];
bool finished[MAX];
vector<int> links[MAX];
vector<vector<int>> sccs;
stack<int> stk;

int Check(int node)
{
	parentNode[node] = id++;
	stk.push(node);

	int curParentNode = parentNode[node];

	for (int i = 0; i < links[node].size(); ++i)
	{
		int linkedNode = links[node][i];

		if (parentNode[linkedNode] == 0)
			curParentNode = min(curParentNode, Check(linkedNode));
		else if (finished[linkedNode] == false)
			curParentNode = min(curParentNode, parentNode[linkedNode]);
	}

	if (curParentNode == parentNode[node])
	{
		vector<int> scc;

		while(true)
		{
			int stackedNode = stk.top();
			stk.pop();

			scc.push_back(stackedNode);
			finished[stackedNode] = true;

			if (node == stackedNode)
				break;
		}

		sccs.push_back(scc);
	}

	return curParentNode;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	cin >> N >> M;

	for (int m = 0; m < M; ++m)
	{
		int from, to;
		cin >> from >> to;

		links[from].push_back(to);
	}

	for (int node = 1; node <= N; ++node)
	{
		if (parentNode[node] == 0)
			Check(node);
	}

	if (sccs.size() == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

    return 0;
}
