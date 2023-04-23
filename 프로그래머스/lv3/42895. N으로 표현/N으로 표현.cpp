#include <string>
#include <vector>

using namespace std;

#define MAX 8

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



/*
#include <string>
#include <vector>
using namespace std;

#define MAX 8

int targetNum;
int minCount = MAX + 1; // 문제의 조건인 '최솟값이 8보다 크면 -1을 return 합니다.'를 위해 설정
int ns[MAX + 1];

void Check(int curCount, int curNum)
{   
    // 2-1. 만약, 현재 N을 사용한 횟수가 저장되어 있는 최소 사용 횟수보다 많거나 같으면 이 경우의 검사를 그만둔다.
    if (curCount >= minCount)
        return;
    
    // 2-2. 만약, 현재 숫자가 문제의 목표 숫자와 같다면, 답을 갱신할 수 있는 경우는 갱신하고 검사를 그만둔다.
    if (curNum == targetNum)
    {
        if (minCount > curCount)
            minCount = curCount;

        return;
    }

    // 2-3. 1번에서 미리 준비했던 그냥 붙이기로 만들어진 숫자들을 1개부터 8개까지의 경우를 사칙연산으로 계산하여 검사를 진행한다.
    for (int numberOfUses = 1; numberOfUses <= MAX; ++numberOfUses)
    {
        int nxtCount = curCount + numberOfUses;

        Check(nxtCount, curNum + ns[numberOfUses]);
        Check(nxtCount, curNum - ns[numberOfUses]);
        Check(nxtCount, curNum * ns[numberOfUses]);
        Check(nxtCount, curNum / ns[numberOfUses]);
    }

}

int solution(int N, int number) 
{
    // 1. 우선 사칙연산 외에 숫자를 이용가능한 방법인 그냥 붙이기(만약 N이 5라면 5, 55, 555 같은 경우)로 만들 수 있는 경우를 미리 준비한다.
    targetNum = number;

    ns[1] = N;

    for (int i = 2; i <= MAX; ++i)
        ns[i] = (ns[i - 1] * 10) + N;

    // 2. N을 하나 사용하는 경우부터 차근차근 살펴본다.
    Check(0, 0);

    if (minCount > MAX)
        return -1;
    else
        return minCount;
}
*/