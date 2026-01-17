#include <string>
#include <vector>

#define MAX 101
#define INF 987654321

using namespace std;

int tops[MAX][MAX];
int bottoms[MAX][MAX];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int a = 0; a <= n; ++a)
    {
        for (int b = 0; b <= n; ++b)
        {
            tops[a][b] = INF;
            bottoms[a][b] = INF;
        }
    }
    
    for (vector<int> result : results)
    {
        int startNode = result[0];
        int endNode = result[1];
        
        tops[endNode][startNode] = 1;
        bottoms[startNode][endNode] = 1;
    }
    
    for (int midNode = 1; midNode <= n; ++midNode)
    {
        for (int startNode = 1; startNode <= n; ++startNode)
        {
            for (int endNode = 1; endNode <= n; ++endNode)
            {
                if (tops[startNode][endNode] > tops[startNode][midNode] + tops[midNode][endNode])
                    tops[startNode][endNode] = tops[startNode][midNode] + tops[midNode][endNode];
                
                if (bottoms[startNode][endNode] > bottoms[startNode][midNode] + bottoms[midNode][endNode])
                    bottoms[startNode][endNode] = bottoms[startNode][midNode] + bottoms[midNode][endNode];
            }
        }
    }
    
    for (int node = 1; node <= n; ++node)
    {
        int checkedNodesNum = 0;
        
        for (int targetNode = 1; targetNode <= n; ++targetNode)
        {
            if (node == targetNode)
                continue;
            
            if (tops[node][targetNode] != INF || bottoms[node][targetNode] != INF)
                ++checkedNodesNum;
        }
        
        if (checkedNodesNum == n - 1)
            ++answer;
    }
    
    return answer;
}
