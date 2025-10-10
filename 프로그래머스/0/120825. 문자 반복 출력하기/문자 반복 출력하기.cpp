#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) {
    string answer = "";
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char letter = my_string[i];
        
        for (int k = 0; k < n; ++k)
            answer += letter;
    }
    
    return answer;
}