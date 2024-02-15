#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    while(n > 1)
    {   
        answer.push_back(n);
        
        // 만약 n이 짝수일 경우, 2로 나눈다.
        // 만약 n이 홀수일 경우, 3 x n + 1로 바꾼다.
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
    
    answer.push_back(n);
    
    return answer;
}