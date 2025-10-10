#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char curLetter = my_string[i];
        
        if (curLetter != letter[0])
            answer += curLetter;
    }
    
    return answer;
}