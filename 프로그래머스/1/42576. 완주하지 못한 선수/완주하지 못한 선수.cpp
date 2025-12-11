#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> completionNames;
    
    for (string person : completion)
    {
        if (completionNames[person] == 0)
            completionNames[person] = 1;
        else
            ++completionNames[person];
    }
    
    for (string person : participant)
    {
        if (completionNames[person] > 0)
            --completionNames[person];
        else
        {
            answer = person;
            break;
        }
    }
    
    
    return answer;
}