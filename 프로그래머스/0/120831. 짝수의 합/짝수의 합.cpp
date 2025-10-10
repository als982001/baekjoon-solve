#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int num = 0; num <= n; num +=2)
        answer += num;
    
    return answer;
}