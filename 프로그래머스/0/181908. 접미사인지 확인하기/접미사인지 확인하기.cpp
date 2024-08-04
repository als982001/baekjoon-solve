#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 1;
    
    int myStringLen = my_string.size();
    int isSuffixLen = is_suffix.size();
    
    for (int i = myStringLen - isSuffixLen, j = 0; i < myStringLen; ++i, ++j)
    {
        if (my_string[i] != is_suffix[j])
        {
            answer = 0;
            break;
        }
    }
    
    return answer;
}