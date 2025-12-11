#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int numCount = 0;
    set<int> record;
    
    for (int num : nums)
    {
        if (record.find(num) == record.end())
        {
            record.insert(num);
            ++numCount;
        }
    }
    
    answer = min((int)(nums.size() / 2), numCount);
    
    
    return answer;
}