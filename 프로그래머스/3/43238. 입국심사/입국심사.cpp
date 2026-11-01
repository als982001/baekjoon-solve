#include <string>
#include <vector>

#define MAX 99999999999999

using namespace std;

long long Min(long long a, long long b)
{
    return a < b ? a : b;
}

long long Max(long long a, long long b)
{
    return a > b ? a : b;
}

long long solution(int n, vector<int> times) {
    long long answer = MAX;
    
    long long minTime = 1;
    long long maxTime = 0;
    
    for (int idx = 0; idx < times.size(); ++idx)
    {
        long long t = times[idx];
    
        maxTime = Max(t, maxTime);
    }

    maxTime *= n;
    
    while(minTime < maxTime)
    {
        long long curTime = (minTime + maxTime) / 2;
        
        long long sum = 0;
        
        for (int idx = 0; idx < times.size(); ++idx)
        {
            long long t = times[idx];
            
            sum += (curTime / t);
        }
        
        if (sum >= n)
        {
            maxTime = curTime;
            answer = Min(answer, curTime);
        }
        else
            minTime = curTime + 1;
            
    }
    
    return answer;
}
