#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define MAX 105
#define ROOT 1

using namespace std;

bool isPossible;
int lastNode;
int boxes[MAX];
int linkIdx[MAX];
int targetNums[MAX];
vector<int> boxOrder;
vector<int> linkedNodes[MAX];

// 답을 구할 수 있는지에 대한 상태 체크
// 0: 아직 모름
// 1: 답 구할 수 있음
// 2: target대로 숫자의 합 만들 수 없음
int CheckCondition()
{
    int result = 1;
    
    // 숫자의 합을 만들 수 없는 케이스 존재
    for (int node = 1; node <= lastNode; ++node)
    {
        if (boxes[node] > targetNums[node])
        {
            result = 2;
            break;
        }
    }
    
    if (result == 2)
        return 2;
    
    // 아직 모르는 케이스
    for (int node = 1; node <= lastNode; ++node)
    {
        int minBox = (targetNums[node] + 2) / 3;
        
        // 필요한 최소 박스만큼도 없다면 더 확인해봐야 함
        if (boxes[node] < minBox)
        {
            result = 0;
            break;
        }
    }
    
    if (result == 0)
        return 0;
    
    // 만들 수 있음
    return 1;
}

void FallBox()
{
    int node = ROOT;
    
    while(true)
    {
        // 리프 노드인 경우
        if (linkedNodes[node].size() == 0)
            break;
        
        int curLinkIdx = linkIdx[node];
        int nxtNode = linkedNodes[node][curLinkIdx];
        
        ++linkIdx[node];
        
        if (linkIdx[node] >= linkedNodes[node].size())
            linkIdx[node] = 0;
        
        node = nxtNode;
    }
    
    ++boxes[node];
    boxOrder.push_back(node);
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    
    isPossible = true;
    lastNode = target.size();
    
    for (vector<int> edge : edges)
    {
        linkedNodes[edge[0]].push_back(edge[1]);
    }
    
    for (int node = 1; node <= lastNode; ++node)
    {
        boxes[node] = 0;
        targetNums[node] = target[node - 1];
        linkIdx[node] = 0;
        
        sort(linkedNodes[node].begin(), linkedNodes[node].end());
    }

    
    while(true)
    {
        int checkResult = CheckCondition();
        
        // 숫자를 만들 수 있는지 없는지 판별됨
        if (checkResult != 0)
        {
            isPossible = checkResult == 1;
            break;
        }
        
        FallBox();
    }
    
    // target대로 숫자의 합을 만들 수 없는 경우
    if (isPossible == false)
        return { -1 };
    
    for (int node : boxOrder)
    {
        --boxes[node];
        int leftBox = boxes[node];
        int targetNum = targetNums[node];
        
        if (targetNum - 1 <= leftBox * 3)
        {
            answer.push_back(1);
            targetNums[node] -= 1;
        }
        else if (targetNum - 2 <= leftBox * 3)
        {
            answer.push_back(2);
            targetNums[node] -= 2;
        }
        else
        {
            answer.push_back(3);
            targetNums[node] -= 3;
        }
        
        
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