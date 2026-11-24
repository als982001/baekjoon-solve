#include <string>
#include <vector>

#define MAX 99999999999999

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = MAX;
    
    long long minTime = 0;
    long long maxTime = -1;
    
    for (int t : times)
    {
        if (maxTime < t)
            maxTime = t;
    }
    
    maxTime *= n;
    
    while (minTime < maxTime)
    {
        long long curTime = (minTime + maxTime) / 2;
        
        long long sum = 0;
            
        for (int i = 0; i < times.size(); ++i)
        {
            long long t = times[i];
            sum += (curTime / t);
        }
        
        if (sum >= n)
        {
            answer = answer > curTime ? curTime : answer;
            maxTime = curTime;
        }
        else
            minTime = curTime + 1;
    }
    
    return answer;
}