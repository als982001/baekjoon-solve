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

/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> waiting;
    queue<pair<int, int>> bridge;  

    for (int i = 0; i < truck_weights.size(); ++i)
        waiting.push(truck_weights[i]);

    int t = 0;
    int curWeight = 0;
    int passed = 0;

    while (true) 
    {
        queue<pair<int, int>> tempBridge;
        
        while (!bridge.empty())
        {
            int curTime = bridge.front().first + 1;
            int curTruckWeight = bridge.front().second;
            bridge.pop();

            if (curTime < bridge_length) 
                tempBridge.push(make_pair(curTime, curTruckWeight));
            else
            {
                curWeight -= curTruckWeight;
                ++passed;
            }
        }
        
        bridge = tempBridge;

        if (passed >= truck_weights.size())
        {
            answer = t;
            break;
        }

        if (!waiting.empty() && weight - curWeight > 0) 
        {
            int frontTruckWeight = waiting.front();

            if (weight - curWeight >= frontTruckWeight) 
            {
                bridge.push(make_pair(0, frontTruckWeight));
                waiting.pop();
                curWeight += frontTruckWeight;
            }
        }

        ++t;
    }
   
    answer = t + 1;
    
    return answer;
}
*/