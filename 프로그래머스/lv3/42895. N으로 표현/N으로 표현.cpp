#include <string>
#include <vector>

using namespace std;

#define MAX 9

int targetNumber;
int answer = 987654321;
int dp[32111];
int ns[MAX + 1];

void Init(int N)
{
    ns[1] = N;
    
    for (int i = 2; i <= MAX; ++i)
        ns[i] = ns[i - 1] * 10 + N;
}

void Check(int count, int number)
{   
    if (count > MAX)
        return;
    
    if (number == targetNumber)
    {
        if (answer > count)
            answer = count;
        
        return;
    }
    
    for (int usageCount = 1; usageCount <= MAX; ++usageCount)
    {
        Check(count + usageCount, number + ns[usageCount]);
        Check(count + usageCount, number - ns[usageCount]);
        Check(count + usageCount, number * ns[usageCount]);
        Check(count + usageCount, number / ns[usageCount]);
    }
}

int solution(int N, int number) 
{
    targetNumber = number;
    Init(N);
    
    Check(0, 0);
    
    if (answer == 987654321)
        return -1;
    return answer;
}