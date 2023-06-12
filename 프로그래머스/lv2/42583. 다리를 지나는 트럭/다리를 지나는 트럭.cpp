#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int truckIdx = 0;       // 트럭의 인덱스
    int current = 1;        // 현재 시간 (경과 시간 1부터 트럭이 다리에 올라갈 수 있다.)
    int totalWeight = 0;    // 다리 위의 트럭들 무게의 합
    queue<pair<int, int>> trucksOnBridge; // first: 무게, second: 다리에 올라온 시간
    
    // 모든 트럭이 다리에 올라가지 못했거나, 다리 위에 트럭이 존재하는 경우 반복문을 진행한다.
    while(truckIdx < truck_weights.size() || trucksOnBridge.size() > 0)
    {   
        // 이미 다리를 건넌 트럭은 다리 위에서 제거한다.
        while(trucksOnBridge.empty() == false)
        {
            pair<int, int> truck = trucksOnBridge.front();
            
            // 현재 시간 - 트럭이 다리에 올라간 시간 >= 다리 길이 -> 다리를 건넘
            if (current - truck.second >= bridge_length)
            {
                trucksOnBridge.pop();
                totalWeight -= truck.first;
            }
            else
                break;
        }
        
        // 만약 현재 트럭의 인덱스가 주어진 트럭의 범위 안이라면
        // 트럭이 다리에 올라갈 수 있는지 검사한다.
        if (truckIdx < truck_weights.size())
        {
            int currentTruck = truck_weights[truckIdx];
            
            // 만약 다리에 트럭이 올라갈 공간이 있으면서
            // 현재 다리 위의 트럭들의 총 무게 + 현재 트럭 무게 <= 주어진 무게 조건 이라면 다리로 올라갈 수 있다.
            if (trucksOnBridge.size() < bridge_length && totalWeight + currentTruck <= weight)
            {
                trucksOnBridge.push({ currentTruck, current }); // 다리에 올라간 것을 표현
                totalWeight += currentTruck;                    // 총 무게에 현재 트럭의 무게를 더해준다.
                 ++truckIdx;                                    // 다음 트럭을 가리킴
            }
        }
        
        ++current;  // 시간이 1 경과한다.
    }
        
    answer = current - 1;   // 마지막 차례에서 ++current; 한 거를 빼줘야 한다.
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> onBridge;
    int totalTruck = truck_weights.size();
    int totalWeight = 0;
    int time = 0;
    int passNum = 0;
    int idx = 0;
    
    while(passNum < totalTruck)
    {
        while(onBridge.empty() == false)
        {
            pair<int, int> truck = onBridge.front();
            
            if (truck.second <= time)
            {
                totalWeight -= truck.first;
                onBridge.pop();
                
                ++passNum;
            }
            else
                break;
        }
        
        if (idx < totalTruck)
        {
             int truckWeight = truck_weights[idx];
        
            if (onBridge.size() < bridge_length && totalWeight + truckWeight <= weight)
            {
                onBridge.push({ truckWeight, time + bridge_length });
                totalWeight += truckWeight;
                ++idx;
            }
        }
        
        ++time;
    }
    
    return time;
}
*/