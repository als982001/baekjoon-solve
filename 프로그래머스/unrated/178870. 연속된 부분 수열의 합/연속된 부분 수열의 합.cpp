#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    answer.push_back(0);
    answer.push_back(sequence.size() - 1);
    
    int startIdx = 0;
    int endIdx = 0;
    long long sum = sequence[startIdx];
    
    while(startIdx <= endIdx && endIdx < sequence.size())
    {
        if (sum == k)
        {
            int len = endIdx - startIdx;
            int answerLen = answer[1] - answer[0];
            
            if (answerLen > len)
            {
                answerLen = len;
                answer[0] = startIdx;
                answer[1] = endIdx;
            }
            
            sum -= sequence[startIdx++];
            
            if (startIdx > endIdx)
            {
                endIdx = startIdx;
                sum = sequence[endIdx];
            }
        }
        else if (sum > k)
        {
            sum -= sequence[startIdx++];
            
            if (startIdx > endIdx)
            {
                endIdx = startIdx;
                sum = sequence[endIdx];
            }
        }
        else
            sum += sequence[++endIdx];
    }
    
    return answer;
}