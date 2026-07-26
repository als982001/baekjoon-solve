#include <string>
#include <vector>
#define MAX 202
#define INF 5000000

using namespace std;

int costs[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for (int x = 0; x < MAX; ++x)
    {
        for (int y = 0; y < MAX; ++y)
        {
            if (x == y)
                costs[x][y] = 0;
            else
                costs[x][y] = INF;
        }
    }
    
    for (vector<int> fare : fares)
    {
        int x = fare[0];
        int y = fare[1];
        int cost = fare[2];
        
        costs[x][y] = cost;
        costs[y][x] = cost;
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
    
    answer = min(costs[s][a] + costs[a][b], costs[s][b] + costs[b][a]);
    
    for (int mid = 1; mid <= n; ++mid)
    {
        int costSum = costs[s][mid] + costs[mid][a] + costs[mid][b];
        
        if (answer > costSum)
            answer = costSum;
    }
    
    return answer;
}