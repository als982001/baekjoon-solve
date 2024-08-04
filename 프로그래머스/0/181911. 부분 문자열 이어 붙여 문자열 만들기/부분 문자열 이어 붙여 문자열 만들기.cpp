#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";
    
    for (int i = 0; i < my_strings.size(); ++i)
    {
        string currentString = my_strings[i];
        vector<int> currentPart = parts[i];
        
        int startIndex = currentPart[0];
        int len = currentPart[1] - currentPart[0] + 1;
        
        string slicedString = currentString.substr(startIndex, len);
        
        answer += slicedString;
    }
    
    return answer;
}