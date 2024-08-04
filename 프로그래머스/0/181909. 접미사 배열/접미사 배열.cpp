#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        string slicedString = my_string.substr(i);
        answer.push_back(slicedString);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}