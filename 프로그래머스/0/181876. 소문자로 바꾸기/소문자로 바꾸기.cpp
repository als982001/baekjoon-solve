#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < myString.size(); ++i)
    {
        char letter = myString[i];
        
        if ('A' <= letter && letter <= 'Z')
            answer += (letter + 32);
        else
            answer += letter;
    }
    
    return answer;
}