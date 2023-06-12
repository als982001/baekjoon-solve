#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    int truckIdx = 0;
    int current = 0;
    int totalWeight = 0;
    queue<pair<int, int>> trucksOnBridge; // first: 무게, second: 다리에 올라온 시간
    
    while(truckIdx < truck_weights.size() || trucksOnBridge.size() > 0)
    {   
        // 이미 다리를 건넌 트럭은 다리 위에서 제거한다.
        while(trucksOnBridge.empty() == false)
        {
            pair<int, int> truck = trucksOnBridge.front();
            
            if (current - truck.second >= bridge_length)
            {
                trucksOnBridge.pop();
                totalWeight -= truck.first;
            }
            else
                break;
        }
        
        if (truckIdx < truck_weights.size())
        {
            int currentTruck = truck_weights[truckIdx];
        
            if (trucksOnBridge.size() < bridge_length && totalWeight + currentTruck <= weight)
            {
                trucksOnBridge.push({ currentTruck, current });
                totalWeight += currentTruck;
                 ++truckIdx;
            }
        }
        
        ++current;
    }
        
    answer = current;
    
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