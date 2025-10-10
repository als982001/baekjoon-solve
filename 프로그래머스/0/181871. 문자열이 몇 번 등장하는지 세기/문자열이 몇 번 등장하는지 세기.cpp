#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    int endCheckIdx = myString.size() - pat.size() + 1;
    
    for (int checkIdx = 0; checkIdx < endCheckIdx; ++checkIdx)
    {
        bool isSame = true;
        
        for (int m = checkIdx, p = 0; p < pat.size(); ++m, ++p)
        {
            if (myString[m] != pat[p])
            {
                isSame = false;
                break;
            }
        }
        
        if (isSame)
            ++answer;
    }
    
    return answer;
}