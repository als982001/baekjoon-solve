#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool CompareJobs(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    // return할 변환 시간 (작업의 개수로 나누는 것은 편의상 가장 마지막에 실행)
    int conversionTime = 0;
    
    // 1. jobs를 요청 시각 순으로 정렬
    sort(jobs.begin(), jobs.end(), CompareJobs);
    
    // 2. 작업들을 우선 순위 순으로 처리
    int currentTime = 0; // 현재 시점
    int jobIdx = 0; // job의 순서
    priority_queue<pair<int, int>> pq; // first: 소요 시간, second: 작업 번호
    
    // 5. 3, 4번의 과정을 남은 작업이 있거나 대기 중인 작업이 있으면 반복
    while(jobIdx < jobs.size() || !pq.empty())
    {
        // 3. 현재 시점보다 이전 ~ 현재 시점까지 요청한 작업들을 pq에 저장
        while(jobIdx < jobs.size() && jobs[jobIdx][0] <= currentTime)
        {
            pq.push({ -jobs[jobIdx][1], -jobIdx });
            ++jobIdx;
        }
        
        // 4. pq에 작업이 하나 이상 있으면 가장 우선 순위 높은 거 하나 처리
        if (!pq.empty())
        {
            int takenTime = -pq.top().first;
            int jobIdx = -pq.top().second;
            pq.pop();
            
            // 4-1. 현재 시점을 처리 시간만큼 뒤로 이동
            currentTime += takenTime;
            
            // 4-2. 변환 시간에 작업 요청 ~ 종료까지 걸린 시간을 더함
            conversionTime += (currentTime - jobs[jobIdx][0]);
        }
        else
            ++currentTime; // 4-3. pq에 작업 없으면 현재 시점 + 1
    }
    
    // 6. 변환 시점을 작업 개수로 나눔
    int answer = conversionTime / jobs.size();
    
    return answer;
}