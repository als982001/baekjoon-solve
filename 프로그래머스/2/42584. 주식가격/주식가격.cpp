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
        
        if (stk.empty())
            stk.push(priceInfo);
        else
        {
            if (stk.top().price <= priceInfo.price)
                stk.push(priceInfo);
            else
            {
                while(!stk.empty())
                {
                    PriceInfo prevPriceInfo = stk.top();
                                    
                    if (prevPriceInfo.price <= priceInfo.price)
                        break;
                    else
                    {
                        int dur = idx - prevPriceInfo.idx;
                        answer[prevPriceInfo.idx] = dur;
                        
                        stk.pop();
                    }
                }
                
                stk.push(priceInfo);
            }
        }
    }
    
    while(!stk.empty())
    {
        PriceInfo prevPriceInfo = stk.top();
        stk.pop();
        
        answer[prevPriceInfo.idx] = prices.size() - prevPriceInfo.idx - 1;
    }
    
    return answer;
}











/*

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    vector<pair<int, int>> stk;
    
    int idx = 0;
    
    for (; idx < prices.size(); ++idx)
    {
        int price = prices[idx];
        
        if (stk.empty())
            stk.push_back({ price, idx });
        else
        {
            int prevPrice = stk.back().first;
            
            if (prevPrice < price)
                stk.push_back({ price, idx });
            else
            {
                while(stk.empty() == false)
                {
                    auto [prevPrice, prevPriceIdx] = stk.back();
                    
                    if (prevPrice <= price)
                        break;
                    
                    answer[prevPriceIdx] = idx - prevPriceIdx;
                    stk.pop_back();
                }
                
                stk.push_back({ price, idx });
            }
        }
    }
    
    for (auto [price, priceIdx] : stk)
        answer[priceIdx] = idx - priceIdx - 1;
    
    return answer;
}

*/