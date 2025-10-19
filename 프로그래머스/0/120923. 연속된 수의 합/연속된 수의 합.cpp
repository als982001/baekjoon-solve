#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    
    int baseNum = total / num;
    int startNum = 0;
    
    for (int n = baseNum - num - 1; n <= baseNum; ++n)
    {
        int sum = 0;
        
        for (int k = 0; k < num; ++k)
        {
            sum += (n + k);
        }
        
        if (sum == total)
        {
            startNum = n;
            break;
        }
    }
    
    for (int k = 0; k < num; ++k)
        answer.push_back(startNum + k);
    
    return answer;
}