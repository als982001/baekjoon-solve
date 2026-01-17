#include <string>
#include <vector>
#include <map>

using namespace std;

int dir[8][2] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };
map<pair<int, int>, bool> visited; // 특정 노드를 방문한 적이 있는지
map<pair<pair<int, int>, pair<int, int>>, bool> nodeToNode; // 노드 -> 노드를 방문한 적 있는지 

int solution(vector<int> arrows) {
    int answer = 0;
    
    int r = 0;
    int c = 0;
    
    visited[{ r, c }] = true;
    
    for (int arrow : arrows)
    {
        // 두 번에 걸쳐 이동하는 이유는, 경로가 노드 ~ 노드 사이를 뚫고 갈 수 있기 때문에 2배로 확장하여 이동하면서 체크
        for (int t = 0; t < 2; ++t)
        {
            int nxtR = r + dir[arrow][0];
            int nxtC = c + dir[arrow][1];
            
            // 현재 경로가 이전 경로랑 겹치면서 방문하지 않은 노드로 가는 경우, 방 개수 +1
            if (!nodeToNode[{{ r, c }, { nxtR, nxtC }}] && visited[{ nxtR, nxtC }])
                ++answer;
            
            visited[{ nxtR, nxtC }] = true;
            nodeToNode[{{ r, c }, { nxtR, nxtC }}] = true;
            nodeToNode[{{ nxtR, nxtC }, { r, c }}] = true;
            
            r = nxtR;
            c = nxtC;
        }
    }
    
    return answer;
    
}