#include <iostream>
#include <queue>
#include <vector>

#define MAX 10002

using namespace std;

int shortcutsNum, expresswayLen;
int minLen[MAX];
vector<pair<pair<int, int>, int>> shortcuts;

// 다익스트라 알고리즘을 이용하여 확인
void Check()
{
    minLen[0] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 0 });
    
    while(!pq.empty())
    {
        int curPos = pq.top().first;
        int curLen = -pq.top().second;
        
        pq.pop();

        if (curLen > minLen[curPos])
            continue;

        for (int i = 0; i < shortcutsNum; ++i)
        {
            int startPos = shortcuts[i].first.first;
            int endPos = shortcuts[i].first.second;
            int shortcutLen = shortcuts[i].second;
            
            if (startPos < curPos) 
                continue;
            
            // 현재 위치 -> 지름길 시작 위치 거리
            int curPosToStartPos = startPos - curPos;
            
            // 현재 지점 -> 지름길 시작 위치 -> 지름길 도착 위치
            int nxtLenWithShortcut = curPosToStartPos + shortcutLen + minLen[curPos];
            
            // 저장된 지름길 도착 위치보다 '현재 지점 -> 지름길 시작 위치 -> 지름길 도착 위치' 값이 더 작으면 저장
            if (minLen[endPos] > nxtLenWithShortcut)
            {
                minLen[endPos] = nxtLenWithShortcut;
                pq.push({ endPos, -nxtLenWithShortcut });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> shortcutsNum >> expresswayLen;
    
    for (int n = 0; n < shortcutsNum; ++n)
    {
        int startPos, endPos, roadLen;
        
        cin >> startPos >> endPos >> roadLen;
        
        shortcuts.push_back({ { startPos, endPos }, roadLen });
    }
    
    // 시작점인 0부터 각 거리까지 지름길을 이용하지 않을 경우로 초기화
    for (int i = 0; i <= expresswayLen; ++i)
        minLen[i] = i;
        
    Check();
        
    for (int expressway = 0; expressway <= expresswayLen; ++expressway)
    {   
        // 한 번도 값이 변경되지 않은 위치의 경우 마지막으로 확인
        if (minLen[expressway] < expressway)
        {
            // 현재 위치 -> 고속도로 끝까지 지름길 이용 안 하고 가는 거리
            int nxtMinLen = minLen[expressway] + abs(expresswayLen - expressway);
            
            // 저장된 지름길 도착 위치보다 '현재 위치 -> 고속도로 끝까지 지름길 이용 안 하고 가는 거리' 값이 더 작다면 저장
            if (minLen[expresswayLen] > nxtMinLen)
                minLen[expresswayLen] = nxtMinLen;
        }
    }
    
    cout << minLen[expresswayLen] << endl;

    return 0;
}