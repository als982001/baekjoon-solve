#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    
    int xIdx = myString.find('x');
        
    while(xIdx != -1)
    {
        string str = myString.substr(0, xIdx);
        
        if (str.size() > 0)
            answer.push_back(str);
        
        myString = myString.substr(xIdx + 1);
        
        xIdx = myString.find('x');
    }
    
    if (myString.size() > 0)
        answer.push_back(myString);
    
    sort(answer.begin(), answer.end());
    
    return answer;
}