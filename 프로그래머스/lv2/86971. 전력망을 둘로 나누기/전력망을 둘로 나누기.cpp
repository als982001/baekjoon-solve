#include <string>
#include <vector>

using namespace std;

#define MAX 101

int nodesNum;
bool checked[MAX];
vector<int> links[MAX];

void Link(vector<vector<int>> wires, int cutWire)
{
    for (int i = 0; i < wires.size(); ++i)
    {
        if (i == cutWire)
            continue;
        
        vector<int> wire = wires[i];
        
        int nodeA = wire[0];
        int nodeB = wire[1];
        
        links[nodeA].push_back(nodeB);
        links[nodeB].push_back(nodeA);
    }
}

void Check(int node)
{
    if (checked[node] == true)
        return;
    checked[node] = true;
    
    ++nodesNum;
    
    for (int i = 0; i < links[node].size(); ++i)
    {
        int nxtNode = links[node][i];
        Check(nxtNode);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 500;
    
    for (int cutWire = 0; cutWire < wires.size(); ++cutWire)
    {
        for (int node = 0; node < MAX; ++node)
        {
            links[node].clear();
            checked[node] = false;
        }
        
        Link(wires, cutWire);
        
        vector<int> nodesNums;
        
        for (int node = 1; node <= n; ++node)
        {
            if (checked[node] == false)
            {
                nodesNum = 0;
                Check(node);
                nodesNums.push_back(nodesNum);
            }
        }
        
        int diff = abs(nodesNums[0] - nodesNums[1]);
        
        if (answer > diff)
            answer = diff;
    }
    
    return answer;
}