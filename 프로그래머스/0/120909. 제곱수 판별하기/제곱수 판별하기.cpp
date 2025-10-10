#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    
    for (int a = 1; a * a <= n; ++a)
    {
        if (a * a == n)
        {
            answer = 1;
            break;
        }
    }
    
    return answer;
}