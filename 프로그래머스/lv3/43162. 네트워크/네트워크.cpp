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

/*
int id = 1;
int ids[MAX];
vector<int> links[MAX];

int solution(int n, vector<vector<int>> computers)
{
	id = 1;
	for (int i = 0; i < MAX; ++i)
	{
		ids[i] = 0;
		links[i].clear();
	}

	for (int from = 0; from < computers.size(); ++from)
	{
		for (int idx = 0; idx < computers[from].size(); ++idx)
		{
			int linkCheck = computers[from][idx];

			if (linkCheck == 1)
				links[from + 1].push_back(idx + 1);
		}
	}

	for (int idx = 1; idx <= n; ++idx)
	{
		if (ids[idx] == 0)
		{
			queue<int> q;
			q.push(idx);

			ids[idx] = id;

			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				for (int i = 0; i < links[cur].size(); ++i)
				{
					int nxt = links[cur][i];

					if (ids[nxt] == 0)
					{
						ids[nxt] = id;
						q.push(nxt);
					}
				}
			}

			++id;
		}
	}

	return id - 1;
}
*/

/*
bool check[200];
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    queue<int> q;

    for (int cur_index = 0; cur_index < n; ++cur_index)
    {
        if (!check[cur_index])
        {
            q.push(cur_index);
            check[cur_index] = true;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int t = 0; t < n; ++t)
                {
                    if (t == cur_index)
                        continue;

                    if (!check[t] && computers[cur][t] == 1)
                    {
                        check[t] = true;
                        q.push(t);
                    }
                }
                
            }
            ++answer;
        }
    }
    
    return answer;
}
*/