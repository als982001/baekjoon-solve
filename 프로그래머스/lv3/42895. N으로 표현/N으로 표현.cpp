#include <string>
#include <vector>
using namespace std;

#define MAX 8

int targetNum;
int minCount = MAX + 1;
int ns[MAX + 1];

void Check(int curCount, int curNum)
{
    if (curCount >= minCount)
        return;
    
    if (curNum == targetNum)
    {
        if (minCount > curCount)
            minCount = curCount;

        return;
    }

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
    targetNum = number;

    ns[1] = N;

    for (int i = 2; i <= MAX; ++i)
        ns[i] = (ns[i - 1] * 10) + N;

    Check(0, 0);

    if (minCount > MAX)
        return -1;
    else
        return minCount;
}

/*
int n, num;
int maxCnt = 9;
int arr[9];

void Make_Array() {

    int input = n;

    for (int i = 1; i <= 8; ++i) {
        arr[i] = input;
        input = (input * 10) + n;
    }
}

void Find_Answer(int curCnt, int curNum) {

    if (curCnt >= maxCnt)
        return;

    if (curNum == num) {
        maxCnt = curCnt;
        return;
    }

    for (int numOfUse = 1; numOfUse <= 8; ++numOfUse) {

        int nxtCnt = curCnt + numOfUse;

        Find_Answer(nxtCnt, curNum + arr[numOfUse]);
        Find_Answer(nxtCnt, curNum - arr[numOfUse]);
        Find_Answer(nxtCnt, curNum * arr[numOfUse]);
        Find_Answer(nxtCnt, curNum / arr[numOfUse]);
    }
}

int solution(int N, int number) {
    
    n = N;
    num = number;

    Make_Array();
    Find_Answer(0, 0);

    if (maxCnt > 8)
        maxCnt = -1;

    return maxCnt;
}
*/