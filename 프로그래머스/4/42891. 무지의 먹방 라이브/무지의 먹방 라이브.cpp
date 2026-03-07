#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long totalFoods = 0;
    
    for (int foodTime : food_times)
        totalFoods += foodTime;
    
    // k 시간 내에 다 먹어버림
    if (totalFoods <= k)
        return -1;
        
    priority_queue<pair<int, int>> pq;
    
    long long eatenFoods = 0; // 음식 별 먹은 음식 양
    long long leftFoodsNum = food_times.size(); // 남은 음식 종류 개수
    
    for (int i = 0; i < food_times.size(); ++i)
        pq.push({ -food_times[i], -i });
    
    while(!pq.empty())
    {
        long long minFood = -pq.top().first;
        
        long long foodDiff = minFood - eatenFoods;
        
        // 음식 남아 있는 경우
        if (foodDiff > 0)
        {
            long long t = foodDiff * leftFoodsNum; // minFood 다 먹는데 걸리는 시간
            
            // 시간 내에 먹을 수 있는 경우
            if (k >= t)
            {
                eatenFoods = minFood;
                k -= t;
            }
            else // 시간 내에 못 먹으니까 종료
                break;
        }
        
        pq.pop();
        --leftFoodsNum;
    }
    
    vector<int> leftFoodsIdxes;
    
    while(!pq.empty())
    {
        leftFoodsIdxes.push_back(-pq.top().second);
        pq.pop();
    }
    
    sort(leftFoodsIdxes.begin(), leftFoodsIdxes.end());
    
    int targetIdx = k % leftFoodsIdxes.size();
    
    return leftFoodsIdxes[targetIdx] + 1;
}