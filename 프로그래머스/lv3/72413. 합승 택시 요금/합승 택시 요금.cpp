#include <string>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 201
#define INF 5000000 // 이 값을 꽤 크게 주는 게 중요하다고 생각한다

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

