#include <string>
#include <vector>

#define MAX 201

using namespace std;

bool visited[MAX];
vector<int> links[MAX];

void Check(int node)
{
    for (int nxtNode : links[node])
    {
        if (!visited[nxtNode])
        {
            visited[nxtNode] = true;
            Check(nxtNode);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < MAX; ++i)
        visited[i] = false;
    
    for (int nodeA = 0; nodeA < n; ++nodeA)
    {
        for (int nodeB = nodeA + 1; nodeB < n; ++nodeB)
        {
            if (computers[nodeA][nodeB] == 1)
            {
                links[nodeA].push_back(nodeB);
                links[nodeB].push_back(nodeA);
            }
        }
    }
    
    for (int node = 0; node < n; ++node)
    {       
        if (!visited[node])
        {
            visited[node] = true;
            ++answer;
            Check(node);
        }
    }
    
    return answer;
}