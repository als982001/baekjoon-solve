#include <string>
#include <vector>

using namespace std;

vector<int> DISCOUNT_RATES = { 10, 20, 30, 40 };

int GetDiscountPrice(int price, int discountRate)
{
    return price * (100 - discountRate) / 100;
}

vector<int> GetResult(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discountRates)
{
    vector<int> result(2, 0); // result[0]: 가입자, result[1]: 판매액
    
    for (vector<int> user : users)
    {
        int targetRate = user[0];
        int targetSum = user[1];
        
        int sum = 0;
        
        for (int i = 0; i < emoticons.size(); ++i)
        {
            int emoticon = emoticons[i];
            int discountRate = discountRates[i];
            
            if (discountRate >= targetRate)
            {
                int discountPrice = GetDiscountPrice(emoticon, discountRate);
                sum += discountPrice;
            }        
        }
        
        if (sum >= targetSum)
            ++result[0];   
        else
            result[1] += sum;
    }
    
    return result;
}

void CheckAllCase(vector<vector<int>>& users, vector<int>& emoticons, vector<int>& discountRates, vector<int>& answer, int emoticonIdx)
{
    if (emoticonIdx >= emoticons.size())
    {
        vector<int> result = GetResult(users, emoticons, discountRates);
        
        if (answer[0] < result[0])
        {
            answer[0] = result[0];
            answer[1] = result[1];
        }
        else if (answer[0] == result[0] && answer[1] < result[1])
        {
            answer[0] = result[0];
            answer[1] = result[1];
        }
        
        return;
        
    }
    
    for (int discountRate : DISCOUNT_RATES)
    {
        discountRates[emoticonIdx] = discountRate;
        
        CheckAllCase(users, emoticons, discountRates, answer, emoticonIdx + 1);
        
        discountRates[emoticonIdx] = 0;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    
    vector<int> discountRates(emoticons.size(), 0);
    
    CheckAllCase(users, emoticons, discountRates, answer, 0);
    
    return answer;
}
