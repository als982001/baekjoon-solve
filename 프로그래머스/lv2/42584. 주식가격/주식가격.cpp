#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); ++i)
    {
        int price = prices[i];
        int time = 0;
        
        for (int k = i + 1; k < prices.size(); ++k)
        {
            int nxtPrice = prices[k];
            
            ++time;
            
            if (price > nxtPrice)
                break;
        }
        
        answer.push_back(time);
    }
    
    return answer;
}