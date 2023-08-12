#include <string>
#include <vector>
using namespace std;

int reqGold, reqSilver;
vector<int> gold;
vector<int> silver;
vector<int> truck;
vector<int> oneWay;

long long Min(long long a, long long b)
{
    return a < b ? a : b;
}

bool Check(long long curTime)
{
    long long totalGold = 0;
    long long totalSilver = 0;
    long long totalMineral = 0;
    
    for (int i = 0; i < truck.size(); ++i)
    {   
        long long curTruck = truck[i];
        long long roundTrip = oneWay[i] * 2;
        
        long long curMineral = curTruck * (curTime / roundTrip);
        
        if (curTime % roundTrip >= oneWay[i])
            curMineral += curTruck;
        
        totalGold += Min(curMineral, (long long)gold[i]);
        totalSilver += Min(curMineral, (long long)silver[i]);
        totalMineral += Min(curMineral, (long long)gold[i] + (long long)silver[i]);
    }
    
    if (totalGold >= reqGold && totalSilver >= reqSilver && totalMineral >= reqGold + reqSilver)
        return true;
    else
        return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    
    reqGold = a;
    reqSilver = b;
    gold = g;
    silver = s;
    truck = w;
    oneWay = t;
    
    long long minTime = 0;
    long long maxTime = 10e14 * 3;
    answer = maxTime;
    
    while(minTime <= maxTime)
    {
        long long midTime = (minTime + maxTime) / 2;
        
        bool success = Check(midTime);
        
        if (success) 
        {
            answer = Min(answer, midTime);
            maxTime = midTime - 1;
        }
        else
            minTime = midTime + 1;
    }
    
    return answer;
}