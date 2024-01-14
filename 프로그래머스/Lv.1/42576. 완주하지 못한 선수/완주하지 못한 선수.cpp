#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> count;
    
    for (int i = 0; i < participant.size(); ++i)
        ++count[participant[i]];
    
    for (int i = 0; i < completion.size(); ++i)
        --count[completion[i]];
    
    for (int i = 0; i < participant.size(); ++i)
    {
        if (count[participant[i]] > 0)
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}