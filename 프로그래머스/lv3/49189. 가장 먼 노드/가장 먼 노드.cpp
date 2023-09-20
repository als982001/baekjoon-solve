#include <string>
#include <vector>
#include <queue>
#define MAX 20001
using namespace std;

int maxDist = 0;
int answer = 0;
bool visited[MAX];
vector<int> links[MAX];

void Check(int startNode)
{
    queue<pair<int, int>> q;
    
    q.push({ startNode, 0 });
    visited[startNode] = true;
    
    while(!q.empty())
    {
        int curNode = q.front().first;
        int curDist = q.front().second;
        q.pop();
        
        if (maxDist == curDist)
            ++answer;
        else if (maxDist < curDist)
        {
            maxDist = curDist;
            answer = 1;
        }
        
        for (int i = 0; i < links[curNode].size(); ++i)
        {
            int nxtNode = links[curNode][i];
            
            if (visited[nxtNode] == false)
            {
                visited[nxtNode] = true;
                q.push({ nxtNode, curDist + 1 });
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    for (int node = 0; node < MAX; ++node)
        visited[node] = false;
    
    for (int i = 0; i < edge.size(); ++i)
    {
        int nodeA = edge[i][0];
        int nodeB = edge[i][1];
        
        links[nodeA].push_back(nodeB);
        links[nodeB].push_back(nodeA);
    }
    
    Check(1);
    
    return answer;
}