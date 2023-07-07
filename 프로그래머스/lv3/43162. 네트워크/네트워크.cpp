#include <string>
#include <vector>
#define MAX 202

using namespace std;

bool checked[MAX];
vector<int> links[MAX];

void Check(int node)
{
    for (int i = 0; i < links[node].size(); ++i)
    {
        int linkedNode = links[node][i];
        
        if (!checked[linkedNode])
        {
            checked[linkedNode] = true;
            Check(linkedNode);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
        
    for (int nodeA = 0; nodeA < n; ++nodeA)
    {
        for (int nodeB = 0; nodeB < n; ++nodeB)
        {
            if (nodeA == nodeB)
                continue;
            
            if (computers[nodeA][nodeB] == 1)
                links[nodeA].push_back(nodeB);
        }
    }
    
    for (int node = 0; node < n; ++node)
    {
        if (checked[node] == false)
        {
            ++answer;
            Check(node);
        }
    }
    
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define MAX 211

int parentNode[MAX];
bool isParent[MAX];
vector<pair<int, int>> links;

int ParentNode(int node)
{
	if (parentNode[node] == node)
		return node;

	return parentNode[node] = ParentNode(parentNode[node]);
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

int solution(int n, vector<vector<int>> computers)
{
	int networkNum = 0;

	for (int node = 0; node < MAX; ++node)
		parentNode[node] = node;

	for (int nodeA = 0; nodeA < computers.size(); ++nodeA)
	{
		for (int nodeB = 0; nodeB < computers[nodeA].size(); ++nodeB)
		{
			if (nodeA == nodeB)
				continue;

			int linked = computers[nodeA][nodeB];

			if (linked == 1)
				links.push_back({ nodeA, nodeB });	
		}
	}

	for (int i = 0; i < links.size(); ++i)
	{
		int nodeA = links[i].first;
		int nodeB = links[i].second;

		if (IsSame(nodeA, nodeB) == false)
			MakeSame(nodeA, nodeB);
	}

	for (int node = 0; node < n; ++node)
	{
		int curParentNode = ParentNode(node);

		if (isParent[curParentNode] == false)
		{
			isParent[curParentNode] = true;
			++networkNum;
		}
	}

	return networkNum;
}
*/