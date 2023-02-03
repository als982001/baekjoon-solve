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

#define MAX 10010

int N;
int curCol, maxLev;
int widest, minLevel;
int parent[MAX];
vector<int> nodeByLevel[MAX];
vector<int> lnk[MAX];
pair<int, int> info[MAX];

int Find_Root(int idx)
{
	if (parent[idx] == 0)
		return idx;
	else
		return Find_Root(parent[idx]);
}

void Make_Tree(int idx, int level)
{
	if (maxLev < level)
		maxLev = level;

	info[idx].first = level;
	nodeByLevel[level].push_back(idx);

	if (lnk[idx][0] != -1)
		Make_Tree(lnk[idx][0], level + 1);

	info[idx].second = curCol;
	++curCol;

	if (lnk[idx][1] != -1)
		Make_Tree(lnk[idx][1], level + 1);
}

void Find_Widest()
{
	widest = 0;
	minLevel = MAX + MAX;

	for (int lev = 1; lev <= maxLev; ++lev)
	{
		int leftNode = nodeByLevel[lev][0];
		int rightNode = nodeByLevel[lev][nodeByLevel[lev].size() - 1];

		int curWidth = info[rightNode].second - info[leftNode].second + 1;

		if (widest < curWidth)
		{
			widest = curWidth;
			minLevel = lev;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	int idx, leftNode, rightNode;
	for (int i = 1; i <= N; ++i)
	{
		cin >> idx >> leftNode >> rightNode;
		lnk[idx].push_back(leftNode);
		lnk[idx].push_back(rightNode);

		parent[leftNode] = idx;
		parent[rightNode] = idx;
	}

	int rootNode = Find_Root(1);

	curCol = 1;
	Make_Tree(rootNode, 1);

	Find_Widest();

	printf("%d %d \n", minLevel, widest);
	

	return 0;
}
