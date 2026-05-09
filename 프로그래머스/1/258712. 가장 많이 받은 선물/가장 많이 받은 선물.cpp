#include <string>
#include <vector>
#include <map>
#include <sstream>

#include <iostream>

#define MAX 51

using namespace std;

map<string, int> nameToIdx;
map<int, string> idxToName;
int record[MAX][MAX]; // 선물 기록
int giftScore[MAX]; // 선물 지수

int solution(vector<string> friends, vector<string> gifts) {
    // 0. 초기화
    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < MAX; ++b)
            record[a][b] = 0;
        
        giftScore[a] = 0;
    }
        
    
    // 1. friends 이름을 편의상 숫자로 변경할 수 있게 한다.
    for (int i = 0; i < friends.size(); ++i)
    {
        nameToIdx[friends[i]] = i;
        idxToName[i] = friends[i];
    }
    
    // 2. 2차원 배열에 선물 주고 받은 거 기록한다.
    for (string gift : gifts)
    {
        stringstream ss(gift);
        string segment;
        
        vector<int> idxes;
        
        while(getline(ss, segment, ' '))
            idxes.push_back(nameToIdx[segment]);
        
        record[idxes[0]][idxes[1]]++;
    }
    
    // 3. 선물 지수를 기록한다.
    for (int idx = 0; idx < friends.size(); ++idx)
    {
        int receivedGiftsCount = 0; // 받은 선물들 개수
        int sentGiftsCount = 0; // 준 선물들 개수
        
        for (int diffIdx = 0; diffIdx < friends.size(); ++diffIdx)
        {
            receivedGiftsCount += record[diffIdx][idx];
            sentGiftsCount += record[idx][diffIdx];
        }
        
        giftScore[idx] = sentGiftsCount - receivedGiftsCount;
    }
    
    // 4. 각 사람마다 체크한다.
    int maxGiftsNum = -1; // return할 값. 최대 선물 개수
    int maxGiftsIdx = -1; // 선물 최대한 많이 받는 사람 번호
   
    for (int idx = 0; idx < friends.size(); ++idx)
    {
        int curGiftsNum = 0;
        
        for (int diffIdx = 0; diffIdx < friends.size(); ++diffIdx)
        {
            // 자기 자신과는 비교하면 안됨
            if (idx == diffIdx)
                continue;
            
            // 두 사람이 선물을 주고 받은 기록이 하나도 없거나 주고받은 수가 같은 경우
            bool noRecord = record[idx][diffIdx] == 0 && record[diffIdx][idx] == 0;
            bool sameRecord = record[idx][diffIdx] == record[diffIdx][idx];
            
            if (noRecord || sameRecord)
            {
                // 선물 지수가 더 크면 받아야 함
                if (giftScore[idx] > giftScore[diffIdx])
                    ++curGiftsNum;
            }
            else
            {
                // 두 사람이 선물을 주고 받은 기록이 있는 경우, 더 많이 준 사람이 받아야 함
                if (record[idx][diffIdx] > record[diffIdx][idx])
                    ++curGiftsNum;
            }
        }
        
        // 저장되어 있던 값을 갱신한 수 있으면 갱신함
        if (maxGiftsNum < curGiftsNum)
        {
            maxGiftsNum = curGiftsNum;
            maxGiftsIdx = idx;
        }
    }
    
    return maxGiftsNum;
}









/*

#include <string>
#include <vector>
#include <sstream>
#include <map>

#define MAX 51

using namespace std;

int maxNameIdx = -1;
map<string, int> nameToIndex;
map<int, string> indexToName;

int giftsInfo[MAX][MAX]; // 주고받은 양 저장하는 테이블
int giving[MAX];
int given[MAX];
int giftPoint[MAX];

int solution(vector<string> friends, vector<string> gifts) {
    for (int idx = 0; idx < friends.size(); ++idx)
    {
        nameToIndex[friends[idx]] = idx;
        indexToName[idx] = friends[idx];
    }
    
    maxNameIdx = friends.size() - 1;
    
    for (int r = 0; r < MAX; ++r)
    {
        giving[r] = 0;
        given[r] = 0;
        giftPoint[r] = 0;
        
        for (int c = 0; c < MAX; ++c)
            giftsInfo[r][c] = 0;
    }
    
    for (string gift : gifts) 
    {
        stringstream ss(gift);
        string segment;
        
        vector<int> curGift;
        
        while(getline(ss, segment, ' '))
            curGift.push_back(nameToIndex[segment]);
        
        giftsInfo[curGift[0]][curGift[1]]++;
        
        giving[curGift[0]]++;
        given[curGift[1]]++;
    }
    
    for (int idx = 0; idx <= maxNameIdx; ++idx)
        giftPoint[idx] = giving[idx] - given[idx];
    
    int maxReceive = 0;
    
    for (int idx = 0; idx <= maxNameIdx; ++idx)
    {
        int curReceive = 0;
        
        for (int nxtIdx = 0; nxtIdx <= maxNameIdx; ++nxtIdx)
        {
            // 자기 자신인 경우 패스
            if (idx == nxtIdx)
                continue;
            
            // 준 게 받은 거보다 더 많은 경우
            bool 더많이줌 = giftsInfo[idx][nxtIdx] > giftsInfo[nxtIdx][idx];
            
            // 주고 받은 거 같으면서 지수가 더 높음
            bool 지수더큼 = (giftsInfo[idx][nxtIdx] == giftsInfo[nxtIdx][idx]) && (giftPoint[idx] > giftPoint[nxtIdx]);
            
            if (더많이줌 || 지수더큼)
                ++curReceive;
        }
        
        if (maxReceive < curReceive)
            maxReceive = curReceive;
    }
    
    
    return maxReceive;
}

*/