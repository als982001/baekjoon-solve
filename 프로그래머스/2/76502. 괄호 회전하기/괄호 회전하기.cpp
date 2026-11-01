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











/*

#include <string>
#include <vector>

using namespace std;

string Rotate(string str)
{
    char firstLetter = str[0];
    return str.substr(1) + firstLetter;
}

bool CheckMatchedBrackets(char leftBracket, char rightBracket)
{
    if (leftBracket == '(' && rightBracket == ')')
        return true;
    if (leftBracket == '[' && rightBracket == ']')
        return true;
    if (leftBracket == '{' && rightBracket == '}')
        return true;
    
    return false;
}

bool CheckValidBrackets (string str)
{
    bool isValid = true;
    
    vector<char> letters;
    
    for (int i = 0; i < str.size(); ++i)
    {
        char letter = str[i];
        
        if (letter == '(' || letter == '[' || letter == '{')
            letters.push_back(letter);
        else
        {
            if (letters.size() == 0)
            {
                isValid = false;
                break;
            }
            
            char latestBracket = letters.back();
            letters.pop_back();
            
            bool isMatched = CheckMatchedBrackets(latestBracket, letter);
            
            if (isMatched == false)
            {
                isValid = false;
                break;
            }
        }
    }
    
    return letters.size() > 0;
}

int solution(string s) {
    int answer = 0;
    
    // 문자열 길이가 홀수이면 애초에 올바른 괄호일 수가 없다.
    if (s.size() % 2 == 1)
        return 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        bool isValid = CheckValidBrackets(s);
        
        if (isValid)
            ++answer;
        
        s = Rotate(s);
    }
    
    return answer;
}

*/