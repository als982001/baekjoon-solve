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