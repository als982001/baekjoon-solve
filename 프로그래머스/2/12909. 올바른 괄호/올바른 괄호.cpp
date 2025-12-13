#include<string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    if (s.size() % 2 == 1)
        return false;
    
    vector<int> stk;
    
    for (char letter : s)
    {
        if (letter == '(')
            stk.push_back(letter);
        else
        {
            if (stk.empty())
            {
                answer = false;
                break;
            }
            
            stk.pop_back();
        }
            
    }
    
    if (stk.empty() == false)
        answer = false;

    return answer;
}