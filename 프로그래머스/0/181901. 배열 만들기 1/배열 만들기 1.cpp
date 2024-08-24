#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k) {
    vector<int> answer;
    
    for (int num = 1; num <= n; ++num)
    {
        if (num % k == 0)
            answer.push_back(num);
    }
    
    return answer;
}