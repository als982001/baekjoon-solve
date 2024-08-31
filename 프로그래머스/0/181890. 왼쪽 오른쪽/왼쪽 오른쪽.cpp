#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    for (int i = 0; i < str_list.size(); ++i)
    {
        if (str_list[i] == "l")
        {
            for (int k = 0; k < i; ++k)
                answer.push_back(str_list[k]);
            
            break;
        }
        else if (str_list[i] == "r")
        {
            for (int k = i + 1; k < str_list.size(); ++k)
                answer.push_back(str_list[k]);
            
            break;
        }
    }
    
    return answer;
}