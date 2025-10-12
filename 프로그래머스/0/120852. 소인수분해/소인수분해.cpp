#include <string>
#include <vector>
#include <cmath>

#include <iostream>

#define MAX 10001

using namespace std;

bool isPrimeNumber[MAX];
bool checkedNumber[MAX];

void Init()
{
    for (int num = 0; num < MAX; ++num)
        isPrimeNumber[num] = true;
    isPrimeNumber[0] = false;
    isPrimeNumber[1] = false;
    
    for (int num = 2; num < MAX; ++num)
    {
        if (isPrimeNumber[num] == false)
            continue;
        
        for (int nextNum = num + num; nextNum < MAX; nextNum += num)
            isPrimeNumber[nextNum] = false;
    }
}

int GetNextPrimeNumber(int num, int maxNum)
{
    int nextPrimeNumber = -1;
    
    for (int nextNum = num + 1; nextNum <= maxNum; ++nextNum)
    {
        if (isPrimeNumber[nextNum])
        {
            nextPrimeNumber = nextNum;
            break;
        }
    }
    
    return nextPrimeNumber;
}

vector<int> solution(int n) {
    vector<int> answer;
    
    Init();
    
    int copiedN = n;
    int curNum = 2;
    
    while(copiedN > 1)
    {
        if (copiedN % curNum == 0)
        {
            copiedN /= curNum;
            
            if (checkedNumber[curNum] == false)
            {
                checkedNumber[curNum] = true;
            }
        }
        else
        {
            curNum = GetNextPrimeNumber(curNum, n);
                        
            if (curNum == -1)
                break;
        }
    }
    
    for (int num = 2; num <= n; ++num)
    {
        if (checkedNumber[num])
            answer.push_back(num);
    }
    
    
    return answer;
}