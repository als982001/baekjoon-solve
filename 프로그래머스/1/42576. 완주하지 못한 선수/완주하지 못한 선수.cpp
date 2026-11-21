#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> completionMap;
    
    for (string c : completion)
    {
        if (completionMap[c] == 0)
            completionMap[c] = 1;
        else
            ++completionMap[c];
    }
    
    for (string p : participant)
    {
        if (completionMap[p] == 0)
        {
            answer = p;
            break;
        }
        
        --completionMap[p];
    }
    
    return answer;
}