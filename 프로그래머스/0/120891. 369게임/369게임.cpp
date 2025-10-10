#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    string orderStr = to_string(order);
    
    for (char letter : orderStr)
    {
        if (letter == '3' || letter == '6' || letter == '9')
            ++answer;
    }
    
    return answer;
}