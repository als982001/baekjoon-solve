#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for (int i = 0; i < my_string.size(); ++i)
    {
        char letter = my_string[i];
        
        if ('A' <= letter && letter <= 'Z')
            ++answer[letter - 'A'];
        else
            ++answer[letter - 'a' + 26];
    }
    
    return answer;
}