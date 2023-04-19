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

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int current = 0; current < prices.size() - 1; ++current) {

        int target = current + 1;
        for (; target < prices.size(); ++target) {
            
            if (prices[current] > prices[target])
                break;
        }

        if (target == prices.size())
            answer.push_back(target - current - 1);
        else
            answer.push_back(target - current);
    }
    answer.push_back(0);
    
    return answer;
}
*/