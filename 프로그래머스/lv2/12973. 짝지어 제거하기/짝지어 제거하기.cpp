#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> stk;
    
    for (int i = 0; i < s.length(); ++i)
    {
        char letter = s[i];
        
        if (stk.empty() || stk.top() != letter)
            stk.push(letter);
        else
            stk.pop();
    }
    
    if (stk.empty())
        return 1;
    else
        return 0;
}