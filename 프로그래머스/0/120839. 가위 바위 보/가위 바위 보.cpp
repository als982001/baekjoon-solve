#include <string>
#include <vector>

using namespace std;

char Win(char letter)
{
    if (letter == '2')
        return '0';
    
    if (letter == '0')
        return '5';
    
    if (letter == '5')
        return '2';
    
    return '2';
}

string solution(string rsp) {
    string answer = "";
    
    for (char letter : rsp)
    {
        answer += Win(letter);
    }
    
    return answer;
}