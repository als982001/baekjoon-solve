#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {    
    string answer = "";
    
    int lastPatIdx = myString.find_last_of(pat) - pat.size() + 1;
        
    for (int i = 0; i < lastPatIdx; ++i)
        answer += myString[i];
    
    answer += pat;
        
    return answer;
}