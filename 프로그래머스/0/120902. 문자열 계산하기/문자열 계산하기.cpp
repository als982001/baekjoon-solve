#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    istringstream iss(my_string);

    int answer = 0;
    int x;
    string op;

    // 첫 숫자를 읽고 시작
    iss >> answer;

    // 이후는 "연산자 op"와 "숫자 x"를 묶어서 반복
    while (iss >> op >> x) {
        if (op == "+")      
            answer += x;
        else /* op == "-"*/ 
            answer -= x;
    }
    return answer;
}