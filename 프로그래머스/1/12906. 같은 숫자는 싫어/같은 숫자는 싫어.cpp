#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    vector<int> stk;
    
    for (int num : arr)
    {
        if (stk.empty())
        {
            stk.push_back(num);
            answer.push_back(num);
        }
        else
        {
            int lastNum = stk[stk.size() - 1];
            
            if (lastNum != num)
            {
                stk.push_back(num);
                answer.push_back(num);
            }
        }
    }

    return answer;
}