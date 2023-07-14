#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
#define MAX 18

typedef struct NODE {
	int sheep;
	int wolf;
	int route;

	NODE(int _sheep, int _wolf, int _route) : sheep(_sheep), wolf(_wolf), route(_route) {}
} node;

int check[140000];

int solution(vector<int> info, vector<vector<int>> edges) {
	int answer = 1;

	int nodeNum = info.size();

	vector<int> links[MAX];

	for (int i = 0; i < edges.size(); ++i)
		links[edges[i][0]].push_back(edges[i][1]);

	node start(1, 0, 1 << 0);
	check[1 << 0] = true;

	queue<node> q;
	q.push(start);

	while (!q.empty())
	{
		node cur = q.front();
		q.pop();

		int sheep = cur.sheep;
		int wolf = cur.wolf;
		int route = cur.route;

		for (int n = 0; n < nodeNum; ++n)
		{
			if (route & (1 << n))
			{
				for (int i = 0; i < links[n].size(); ++i)
				{
					int nxt = links[n][i];
					int nxtRoute = route | (1 << nxt);

					if (check[nxtRoute] == false)
					{
						if (info[nxt] == 0)
						{
							answer = max(answer, sheep + 1);
							check[nxtRoute] = true;

							node nxtNode(sheep + 1, wolf, nxtRoute);
							q.push(nxtNode);
						}
						else if (sheep > wolf + 1)
						{
							check[nxtRoute] = true;

							node nxtNode(sheep, wolf + 1, nxtRoute);
							q.push(nxtNode);
						}
					}
				}
			}
		}
	}

	return answer;
}
*/
#define MAX 140000

typedef struct NODE {
	int sheep;
	int wolf;
	int route;

	NODE(int _sheep, int _wolf, int _route) : sheep(_sheep), wolf(_wolf), route(_route) {}
}Node;

bool check[MAX];
vector<int> links[20];

int solution(vector<int> info, vector<vector<int>> edges)
{
	int answer = 1;
	int nodeNum = info.size();
	
	for (int i = 0; i < edges.size(); ++i)
	{
		vector<int> edge = edges[i];

		int from = edge[0];
		int to = edge[1];

		links[from].push_back(to);
	}

	queue<Node> q;
	Node start(1, 0, (1 << 0));
	q.push(start);

	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		for (int idx = 0; idx < nodeNum; ++idx)
		{
			if (node.route & (1 << idx))
			{
				int cur = idx;
				
				for (int i = 0; i < links[cur].size(); ++i)
				{
					int nxt = links[cur][i];
					int nxtRoute = node.route | (1 << nxt);

					if (check[nxtRoute])
						continue;

					if (info[nxt] == 0)
					{
						Node nxtNode(node.sheep + 1, node.wolf, nxtRoute);
						check[nxtRoute] = true;
                        
						if (answer < nxtNode.sheep)
							answer = nxtNode.sheep;
						
						q.push(nxtNode);
					}
					else if (node.sheep > node.wolf + 1)
					{
                        Node nxtNode(node.sheep, node.wolf + 1, nxtRoute);
						check[nxtRoute] = true;
						q.push(nxtNode);
					}
				}
			}
		}
	}

	return answer;
}
