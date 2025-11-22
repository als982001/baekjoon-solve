#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long idx = 0;
    
    for (long long idx = left; idx <= right; ++idx)
    {
        int r = (idx / n) + 1;
        int c = (idx % n) + 1;
        
        int num = max(r, c);
        
        answer.push_back(num);
    }
    
    
    return answer;
}