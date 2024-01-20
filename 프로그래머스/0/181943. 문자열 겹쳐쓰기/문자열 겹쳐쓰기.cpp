#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        if (i == s)
        {
            for (int k = 0; k < overwrite_string.size(); ++k)
                answer += overwrite_string[k];
            
            i = i + overwrite_string.size() - 1;
        }
        else
            answer += my_string[i];
    }
    
    return answer;
}