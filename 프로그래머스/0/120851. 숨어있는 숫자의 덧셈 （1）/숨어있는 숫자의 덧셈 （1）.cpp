#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (char letter : my_string)
    {
        if ('0' <= letter && letter <= '9')
            answer += (letter - '0');
    }
    
    return answer;
}