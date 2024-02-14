#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    int num = numLog[0];
    
    for (int i = 1; i < numLog.size(); ++i)
    {
        int nxtNum = numLog[i];
        
        if (nxtNum - num == 1)
            answer += "w";
        else if (nxtNum - num == -1)
            answer += "s";
        else if (nxtNum - num == 10)
            answer += "d";
        else if (nxtNum - num == -10)
            answer += "a";
        
        num = nxtNum;
    }
    
    return answer;
}