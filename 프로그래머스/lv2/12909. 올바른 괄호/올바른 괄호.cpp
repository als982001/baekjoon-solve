#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for (int i = 0; i < s.size(); ++i)
    {
        char parenthesis = s[i];
        
        if (stk.empty())
        {
            if (parenthesis == ')')
                return false;
            else
                stk.push(parenthesis);
        }
        else
        {
            if (parenthesis == '(')
                stk.push(parenthesis);
            else
                stk.pop();
        }
    }

    if (stk.empty() == false)
        return false;
    
    return true;
}