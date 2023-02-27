#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define MAX 20011
#define START 1

int dist[MAX];
vector<int> links[MAX];

int Check(int nodeNum)
{
    int maxDist = -1;
    int maxDistNum = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({ START, 0 });

    dist[START] = 0;

    while(!pq.empty())
    {
        int curNode = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();

        if (dist[curNode] < curDist)
            continue;

        for (int i = 0; i < links[curNode].size(); ++i)
        {
            int nxtNode = links[curNode][i];
            int nxtDist = curDist + 1;

            if (dist[nxtNode] > nxtDist)
            {
                dist[nxtNode] = nxtDist;
                pq.push({ nxtNode, -nxtDist });
            }
        }
    }

    for (int node = 2; node <= nodeNum; ++node)
    {
        if (maxDist < dist[node])
        {
            maxDist = dist[node];
            maxDistNum = 1;
        }
        else if (maxDist == dist[node])
            ++maxDistNum;
    }

    return maxDistNum;
}

int solution(int n, vector<vector<int>> edge) 
{
    for (int i = 0; i < MAX; ++i)
        dist[i] = MAX + MAX + MAX;

    for (int i = 0; i < edge.size(); ++i)
    {
        int nodeA = edge[i][0];
        int nodeB = edge[i][1];

        links[nodeA].push_back(nodeB);
        links[nodeB].push_back(nodeA);
    }

    int answer = Check(n);

    return answer;
}

/*
#define MAX 20011
#define INF 987654321
using namespace std;

int nodeNum;
int dist[MAX];
vector<pair<int, int>> link[MAX];

void Reset_Dist(int n) {
    for (int i = 1; i <= n; ++i)
        dist[i] = INF;
}

int solution(int n, vector<vector<int>> edge) {

    int answer = 0;

    int maxDist = 0;
    vector<int> farNode;

    for (int i = 0; i < edge.size(); ++i) {

        int a = edge[i][0];
        int b = edge[i][1];

        link[a].push_back(make_pair(b, 1));
        link[b].push_back(make_pair(a, 1));
    }

    int start = 1;
    Reset_Dist(n);
    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty()) {

        int curNode = pq.top().first;
        int curDist = -pq.top().second;
        pq.pop();

        if (curDist > dist[curNode])
            continue;

        for (int i = 0; i < link[curNode].size(); ++i) {

            int nxtNode = link[curNode][i].first;
            int nxtDist = curDist + link[curNode][i].second;

            if (dist[nxtNode] > nxtDist) {

                dist[nxtNode] = nxtDist;
                pq.push(make_pair(nxtNode, -nxtDist));
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {

        if (maxDist < dist[i]) {
            maxDist = dist[i];
            farNode.clear();
            farNode.push_back(i);
        }
        else if (maxDist == dist[i])
            farNode.push_back(i);
    }

    answer = farNode.size();

    return answer;
}
*/