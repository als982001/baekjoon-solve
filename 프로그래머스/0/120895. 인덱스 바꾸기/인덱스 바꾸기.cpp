#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = my_string;
    
    char tempLetter = answer[num1];
    answer[num1] = answer[num2];
    answer[num2] = tempLetter;
    
    return answer;
}