#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    while (n > 0)
    {
        int num = n % 10;
        answer += num;
        
        n /= 10;
    }
    
    return answer;
}