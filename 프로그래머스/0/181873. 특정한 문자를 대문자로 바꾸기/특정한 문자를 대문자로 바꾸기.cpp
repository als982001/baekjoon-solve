#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    string answer = "";
    
    char targetAlp = alp[0];
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char letter = my_string[i];
        
        if (letter == alp[0])
            letter -= 32;
        
        answer += letter;
    }
    
    return answer;
}