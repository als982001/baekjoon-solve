#include <string>
#include <vector>
#include <numeric>

using namespace std;

char NumberToChar(char letter)
{
    return letter - '0' + 'a';
}

string solution(int age) {
    string answer = "";
    
    string ageStr = to_string(age);
    
    for (char letter : ageStr)
    {
        answer += NumberToChar(letter);
    }
    
    return answer;
}