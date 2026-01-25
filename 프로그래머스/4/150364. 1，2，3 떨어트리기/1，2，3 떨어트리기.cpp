#include <string>
#include <vector>
#include <algorithm>

#define MAX 105

using namespace std;

int lastNode = -1;
int boxes[MAX];
int linkIdxes[MAX];
vector<int> linkedNodes[MAX];
vector<int> dropOrder;

void FallBox()
{    
    int node = 1;
    
    while(true)
    {
        // 리프노드
        if (linkedNodes[node].size() == 0)
            break;
        
        int linkIdx = linkIdxes[node];
        
        linkIdxes[node] = linkIdx + 1 >= linkedNodes[node].size() ? 0 : linkIdx + 1;
        
        node = linkedNodes[node][linkIdx];
    }
    
    // 해당 리프 노드에 박스 개수 +1
    ++boxes[node];
    dropOrder.push_back(node);
}

// 0: 아직 못 만듬
// 1: 만들 수 있음
// 2: 못 만듬
int CanMakeTarget(vector<int>& targets)
{
    // 아예 못 만드는 경우
    for (int node = 1; node <= lastNode; ++node)
    {
        if (boxes[node] > targets[node - 1])
            return 2;
    }
    
    // 아직 못 만드는 경우가 있는 경우
    for (int node = 1; node <= lastNode; ++node)
    {
        int target = targets[node - 1];
        int boxNum = boxes[node];
        
        int minBoxNeeded = (target + 2) / 3;
        
        if (boxNum < minBoxNeeded)
            return 0;
    }
    
    // 만들 수 있음
    return 1;
}

vector<int> Make(vector<int>& targets)
{
    vector<int> result;
    
    for (int node: dropOrder)
    {
        --boxes[node];
        
        int val = 0;
        
        int target = targets[node - 1];
        int remainingBoxes = boxes[node];
        
        // 1로 하나 채운 후, 나머지 어떻게든 채울 수 있는 경우
        if (target - 1 <= remainingBoxes * 3)
            val = 1;
        // 2로 하나 채운 후, 나머지 어떻게든 채울 수 있는 경우
        else if (target - 2 <= remainingBoxes * 3)
            val = 2;
        else
            val = 3;
        
        result.push_back(val);
        targets[node - 1] -= val;
    }
    
    return result;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    // 초기화
    for (int i = 0; i < MAX; ++i)
    {
        boxes[i] = 0;
        linkedNodes[i].clear();
        linkIdxes[i] = 0;
    }
    dropOrder.clear();
    
    for (vector<int> edge : edges)
        linkedNodes[edge[0]].push_back(edge[1]);
    
    lastNode = target.size();
    
    for (int node = 1; node <= lastNode; ++node)
    {
        if (linkedNodes[node].size() > 1)
            sort(linkedNodes[node].begin(), linkedNodes[node].end());
    }
    
    int isPossible = 0;
    
    while(true)
    {
        int result = CanMakeTarget(target);
        
        // 성공이든 실패든 결론이 남
        if (result != 0)
        {
            isPossible = result;
            break;
        }
        
        FallBox();
    }
    
    if (isPossible == 2)
        return { -1 };
    
    answer = Make(target);
    
    return answer;
}