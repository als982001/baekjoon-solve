#include <string>
#include <vector>

using namespace std;

bool CheckSmallLetter(char letter)
{
    return 'a' <= letter && letter <= 'z';
}

char SmallToCapital(char letter)
{
    bool isSmallLetter = CheckSmallLetter(letter);
    
    if (isSmallLetter)
        return letter - 'a' + 'A';
    
    return letter;
}

char CapitalToSmall(char letter)
{
    bool isSmallLetter = CheckSmallLetter(letter);
    
    if (isSmallLetter)
        return letter;
    
    return letter - 'A' + 'a';
}


bool CheckAlphabet(char letter)
{
    return CheckSmallLetter(letter) || ('A' <= letter && letter <= 'Z');
}

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < myString.size(); ++i)
    {
        char letter = myString[i];
        
        if (CheckAlphabet(letter) == false)
            answer += letter;
        else if (letter == 'a' || letter == 'A')
            answer += SmallToCapital(letter);
        else
            answer += CapitalToSmall(letter);
    }
    
    return answer;
}