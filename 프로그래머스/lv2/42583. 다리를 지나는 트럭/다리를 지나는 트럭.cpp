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