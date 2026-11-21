#include <string>
#include <vector>
#include <stack>

using namespace std;

struct PriceInfo
{
    int price;
    int idx;
    
    PriceInfo(int price, int idx)
    {
        this->price = price;
        this->idx = idx;
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    stack<PriceInfo> stk;
    
    int curIdx = 0;
    
    for (; curIdx < prices.size(); ++curIdx)
    {
        int curPrice = prices[curIdx];
        
        if (stk.empty() == false)
        {
            while(!stk.empty() && stk.top().price > curPrice)
            {
                PriceInfo befPriceInfo = stk.top();
                stk.pop();
                
                int dur = curIdx - befPriceInfo.idx;
                
                answer[befPriceInfo.idx] = dur;
            }
        }
        
        PriceInfo curPriceInfo(curPrice, curIdx);
        stk.push(curPriceInfo);    
    }
    
    while(stk.empty() == false)
    {
        PriceInfo befPriceInfo = stk.top();
        stk.pop();
        
        int dur = curIdx - befPriceInfo.idx - 1;
        
        answer[befPriceInfo.idx] = dur;
    }
    
    
    return answer;
}











/*

#include <string>
#include <vector>
#include <stack>

using namespace std;

struct PriceInfo
{
    int price;
    int idx;
    
    PriceInfo(int price, int idx)
    {
        this->price = price;
        this->idx = idx;
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    int idx = 0;
    stack<PriceInfo> stk;
    
    for (; idx < prices.size(); ++idx)
    {
        PriceInfo priceInfo(prices[idx], idx);

        if (!stk.empty())
        {
            if (stk.top().price > priceInfo.price)
            {
                while(!stk.empty())
                {
                    PriceInfo prevPriceInfo = stk.top();
                                    
                    // 현재 가격이 이전 가격에 비해 떨어진 경우
                    if (prevPriceInfo.price > priceInfo.price)
                    {
                        int dur = idx - prevPriceInfo.idx; // 지속 기간
                        answer[prevPriceInfo.idx] = dur;
                        
                        stk.pop();
                    }
                    else
                        break;
                }
            }
        }
        
        stk.push(priceInfo);
    }
    
    while(!stk.empty())
    {
        PriceInfo prevPriceInfo = stk.top();
        stk.pop();
        
        answer[prevPriceInfo.idx] = prices.size() - prevPriceInfo.idx - 1;
    }
    
    return answer;
}

*/