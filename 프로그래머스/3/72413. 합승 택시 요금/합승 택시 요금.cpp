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












/*

#include <string>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX 201
#define INF 5000000 // 이 값을 꽤 크게 주는 게 중요하다고 생각한다

int costs[MAX][MAX];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    for (int from = 1; from <= n; ++from)
    {
        for (int to = 1; to <= n; ++to)
        {
            if (from == to)
                costs[from][to] = 0;
            else
                costs[from][to] = INF;
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



*/