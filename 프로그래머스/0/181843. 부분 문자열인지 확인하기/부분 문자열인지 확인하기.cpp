#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string target) {
    int answer = 1;
    
    if (my_string.find(target) == -1)
        answer = 0;
    
    return answer;
}