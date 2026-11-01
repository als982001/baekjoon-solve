#include <string>
#include <vector>

#define MAX 201

using namespace std;

int lastNode;
bool visited[MAX];
vector<int> linkedNodes[MAX];

void Check(int node)
{
    if (visited[node] == true)
        return;
    
    visited[node] = true;
    
    for (int linkedNode : linkedNodes[node])
    {
        if (visited[linkedNode] == false)
            Check(linkedNode);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    lastNode = n - 1;
    
    for (int node = 0; node <= lastNode; ++node)
        visited[node] = false;
    
    for (int node = 0; node < computers.size(); ++node)
    {
        for (int idx = 0; idx < computers[node].size(); ++idx)
        {
            if (computers[node][idx] == 1)
                linkedNodes[node].push_back(idx);
        }
    }
    
    for (int node = 0; node <= lastNode; ++node)
    {
        if (visited[node] == false)
        {            
            ++answer;
            Check(node);
        }
    }
    
    return answer;
}