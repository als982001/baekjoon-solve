#include <string>
#include <vector>

#define MAX 101

using namespace std;

vector<int> links[MAX];
int nodesNum[2];
bool visited[MAX];

void Link(int n, vector<vector<int>>& wires, int cutIdx)
{
    for (int i = 1; i <= n; ++i)
    {
        links[i].clear();
        visited[i] = false;
    }
    
    nodesNum[0] = 0;
    nodesNum[1] = 0;
    
    for (int i = 0; i < wires.size(); ++i)
    {
        if (i == cutIdx)
            continue;
        
        int node1 = wires[i][0];
        int node2 = wires[i][1];
        
        links[node1].push_back(node2);
        links[node2].push_back(node1);    
    }
}

void Check(int node, int checkIdx)
{
    ++nodesNum[checkIdx];
    
    for (int linkedNode : links[node])
    {
        if (!visited[linkedNode])
        {
            visited[linkedNode] = true;
            Check(linkedNode, checkIdx);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = MAX + MAX;
    
    for (int cutIdx = 0; cutIdx < wires.size(); ++cutIdx)
    {
        Link(n, wires, cutIdx);
        
        for (int checkIdx = 0; checkIdx < 2; ++checkIdx)
        {
            for (int node = 1; node <= n; ++node)
            {
                if (!visited[node])
                {                    
                    visited[node] = true;
                    
                    Check(node, checkIdx);
                    break;
                }
            }
        }
        
        int diff = abs(nodesNum[0] - nodesNum[1]);
        
        if (answer > diff)
            answer = diff;
    }
    
    return answer;
}