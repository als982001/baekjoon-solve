#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 50011
#define INF 987654321

bool isGate[MAX];
bool isSummit[MAX];
int intensity[MAX];
vector<pair<int, int>> links[MAX];

void Check(vector<int> gates)
{
	priority_queue<pair<int, int>> pq;

	for (int i = 0; i < MAX; ++i)
		intensity[i] = INF;

	for (int g = 0; g < gates.size(); ++g)
	{
		int gate = gates[g];

		intensity[gate] = 0;
		pq.push({ gate, 0 });
	}

	while (!pq.empty())
	{
		int curNode = pq.top().first;
		int curIntensity = -pq.top().second;
		pq.pop();

		if (intensity[curNode] < curIntensity)
			continue;

		for (int i = 0; i < links[curNode].size(); ++i)
		{
			int nxtNode = links[curNode][i].first;
			int nxtIntensity = links[curNode][i].second;
			if (0 < curIntensity && nxtIntensity < curIntensity)
				nxtIntensity = curIntensity;

			if (intensity[nxtNode] > nxtIntensity)
			{
				intensity[nxtNode] = nxtIntensity;
				pq.push({ nxtNode, -nxtIntensity });
			}
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
	vector<int> answer(2, INF);
    
    sort(gates.begin(), gates.end());
    sort(summits.begin(), summits.end());

	for (int i = 0; i < MAX; ++i)
	{
		isGate[i] = false;
		isSummit[i] = false;
		links[i].clear();
	}

	for (int g = 0; g < gates.size(); ++g)
		isGate[gates[g]] = true;

	for (int s = 0; s < summits.size(); ++s)
		isSummit[summits[s]] = true;

	for (int i = 0; i < paths.size(); ++i)
	{
		vector<int> path = paths[i];

		int node1 = path[0];
		int node2 = path[1];
		int dist = path[2];

		links[node1].push_back({ node2, dist });
		links[node2].push_back({ node1, dist });

		if (isGate[node1] == true || isSummit[node2] == true)
			links[node2].pop_back();

		if (isGate[node2] == true || isSummit[node1] == true)
			links[node1].pop_back();
	}

	Check(gates);

	for (int s = 0; s < summits.size(); ++s)
	{
		int summit = summits[s];
		
		if (answer[1] > intensity[summit])
		{
			answer[0] = summit;
			answer[1] = intensity[summit];
		}
	}
	

	return answer;
}
