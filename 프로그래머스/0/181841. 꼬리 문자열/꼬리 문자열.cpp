#include <string>
#include <vector>

using namespace std;

string solution(vector<string> str_list, string ex) {
    string answer = "";
        
    for (int i = 0; i < str_list.size(); ++i)
    {
        string curStr = str_list[i];
        
        int startIndex = curStr.find(ex);
        
        if (startIndex == -1)
            answer += curStr;
    }
    
    return answer;
}