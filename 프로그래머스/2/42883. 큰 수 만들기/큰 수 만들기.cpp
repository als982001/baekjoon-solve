#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) 
{
    string answer;
    
    int removeCount = k;
    
    for (int idx = 0; idx < number.size(); ++idx)
    {
        char digit = number[idx];
        
        while(answer.size() > 0 && removeCount > 0 && digit > answer.back())
        {
            answer.pop_back();
            --removeCount;
        }
        
        answer.push_back(digit);
    }
    
    while(removeCount > 0)
    {
        --removeCount;
        answer.pop_back();
    }
    
    return answer;
}