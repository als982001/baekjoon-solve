#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{    
    queue<long long> q1;
    queue<long long> q2;
    
    long long sum1 = 0;
    long long sum2 = 0;
    
    for (int num : queue1)
    {
        q1.push(num);
        sum1 += num;
    }
    
    for (int num : queue2)
    {
        q2.push(num);
        sum2 += num;
    }
    
    int t = 0;
    int maxTime = (queue1.size() + queue2.size()) * 2;
    
    while (t <= maxTime)
    {
        if (sum1 < sum2)
        {
            long long num = q2.front();
            q2.pop();
            q1.push(num);
            
            sum2 -= num;
            sum1 += num;
        }
        else if (sum1 > sum2)
        {
            long long num = q1.front();
            q1.pop();
            q2.push(num);
            
            sum1 -= num;
            sum2 += num;
        }
        else
            break;
        
        ++t;
    }
    
    if (t > maxTime)
        return -1;
    
    return t;
}