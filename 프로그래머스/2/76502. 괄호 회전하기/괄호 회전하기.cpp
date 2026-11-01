#include <string>
#include <vector>

using namespace std;

bool IsLeft(char letter)
{
    return letter == '(' || letter == '[' || letter == '{';
}

bool IsMatched(char a, char b)
{
    if (a == '(') return b == ')';
    if (a == ')') return b == '(';
    
    if (a == '{') return b == '}';
    if (a == '}') return b == '{';
    
    if (a == '[') return b == ']';
    if (a == ']') return b == '[';
    
    return false;
}

int solution(string s) {
    int answer = 0;
    
    // 에지 케이스
    if (s.size() % 2 == 1)
        return 0;
    
    vector<char> stk;
    
    for (int t = 0; t < s.size(); ++t)
    {
        while(!stk.empty())
            stk.pop_back();
        
        bool isValid = true;
        
        for (char letter : s)
        {
            if (IsLeft(letter))
                stk.push_back(letter);
            else 
            {
                if (stk.empty() || IsMatched(letter, stk.back()) == false)
                {
                    isValid = false;
                    break;
                }
                else
                    stk.pop_back();
            }
        }
        
        if (stk.empty() == false)
            isValid = false;
        
        if (isValid)
            ++answer;
        
        char lastLetter = s.back();
        s.pop_back();
        s = lastLetter + s;
    }
    
    
    return answer;
}