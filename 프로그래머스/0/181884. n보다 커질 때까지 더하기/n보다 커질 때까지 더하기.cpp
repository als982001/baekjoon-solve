#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int answer = 0;
    
    int idx = 0;
    
    while(answer <= n)
        answer += numbers[idx++];
    
    return answer;
}