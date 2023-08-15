#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    // 답에는 최악의 경우를 상정(가능한 가장 긴 수열, 즉 처음부터 끝까지)
    answer.push_back(0);
    answer.push_back(sequence.size() - 1);  
    
    int leftIdx = 0;    // 투 포인터의 왼쪽
    int rightIdx = 0;   // 투 포인터의 오른쪽
    long long sum = sequence[leftIdx];  // 연속된 부분 수열의 합
    
    while(leftIdx <= rightIdx && rightIdx < sequence.size())
    {   
        // 합이 k보다 같거나 클 때 (두 경우 공통으로 해야할 게 있다.)
        if (sum >= k)
        {
            // 만약 합이 k와 같을 경우
            if (sum == k)
            {   
                int len = rightIdx - leftIdx;
                int answerLen = answer[1] - answer[0];
            
                // 답을 갱신할 수 있으면 갱신한다.
                // 현재 저장된 답보다 현재 길이가 더 짧을 경우 갱신
                if (answerLen > len)
                {
                    answerLen = len;
                    answer[0] = leftIdx;
                    answer[1] = rightIdx;
                } 
            }

            // 왼쪽 포인터의 위치를 +1 한다.
            sum -= sequence[leftIdx++];
            
            // 왼쪽 포인터가 오른쪽 포인터의 오른쪽에 있을 경우
            // 오른쪽 포인터의 위치와 합을 갱신한다.
            if (leftIdx > rightIdx)
            {   
                rightIdx = leftIdx;
                sum = sequence[rightIdx];
            }
        }
        else    
        {
            // 합이 k보다 작은 경우
            // 오른쪽 포인터의 위치를 +1 한다.
            sum += sequence[++rightIdx];
        }
    }
    
    return answer;
}