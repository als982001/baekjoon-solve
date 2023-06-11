#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool Compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end(), Compare);
    
    int idx = 0;
    int current = 0;
    priority_queue<pair<int, int>> pq;
        
    while (idx < jobs.size() || !pq.empty())
    {
        if (idx < jobs.size() && current >= jobs[idx][0])
        {
            pq.push({ -jobs[idx][1], jobs[idx][0] });
            ++idx;
            
            continue;
        }
        
        if (pq.empty() == false)
        {
            current += (-pq.top().first);
            answer += (current - pq.top().second);
            
            pq.pop();
        }  
        else
            current = jobs[idx][0];
    }
    
    return answer / jobs.size();
}

/*
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), Compare);
    
    int answer = 0;     // 답을 저장할 변수
    int idx = 0;        // 현재 작업 번호
    int current = 0;    // 현재 시간
    
    // pq.top().first: 작업 수행 시간
    // pq.top().second: 작업 시작 시간
    // 작업 수행 시간이 짧은 작업이 앞에 오도록 하기 위함
    priority_queue<pair<int, int>> pq;  // 대기열
    
    while(idx < jobs.size() || !pq.empty())
    {   
        // 한 번에 하나의 행동만 한다.
        // 대기열에 작업을 추가하거나 작업을 하거나
        
        // 1. 만약 현재 시간이 idx번의 작업 시작 시간과 같거나 더 뒤라면
        // 그 작업은 시작할 수 있다.
        if (idx < jobs.size() && current >= jobs[idx][0])
        {
            pq.push({ -jobs[idx][1], jobs[idx][0] });
            ++idx;
            
            continue;   // 대기열에 작업을 넣었으므로 continue
        }
        
        // 2. 만약 작업 대기열에 작업이 존재한다면
        // 작업을 수행한다.
        if (!pq.empty())
        {
            current += (-pq.top().first);  // 현재시간 = 현재시간 + 작업 수행 시간
            answer += (current - pq.top().second);  
            
            pq.pop();
        }
        else
            current = jobs[idx][0]; // 첫 작업 예외 처리
    }
    
    answer /= jobs.size();
    
    return answer;
}
*/