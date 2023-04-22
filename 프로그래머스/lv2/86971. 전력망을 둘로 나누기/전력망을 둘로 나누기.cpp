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

/*
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define MAX 101

int nodeNum;
bool visited[MAX];
vector<int> links[MAX];
vector<vector<int>> allWires;

int Search(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    int count = 1;

    while(!q.empty())
    {
        int curNode = q.front();
        q.pop();

        ++count;

        for (int i = 0; i < links[curNode].size(); ++i)
        {
            int nxtNode = links[curNode][i];

            if (visited[nxtNode] == false)
            {
                visited[nxtNode] = true;
                q.push(nxtNode);
            }   
        }
    }

    return count;
}

int Check(int disconnected)
{
    for (int node = 1; node <= nodeNum; ++node)
    {
        links[node].clear();
        visited[node] = false;
    }

    for (int wire = 0; wire < allWires.size(); ++wire)
    {
        if (wire == disconnected)
            continue;

        int nodeA = allWires[wire][0];
        int nodeB = allWires[wire][1];

        links[nodeA].push_back(nodeB);
        links[nodeB].push_back(nodeA);
    }

    vector<int> counts;

    for (int node = 1; node <= nodeNum; ++node)
    {

        if (visited[node] == false)
            counts.push_back(Search(node));
    }

    return abs(counts[0] - counts[1]);
}

int solution(int n, vector<vector<int>> wires) 
{
    nodeNum = n;
    int answer = MAX + MAX;
    allWires = wires;

    for (int disconnected = 0; disconnected < wires.size(); ++disconnected)
    {        
        int diff = Check(disconnected);

        if (answer > diff)
            answer = diff;
    }

    return answer;
}
*/