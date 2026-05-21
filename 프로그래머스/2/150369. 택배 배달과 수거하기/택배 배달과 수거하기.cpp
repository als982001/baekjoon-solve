#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<pair<int, int>> deliveryStk;
    stack<pair<int, int>> pickupStk;
    
    for (int idx = 0; idx < deliveries.size(); ++idx)
    {
        if (deliveries[idx] > 0)
            deliveryStk.push({ idx + 1, deliveries[idx] });
    }
    
    for (int idx = 0; idx < pickups.size(); ++idx)
    {
        if (pickups[idx] > 0)
            pickupStk.push({ idx + 1, pickups[idx] });
    }
    
    while(!deliveryStk.empty() || !pickupStk.empty())
    {
        int leftDeliveryCap = cap;
        int maxDeliveryIdx = 0;
        
        int leftPickupCap = cap;
        int maxPickupIdx = 0;
        
        while(leftDeliveryCap > 0 && !deliveryStk.empty())
        {
            pair<int, int> deliveryInfo = deliveryStk.top();
            deliveryStk.pop();
            
            if (leftDeliveryCap >= deliveryInfo.second)
            {
                leftDeliveryCap -= deliveryInfo.second;
                
                if (maxDeliveryIdx < deliveryInfo.first)
                    maxDeliveryIdx = deliveryInfo.first;
            }
            else
            {
                deliveryInfo.second -= leftDeliveryCap;
                leftDeliveryCap = 0;
                
                deliveryStk.push(deliveryInfo);
                
                if (maxDeliveryIdx < deliveryInfo.first)
                    maxDeliveryIdx = deliveryInfo.first;
            }
        }
        
        while(leftPickupCap > 0 && !pickupStk.empty())
        {
            pair<int, int> pickupInfo = pickupStk.top();
            pickupStk.pop();
            
            if (leftPickupCap >= pickupInfo.second)
            {
                leftPickupCap -= pickupInfo.second;
                
                if (maxPickupIdx < pickupInfo.first)
                    maxPickupIdx = pickupInfo.first;
            }
            else
            {
                pickupInfo.second -= leftPickupCap;
                leftPickupCap = 0;
                
                pickupStk.push(pickupInfo);
                
                if (maxPickupIdx < pickupInfo.first)
                    maxPickupIdx = pickupInfo.first;
            }
        }
        
        int maxIdx = max(maxDeliveryIdx, maxPickupIdx);
        
        answer += maxIdx;
    }
    
    answer *= 2;
    
    return answer;
}

















/*

#include <string>
#include <vector>
#include <stack>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<pair<int, int>> dStk; // 배달 스택
    stack<pair<int, int>> pStk; // 수거 스택
    
    for (int i = 0; i < deliveries.size(); ++i)
    {
        if (deliveries[i] > 0)
            dStk.push({ i + 1, deliveries[i] });
        
        if (pickups[i] > 0)
            pStk.push({ i + 1, pickups[i] });
    }
    
    while(!dStk.empty() || !pStk.empty())
    {    
        int maxDeliveryIdx = -1;
        int maxPickupIdx = -1;
        
        int deliveryCap = cap;
        int pickupCap = cap;
        
        // 배달 확인
        while(!dStk.empty() && deliveryCap > 0)
        {
            int deliveryIdx = dStk.top().first;
            int delivery = dStk.top().second;
        
            dStk.pop();
            
            if (maxDeliveryIdx == -1)
                maxDeliveryIdx = deliveryIdx;
             
            // 남은 배달 용량보다 배달할 게 많은 경우
            if (delivery > deliveryCap)
            {
                delivery -= deliveryCap;
                dStk.push({ deliveryIdx, delivery });
                
                break;
            }
            // 남은 배달 용량이 배달해야할 양이랑 같거나 작은 경우
            else
                deliveryCap -= delivery;
        }
        
        // 픽업 확인
        while(!pStk.empty() && pickupCap > 0)
        {
            int pickupIdx = pStk.top().first;
            int pickup = pStk.top().second;
            
            pStk.pop();
            
            if (maxPickupIdx == -1)
                maxPickupIdx = pickupIdx;
            
            // 남은 수거 용량보다 수거할 게 많은 경우
            if (pickup > pickupCap)
            {
                pickup -= pickupCap;
                pStk.push({ pickupIdx, pickup });
                
                break;
            }
            // 남은 수거 용량이 수거해야할 양이랑 같거나 작은 경우
            else
                pickupCap -= pickup;
        }
        
        answer += (max(maxDeliveryIdx, maxPickupIdx) * 2);
    }
    
    return answer;
}

*/