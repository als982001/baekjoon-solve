#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> record[9];
set<int>::iterator iter1;
set<int>::iterator iter2;

bool CanInsert(int result, int curCnt)
{
    if (result <= 0)
        return false;
    
    bool canInsert = true;
    
    for (int cnt = curCnt - 1; cnt >= 1; --cnt)
    {
        if (record[cnt].find(result) != record[cnt].end())
        {
            canInsert = false;
            break;
        }
    }
    
    return canInsert;
}

void Record(int cnt, int N)
{
    int onlyN = 0;
    
    for (int t = 0, mul = 1; t < cnt; ++t, mul *= 10)
        onlyN += (N * mul);
    
    record[cnt].insert(onlyN);
        
    for (int leftCnt = 1; leftCnt < cnt; ++leftCnt)
    {
        int rightCnt = cnt - leftCnt;
            
        for (iter1 = record[leftCnt].begin(); iter1 != record[leftCnt].end(); ++iter1)
        {
            int leftNum = (*iter1);
            
            for (iter2 = record[rightCnt].begin(); iter2 != record[rightCnt].end(); ++iter2)
            {
                int rightNum = (*iter2);
                                
                int result1 = leftNum + rightNum;
                
                if (CanInsert(result1, cnt))
                    record[cnt].insert(result1);
                
                int result2 = leftNum - rightNum;
                
                if (CanInsert(result2, cnt))
                    record[cnt].insert(result2);
                
                int result3 = leftNum * rightNum;
                
                if (CanInsert(result3, cnt))
                    record[cnt].insert(result3);
                
                if (rightNum == 0)
                    continue;
                
                int result4 = leftNum / rightNum;
                
                if (CanInsert(result4, cnt))
                    record[cnt].insert(result4);
            }
        }
    }
}

int solution(int N, int number) {
    int answer = -1;
    
    record[1].insert(N);
    
    int usingNTwice[5] = { N + N, N * N, N / N, (10 * N) + N };
    
    for (int i = 0; i < 5; ++i)
        record[2].insert(usingNTwice[i]);
    
    for (int cnt = 3; cnt <= 8; ++cnt)
        Record(cnt, N);
    
    for (int cnt = 1; cnt <= 8; ++cnt)
    {
        if (record[cnt].find(number) != record[cnt].end())
        {
            answer = cnt;
            break;
        }
    }
    
    return answer;
}