#include <string>
#include <vector>

using namespace std;

bool IsSmallLetter(char letter)
{
    return 'a' <= letter && letter <= 'z';
}

char ConvertLetter(char letter)
{
    if (IsSmallLetter(letter))
        return letter - 'a' + 'A';
    
    return letter - 'A' + 'a';
}

string solution(string my_string) {
    string answer = "";
    
    for (char letter : my_string)
    {
        answer += ConvertLetter(letter);
    }
    
    return answer;
}