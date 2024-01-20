#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    answer.resize(end - begin + 1, 0);
    
    for (long long idx = 1; idx <= 10000000; ++idx)
    {
        long long start = max(idx * 2, ((begin + idx - 1) / idx) * idx);
        
        for (int k = start; k <= end; k += idx)
            answer[k - begin] = idx;
    }
    
    if (begin == 1)
        answer[0] = 0;
    
    return answer;
}