#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> numList;
map<int, int> numOfNums;

bool Compare(int a, int b)
{
    return numOfNums[a] > numOfNums[b];
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int i = 0; i < tangerine.size(); ++i)
    {
        int num = tangerine[i];
        
        if (numOfNums[num] == 0)
            numList.push_back(num);
        ++numOfNums[num];
    }
    
    sort(numList.begin(), numList.end(), Compare);
    
    for (int i = 0; i < numList.size(); ++i)
    {
        int num = numList[i];
        int curNumOfNum = numOfNums[num];
        
        ++answer;
        
        if (k > curNumOfNum)
            k -= curNumOfNum;
        else
            break;
    }
    
    
    return answer;
}