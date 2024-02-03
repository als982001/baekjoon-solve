#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    int idx1 = 0;
    int idx2 = 0;
    
    while(idx1 < str1.size() || idx2 < str2.size())
    {
        if (idx1 < str1.size())
            answer += str1[idx1++];
        
        if (idx2 < str2.size())
            answer += str2[idx2++];
    }
    
    return answer;
}