#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    for (char letter : my_string)
    {
        if ('0' <= letter && letter <= '9')
            answer.push_back(letter - '0');
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}