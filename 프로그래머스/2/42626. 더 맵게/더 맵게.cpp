#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int> pq;
    
    for (int val : scoville)
        pq.push(-val);
    
    while(true)
    {
        if (-pq.top() >= K)
            break;
        
        // K 이상으로 만들 수 없는 경우
        if (pq.size() <= 1)
        {
            answer = -1;
            break;
        }
        
        int min1 = -pq.top();
        pq.pop();
        
        int min2 = -pq.top();
        pq.pop();
        
        int newVal = min1 + (min2 * 2);
        pq.push(-newVal);
        
        ++answer;
    }
    
    return answer;
}