#include <string>
#include <vector>

using namespace std;

string EMPTY = "EMPTY";

bool CheckLetterABC(char letter)
{
    return letter == 'a' || letter == 'b' || letter == 'c';
}

vector<string> solution(string myStr) {
    vector<string> answer;
    
    int idx = 0;
    
    while(idx < myStr.size())
    {
        bool isLetterABC = CheckLetterABC(myStr[idx]);
        
        if (isLetterABC == false)
        {
            string str = "";
            
            while(CheckLetterABC(myStr[idx]) == false && idx < myStr.size())
                str += myStr[idx++];
            
            answer.push_back(str);
        }
        else
            ++idx;
    }
    
    if (answer.size() == 0)
        answer.push_back(EMPTY);
    
    return answer;
}