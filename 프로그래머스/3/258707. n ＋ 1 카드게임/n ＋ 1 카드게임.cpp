#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> myHand;
set<int> drawn;

bool Check(set<int>& cards1, set<int>& cards2, int targetNum)
{
    bool success = false;
    
    for (int card : cards1)
    {
        int pairCard = targetNum - card;
        
        // cards1이랑 card2가 같은 경우.
        if (cards1 == cards2)
        {
            if (cards1.count(pairCard) && card != pairCard)
            {
                cards1.erase(card);
                cards1.erase(pairCard);
                
                success = true;
                break;
            }
        }
        else
        {
            if (cards2.count(pairCard))
            {
                cards1.erase(card);
                cards2.erase(pairCard);
                
                success = true;
                break;
            }
        }
            
    }
    
    return success;
}

int solution(int coin, vector<int> cards) {
    int answer = 1;
    
    int allCardsNum = cards.size();
    
    int cardIdx = 0;
    int targetNum = allCardsNum + 1;
    
    for (; cardIdx < allCardsNum / 3; ++cardIdx)
        myHand.insert(cards[cardIdx]);
    
    while(cardIdx < allCardsNum)
    {
        bool success = false;
        
        // 두 장만 뽑으면 되니까 그냥 같은 코드 두 번 작성함
        drawn.insert(cards[cardIdx++]);
        drawn.insert(cards[cardIdx++]);
                
        // CASE 1. 현재 가지고 있는 카드들로만 target number를 만들 수 있는 케이스
        bool case1 = Check(myHand, myHand, targetNum);
        
        if (case1)
        {
            success = true;
            ++answer;
            
            continue;
        }
        
        // CASE 2. 현재 가지고 있는 카드 + 뽑은 카드로 target number를 만들 수 있는 케이스
        if (coin > 0)
        {
            bool case2 = Check(myHand, drawn, targetNum);

            if (case2)
            {
                success = true;
                --coin;
                ++answer;
                
                continue;
            }
        }
        
        // CASE 3. 뽑은 카드들로만 target number를 만들 수 있는 케이스
        if (coin > 1)
        {
            bool case3 = Check(drawn, drawn, targetNum);
            
            if (case3)
            {
                success = true;
                coin -= 2;
                ++answer;
                
                continue;
            }
        }
        
        if (!success)
            break;
    }
    
    return answer;
}