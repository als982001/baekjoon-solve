#include <string>
#include <vector>

#define MAX 201

using namespace std;

bool visited [MAX];
vector<int> linkedNodes[MAX];

void Visit(int node)
{
    if (visited[node])
        return;
    
    visited[node] = true;
    
    for (int nxtNode : linkedNodes[node])
        Visit(nxtNode);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int node = 0; node < n; ++node)
        visited[node] = false;
    
    for (int a = 0; a < computers.size(); ++a)
    {
        for (int b = 0; b < computers[a].size(); ++b)
        {
            if (computers[a][b] == 1)
                linkedNodes[a].push_back(b);
        }
    }
    
    for (int node = 0; node < n; ++node)
    {
        if (visited[node] == false)
        {
            Visit(node);
            ++answer;
        }
    }
    
    return answer;
}
