#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int elapsedTime = 0;
    
    queue<pair<int, int>> bridge;
    int totalWeightOnBridge = 0;
    
    int truckIdx = 0;
    
    while(truckIdx < truck_weights.size())
    {
        ++elapsedTime;
        
        int truckWeight = truck_weights[truckIdx];
        
        while(bridge.empty() == false)
        {
            auto [truckWeight, bridgeEnterTime] = bridge.front();
            
            bool crossBridge = elapsedTime - bridgeEnterTime >= bridge_length;
            
            if (crossBridge) 
            {
                totalWeightOnBridge -= truckWeight;
                bridge.pop();
            }
            else
                break;
        }
        
        if (bridge.size() < bridge_length && totalWeightOnBridge + truckWeight <= weight)
        {
            bridge.push({ truckWeight, elapsedTime });
            totalWeightOnBridge += truckWeight;
            
            ++truckIdx;
        }
    }
    
    cout << "경과 시간: " << elapsedTime << ", 다리에 남은 트럭: " << bridge.size() << endl;
    
    if (bridge.empty())
        return elapsedTime;
    
    while(bridge.size() > 1)
        bridge.pop();
    
    int lastTruckEnterTime = bridge.front().second;
    
    elapsedTime += (elapsedTime - lastTruckEnterTime + bridge_length);
    
    return elapsedTime;
}