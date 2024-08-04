#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = "";
    
    string slicedString = my_string.substr(s, e - s + 1);
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        if (s <= i && i <= e)
        {
            for (int k = slicedString.size() - 1; k >= 0; --k)
                answer += slicedString[k];
            
            i = e;
        }
        else
        {
            answer += my_string[i];
        }
    }
    
    return answer;
}