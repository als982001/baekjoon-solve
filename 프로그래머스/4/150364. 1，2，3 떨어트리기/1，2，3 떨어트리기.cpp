#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define ROOT 1
#define MAX 103

using namespace std;

int lastNode = -1;
int linkIdx[MAX];
int boxes[MAX];
vector<int> linkedNodes[MAX];
vector<int> boxOrder;
vector<int> targetNums;

// 박스 떨어트리기 상태 확인
// 2: target대로 숫자의 합을 만들 수 없는 경우
// 1: target대로 숫자의 합을 만들 수 있는 경우
// 0: 아직 모르는 경우
int CheckBoxCondition()
{
    int result = 1;
    
    // 숫자의 합을 만들 수 없는 경우
    // box 개수가 target 숫자보다 큰 경우 (1로 전부 채워도 초과되버리는 케이스)
    
    for (int node = 1; node <= lastNode; ++node)
    {
        if (targetNums[node] < boxes[node])
        {
            result = 2;
            break;
        }
    }
    
    if (result == 2)
        return 2;
    
    // 아직 모르는 경우
    for (int node = 1; node <= lastNode; ++node)
    {
        int minBoxes = (targetNums[node] + 2) / 3;
        
        // 최소 박스 개수보다 모자란 경우
        if (boxes[node] < minBoxes)
        {
            result = 0;
            break;
        }
    }
    
    if (result == 0)
        return 0;
    
    return 1;
}

void UpdateLinkIdx(int node)
{
    int nxtLinkIdx = linkIdx[node] + 1;
    
    if (nxtLinkIdx >= linkedNodes[node].size())
        nxtLinkIdx = 0;
    
    linkIdx[node] = nxtLinkIdx;
}

void FallBox()
{
    int targetNode = ROOT;
    
    while(true)
    {
        // 리프노드인 경우
        if (targetNums[targetNode] > 0)
            break;
        
        int curLinkIdx = linkIdx[targetNode];
        int nxtNode = linkedNodes[targetNode][curLinkIdx];
        
        UpdateLinkIdx(targetNode);
        
        targetNode = nxtNode;
    }
    
    boxOrder.push_back(targetNode);
    boxes[targetNode]++;
}

int GetNumber(int targetNode)
{
    int targetNum = targetNums[targetNode];
    --boxes[targetNode];
    
    // 사전 순서니까 1부터 확인
    if (targetNum - 1 <= boxes[targetNode] * 3)
    {
        targetNums[targetNode] -= 1;
        return 1;
    }
    
    if (targetNum - 2 <= boxes[targetNode] * 3)
    {
        targetNums[targetNode] -= 2;
        return 2;
    }
    
    targetNums[targetNode] -= 3;
    return 3;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    bool success = true;
    
    for (vector<int> edge : edges)
    {
        linkedNodes[edge[0]].push_back(edge[1]);
        
        if (lastNode < edge[0])
            lastNode = edge[0];
        
        if (lastNode < edge[1])
            lastNode = edge[1];
    }
    
    for (int node = 1; node <= lastNode; ++node)
    {
        boxes[node] = 0;
        linkIdx[node] = 0;
        sort(linkedNodes[node].begin(), linkedNodes[node].end());
    }
    
    targetNums.push_back(0);
    
    for (int targetNum : target)
        targetNums.push_back(targetNum);
    
    while(true)
    {
        int checkResult = CheckBoxCondition();
        
        if (checkResult > 0)
        {
            if (checkResult == 2)
                success = false;
                
            break;
        }
        
        FallBox();
    }
    
    if (success == false)
        return { -1 };
    
    for (int targetNode : boxOrder)
    {
        int num = GetNumber(targetNode);
        answer.push_back(num);
    }
    
    return answer;
}













/*


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



*/