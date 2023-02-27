#include <string>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 201
#define INF 5000000

int costs[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    for (int a = 1; a <= n; ++a)
    {
        for (int b = 1; b <= n; ++b)
        {
            if (a == b)
                costs[a][b] = 0;
            else
                costs[a][b] = INF;
        }
    }

    for (int i = 0; i < fares.size(); ++i)
    {
        vector<int> fare = fares[i];

        int nodeA = fare[0];
        int nodeB = fare[1];
        int cost = fare[2];

        costs[nodeA][nodeB] = cost;
        costs[nodeB][nodeA] = cost;
    }
    
    for (int mid = 1; mid <= n; ++mid)
    {
        for (int start = 1; start <= n; ++start)
        {
            for (int end = 1; end <= n; ++end)
            {
                if (costs[start][end] > costs[start][mid] + costs[mid][end])
                    costs[start][end] = costs[start][mid] + costs[mid][end];
            }
        }
    }
    
    int answer = min(costs[s][a] + costs[a][b], costs[s][b] + costs[b][a]);

    for (int mid = 1; mid <= n; ++mid)
        answer = min(answer, costs[s][mid] + costs[mid][a] + costs[mid][b]);
    
    return answer;
}

/*
#define SIZE 3
#define MAX 201
#define INF 500000

int Min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	int dist[MAX][MAX];

	for (int from = 1; from <= n; ++from)
	{
		for (int to = 1; to <= n; ++to)
		{
			if (from == to)
				dist[from][to] = 0;
			else
				dist[from][to] = INF;
		}
	}

	for (int i = 0; i < fares.size(); ++i)
	{
		int node1 = fares[i][0];
		int node2 = fares[i][1];
		int fare = fares[i][2];

		dist[node1][node2] = fare;
		dist[node2][node1] = fare;
	}

	for (int mid = 1; mid <= n; ++mid)
	{
		for (int from = 1; from <= n; ++from)
		{
			for (int to = 1; to <= n; ++to)
			{
				if (dist[from][to] > dist[from][mid] + dist[mid][to])
					dist[from][to] = dist[from][mid] + dist[mid][to];
			}
		}
	}

	int minVal = Min(dist[s][a] + dist[a][b], dist[s][b] + dist[b][a]);

	for (int mid = 1; mid <= n; ++mid)
	{
		int curFare = dist[s][mid] + dist[mid][a] + dist[mid][b];

		minVal = Min(minVal, curFare);
	}

	return minVal;
}
*/
