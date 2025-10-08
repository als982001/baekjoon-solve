#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    int len = 0;
    int xIdx = -1;
    
    for (int i = 0; i < myString.size(); ++i)
    {
        char letter = myString[i];
        
        if (letter == 'x')
        {
            answer.push_back(len);
            
            xIdx = i;
            len = 0;
        
            continue;
        }
        
        ++len;        
    }
        
    answer.push_back(myString.size() - xIdx - 1);
    
    return answer;
}