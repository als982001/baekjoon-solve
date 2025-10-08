#include <string>
#include <vector>

using namespace std;

bool CheckSmallLetter (char letter)
{
    return 'a' <= letter && letter <= 'z';
}

bool CheckCapitalLetter (char letter)
{
    return 'A' <= letter && letter <= 'Z';
}

char SmallToCapital (char letter)
{
    return letter - 'a' + 'A';
}

char CapitalToSmall (char letter)
{
    return letter - 'A' + 'a';
}

string ConvertIntoCapitalLetters (string str)
{
    string result = "";
    
    for (int i = 0; i < str.size(); ++i)
    {
        char letter = str[i];
        
        bool isSmallLetter = CheckSmallLetter(letter);
        
        if (isSmallLetter)
            result += SmallToCapital(letter);
        else
            result += letter;
    }
    
    return result;
}

string ConvertIntoSmallLetters (string str)
{
    string result = "";
    
    for (int i = 0; i < str.size(); ++i)
    {
        char letter = str[i];
        
        bool isCapitalLetter = CheckCapitalLetter(letter);
        
        if (isCapitalLetter)
            result += CapitalToSmall(letter);
        else
            result += letter;
    }
    
    return result;
}

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < strArr.size(); ++i)
    {
        string str = strArr[i];
        
        if (i % 2 == 0)
            answer.push_back(ConvertIntoSmallLetters(str));
        else
            answer.push_back(ConvertIntoCapitalLetters(str));
    }
    
    return answer;
}