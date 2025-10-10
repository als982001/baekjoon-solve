#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char letter = my_string[i];
        
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            continue;
        
        answer += letter;
    }
    
    return answer;
}