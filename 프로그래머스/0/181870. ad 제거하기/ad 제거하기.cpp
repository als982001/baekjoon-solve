#include <string>
#include <vector>

using namespace std;

string targetWord = "ad";

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    for (int i = 0; i < strArr.size(); ++i)
    {
        string str = strArr[i];
        
        int targetStartIndex = str.find(targetWord);
        
        if (targetStartIndex == -1)
            answer.push_back(str);
    }
    
    
    
    return answer;
}