#include <string>
#include <vector>

using namespace std;

bool IsAlphabet(char letter)
{
    return ('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z');
}

int solution(string my_string) {
    int answer = 0;
    
    string numStr = "";
    
    for (char letter : my_string)
    {
        bool isAlphabet = IsAlphabet(letter);
        
        if (isAlphabet)
        {
            if (numStr.size() > 0)
            {
                int num = stoi(numStr);
                
                answer += num;
            }
            
            numStr = "";
        }
        else
            numStr += letter;
    }
    
    if (numStr.size() > 0)
    {
        answer += (stoi(numStr));
    }
    
    return answer;
}