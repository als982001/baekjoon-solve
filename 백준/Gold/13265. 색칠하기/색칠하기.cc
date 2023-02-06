#include <iostream>
#include <string>
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
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 1001

int caseNum;
int nodeNum, linkNum;
string possible = "possible";
string impossible = "impossible";
int nodeColor[MAX];
vector<int> links[MAX];
vector<string> answer;

void Init()
{
	nodeNum = 0;
	linkNum = 0;
	memset(nodeColor, 0, sizeof(nodeColor));
	
	for (int i = 0; i < MAX; ++i)
		links[i].clear();
}

bool CanPaint(int node)
{
	if (nodeColor[node] > 0)
		return true;
    
	queue<pair<int, int>> q;
	q.push({ node, 1 });
	nodeColor[node] = 1;

	while(!q.empty())
	{
		int curNode = q.front().first;
		int curColor = q.front().second;
		int nxtColor = curColor == 1 ? 2 : 1;
		q.pop();

		for (int i = 0; i < links[curNode].size(); ++i)
		{
			int nxtNode = links[curNode][i];

			if (nodeColor[nxtNode] == 0)
			{
				nodeColor[nxtNode] = nxtColor;
				q.push({ nxtNode, nxtColor });
			}
			else if (nodeColor[nxtNode] == curColor)
				return false;
		}
	}
	
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> caseNum;

	while(caseNum--)
	{
		Init();

		cin >> nodeNum >> linkNum;

		for (int i = 0; i < linkNum; ++i)
		{
			int nodeA, nodeB;
			cin >> nodeA >> nodeB;

			links[nodeA].push_back(nodeB);
			links[nodeB].push_back(nodeA);
		}

		bool success = true;

		for (int node = 1; node <= nodeNum; ++node)
		{
			bool result = CanPaint(node);
			
			if (result == false)
			{
				success = false;
				break;
			}
		}

		if (success == true)
			answer.push_back(possible);
		else
			answer.push_back(impossible);
		
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;
	
	return 0;
}
