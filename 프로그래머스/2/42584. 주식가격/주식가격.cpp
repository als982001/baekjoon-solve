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