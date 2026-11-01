#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> itemNums;

bool DiscountAll(vector<string> want)
{
    bool discountAll = true;
    
    for (string item : want)
    {        
        if (itemNums[item] != 0)
        {
            discountAll = false;
            break;
        }
    }
    
    return discountAll;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int idx = 0; idx < want.size(); ++idx)
    {
        string item = want[idx];
        int num = number[idx];
        
        itemNums[item] = num;
    }
    
    int startIdx = 0;
    int endIdx = 9;
    
    // 1. 1 ~ 10번째 날은 별도로 먼저 체크
    for (int idx = startIdx; idx <= endIdx; ++idx)
    {
        string item = discount[idx];
        --itemNums[item];
    }
    
    if (DiscountAll(want))
        ++answer;
    
    // 2. 두 번째 날부터는 각 날짜 끝부분에 해당하는 것만 뺐다가 더했다가 하면 됨
    while(endIdx + 1 < discount.size())
    {
        ++itemNums[discount[startIdx++]];
        --itemNums[discount[++endIdx]];
        
        if (DiscountAll(want))
            ++answer;
    }
  
    return answer;
}