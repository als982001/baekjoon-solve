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