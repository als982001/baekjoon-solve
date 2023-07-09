#include <string>
#include <vector>
#include <algorithm>
#define MAX 102

using namespace std;

int parentNode[MAX];

bool Compare(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int ParentNode(int node)
{
    if (node == parentNode[node])
        return node;
    
    return parentNode[node] = ParentNode(parentNode[node]);
}

bool IsSame(int a, int b)
{
    a = ParentNode(a);
    b = ParentNode(b);
    
    return a == b;
}

void MakeSame(int a, int b)
{
    a = ParentNode(a);
    b = ParentNode(b);
    
    if (a < b)
        parentNode[b] = a;
    else
        parentNode[a] = b;
    
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for (int node = 0; node < MAX; ++node)
        parentNode[node] = node;
    
    sort(costs.begin(), costs.end(), Compare);
    
    for (int i = 0; i < costs.size(); ++i)
    {   
        int nodeA = costs[i][0];
        int nodeB = costs[i][1];
        int cost = costs[i][2];
        
        if (IsSame(nodeA, nodeB) == false)
        {
            MakeSame(nodeA, nodeB);
            answer += cost;
        }
    }
    
    
    return answer;
}