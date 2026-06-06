#include <string>
#include <vector>
#include <queue>

using namespace std;


long long Sum(vector<int> v)
{
    long long sum = 0;
    
    for (int num : v)
        sum += num;
    
    return sum;
}

int solution(vector<int> v1, vector<int> v2) {
    int answer = -2;
    
    int t = 0;
    int maxTry = (v1.size() + v2.size()) * 2;
    long long sum1 = Sum(v1);
    long long sum2 = Sum(v2);
    
    queue<int> q1;
    queue<int> q2;
    
    for (int num : v1)
        q1.push(num);
    
    for (int num : v2)
        q2.push(num);
    
    while(t <= maxTry)
    {
        if (sum1 < sum2)
        {
            int num = q2.front();
            q2.pop();
            
            q1.push(num);
            
            sum1 += num;
            sum2 -= num;
        }
        else if (sum1 > sum2)
        {
            int num = q1.front();
            q1.pop();
            
            q2.push(num);
            
            sum1 -= num;
            sum2 += num;
        }
        else
            break;
        
        ++t;
    }
    
    if (t > maxTry)
        return -1; 
    
    return t;
}
















/*

#include <string>
#include <vector>
#include <queue>

using namespace std;

int Sum(vector<int> q)
{
    int sum = 0;

    for (int i = 0; i < q.size(); ++i)
        sum += q[i];

    return sum;
}


int solution(vector<int> queue1, vector<int> queue2) 
{
    int time = 0;
    int totalLen = queue1.size() + queue2.size();
    long long sum1 = Sum(queue1);
    long long sum2 = Sum(queue2);

    queue<int> q1;
    for (int i = 0; i < queue1.size(); ++i)
        q1.push(queue1[i]);

    queue<int> q2;
    for (int i = 0; i < queue2.size(); ++i)
        q2.push(queue2[i]);

    while (time < totalLen * 2)
    {
        if (sum1 > sum2)
        {
            int popped = q1.front();
            q1.pop();
            q2.push(popped);

            sum1 -= popped;
            sum2 += popped;

            ++time;
        }
        else if (sum1 < sum2)
        {
            int popped = q2.front();
            q2.pop();
            q1.push(popped);

            sum2 -= popped;
            sum1 += popped;

            ++time;
        }
        else if (sum1 == sum2)
            return time;
    }

    return -1;
}

*/