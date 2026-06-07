#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 50003
#define INF 10111111

using namespace std;

int lastNode;
int minIntensity[MAX];
bool isSummit[MAX];
bool isGate[MAX];
vector<pair<int, int>> linkedNodes[MAX];

void Dfs()
{   
    priority_queue<pair<int, int>> pq;
    
    for (int node = 1; node <= lastNode; ++node)
    {
        minIntensity[node] = INF;
        
        if (isGate[node])
            pq.push({ node, -INF });
    }
    
    while(!pq.empty())
    {
        int node = pq.top().first;
        int curIntensity = -pq.top().second;
        
        pq.pop();
        
        if (minIntensity[node] > curIntensity)
            continue;
        
        for (pair<int, int> linkedNode : linkedNodes[node])
        {
            int nxtNode = linkedNode.first;
            int nxtIntensity = curIntensity == INF ? linkedNode.second : max(curIntensity, linkedNode.second);
            
            if (minIntensity[nxtNode] > nxtIntensity)
            {
                minIntensity[nxtNode] = nxtIntensity;
                
                if (isSummit[nxtNode] == false)
                    pq.push({ nxtNode, -nxtIntensity });
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = { -1, INF }; // 산봉우리 번호, intensity 최솟값
    
    lastNode = n;
    
    for (vector<int> path : paths)
    {
        linkedNodes[path[0]].push_back({ path[1], path[2] });
        linkedNodes[path[1]].push_back({ path[0], path[2] });
    }
    
    for (int node = 1; node <= n; ++node)
    {
        minIntensity[node] = INF;
        isSummit[node] = false;
        isGate[node] = false;
    }
    
    for (int gate : gates)
        isGate[gate] = true;
    
    for (int summit : summits)
        isSummit[summit] = true;
    
    sort(summits.begin(), summits.end());
    
    Dfs();
    
    for (int summit : summits)
    {
        if (answer[1] > minIntensity[summit])
        {
            answer[0] = summit;
            answer[1] = minIntensity[summit];
        }
    }
    
    return answer;
}










/*

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


*/