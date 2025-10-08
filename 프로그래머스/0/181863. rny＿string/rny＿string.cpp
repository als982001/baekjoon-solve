#include <string>
#include <vector>

using namespace std;

string solution(string rny_string) {
    string answer = "";
    
    if (rny_string.size() == 1)
    {
        if (rny_string[0] == 'm')
            return "rn";
        
        return rny_string;
    }
    
    for (int i = 0; i < rny_string.size(); ++i)
    {
        char letter = rny_string[i];
        
        if (letter == 'm')
            answer += "rn";
        else
            answer += letter;
        
    }
    
    return answer;
}