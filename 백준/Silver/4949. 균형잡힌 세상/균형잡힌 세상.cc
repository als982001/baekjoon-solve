#include <iostream>
#include <vector>
#include <string>

using namespace std;

string line;
vector<string> strs;
vector<string> answers;

bool IsBracket(char c)
{
    return c == '(' || c == ')' || c == '[' || c == ']';
}

bool IsValidPair(char previousBracket, char currentBracket)
{
    if (currentBracket == ')')
        return previousBracket == '(';
    
    if (currentBracket == ']')
        return previousBracket == '[';
        
    return false;
}


bool CheckValidString(string str)
{
    bool isValid = true;
    vector<char> brackets;
    
    for (int i = 0; i < str.size() && isValid; ++i)
    {
        char bracket = str[i];
        bool isBracket = IsBracket(bracket);
        
        // 괄호가 아니라면 이번 글자는 패스
        if (isBracket == false)
            continue;
        
        if (bracket == '(' || bracket == '[')
        {
            brackets.push_back(bracket);
            continue;
        }
            
        // bracket == ')' || bracket == ']' 인 경우
        
        // 이전에 괄호가 나온 적이 없다면 valid 하지 않음
        if (brackets.empty())
        {
            isValid = false;
            break;
        }
        
        char previousBracket = brackets.back();
        brackets.pop_back();
                
        // 서로 쌍이 안 맞는 괄호면 valid하지 않음
        bool isValidPair = IsValidPair(previousBracket, bracket);
        
        if (isValidPair == false)
        {
            isValid = false;
            break;
        }
    }
    
    if (brackets.empty() == false)
        isValid = false;
        
    return isValid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    string line;

    while (true) {
        getline(cin, line); // 한 줄 입력 받기

        if (line == ".") // 종료 조건
            break;

        strs.push_back(line); // 저장
    }
    
    for (int i = 0; i < strs.size(); ++i)
    {
        string str = strs[i];
        
        bool isValid = CheckValidString(str);
        
        if (isValid)
            answers.push_back("yes");
        else
            answers.push_back("no");
    }

    for (int i = 0; i < answers.size(); ++i)
        cout << answers[i] << endl;
    
    return 0;
}