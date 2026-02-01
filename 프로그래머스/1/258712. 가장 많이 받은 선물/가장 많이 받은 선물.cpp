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