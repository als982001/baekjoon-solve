#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parentNode[101];

int GetParentNode(int node)
{
    if (node == parentNode[node])
        return node;
    
    return GetParentNode(parentNode[node]);
}

void UnionParentNode(int a, int b)
{
    int parentA = GetParentNode(a);
    int parentB = GetParentNode(b);
    
    if (parentA > parentB)
        parentNode[parentA] = parentB;
    else
        parentNode[parentB] = parentA;
}

bool CheckSameParent(int a, int b)
{
    return GetParentNode(a) == GetParentNode(b);
}

bool Compare(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), Compare);
    
    for (int node = 0; node < n; ++node)
        parentNode[node] = node;
    
    for (vector<int> link : costs)
    {
        int nodeA = link[0];
        int nodeB = link[1];
        int cost = link[2];
        
        if (!CheckSameParent(nodeA, nodeB))
        {
            answer += cost;
            UnionParentNode(nodeA, nodeB);
        }
    }
    
    
    return answer;
}




















/*

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

*/