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
#define MAX 200011

int answer;
int N, id;
int nextNode[MAX];
int nodeId[MAX];
int sccId[MAX];
int sccTotalNodeNum[MAX];
bool isFinished[MAX];
stack<int> stk;
vector<vector<int>> scces;

int Smaller(int a, int b)
{
	return a < b ? a : b;
}

int NextNode(int node)
{
	int jump = 0;

	if (node < 10)
		jump = node;
	else
	{
		int num = node;

		while (num > 0)
		{
			int rest = num % 10;
			jump += rest;

			num /= 10;
		}
	}

	int nextNodeIdx = node + jump;

	if (nextNodeIdx > N)
		return nextNodeIdx - N;
	else
		return nextNodeIdx;
}

int MakeScc(int node)
{
	nodeId[node] = (++id);
	stk.push(node);

	int parent = nodeId[node];
	int nxtNode = nextNode[node];

	if (nodeId[nxtNode] == 0)
		parent = Smaller(parent, MakeScc(nxtNode));
	if (!isFinished[nxtNode])
		parent = Smaller(parent, nodeId[nxtNode]);

	if (parent == nodeId[node])
	{
		vector<int> scc;
		int curSccId = scces.size();

		while (true)
		{
			int topNode = stk.top();
			stk.pop();

			scc.push_back(topNode);
			sccId[topNode] = curSccId;
			isFinished[topNode] = true;

			if (topNode == node)
				break;
		}

		scces.push_back(scc);
	}

	return parent;
}

int LinkScc(int node)
{
	int curSccId = sccId[node];

	if (sccTotalNodeNum[curSccId] > 0)
		return sccTotalNodeNum[curSccId];

	sccTotalNodeNum[curSccId] = scces[curSccId].size();

	int nxtNode = nextNode[node];

	if (sccId[nxtNode] != curSccId)
		sccTotalNodeNum[curSccId] += LinkScc(nxtNode);

	return sccTotalNodeNum[curSccId];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int node = 1; node <= N; ++node)
		nextNode[node] = NextNode(node);

	for (int node = 1; node <= N; ++node)
	{
		if (nodeId[node] == 0)
			MakeScc(node);
	}	
	
	for (int node = 1; node <= N; ++node)
		LinkScc(node);

	for (int id = 0; id < scces.size(); ++id)
	{
		if (answer < sccTotalNodeNum[id])
			answer = sccTotalNodeNum[id];
	}

	cout << answer << endl;

	return 0;
}