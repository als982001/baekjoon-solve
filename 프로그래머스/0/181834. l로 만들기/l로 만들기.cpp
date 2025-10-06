#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    
    for (int i = 0; i < myString.size(); ++i)
    {
        char letter = myString[i];
        
        if (letter <= 'l')
            letter = 'l';
        
        answer += letter;
    }
    
    return answer;
}