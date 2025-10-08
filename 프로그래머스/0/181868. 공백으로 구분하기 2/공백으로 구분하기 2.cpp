#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string letters = "";
    bool isEmptyLetter = false;
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char letter = my_string[i];
        
        if (letter == ' ')
        {
            if (letters.size() > 0)
            {
                answer.push_back(letters);
                letters = "";
            }
            
            isEmptyLetter = true;
            continue;
        }
        else
        {
            if (isEmptyLetter) 
                isEmptyLetter = false;
            
            letters += letter;
        }
    }
    
    if (letters.size() > 0)
        answer.push_back(letters);
    
    return answer;
}