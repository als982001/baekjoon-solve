#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> sizeCounts;
vector<int> sizes;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int size : tangerine)
    {
        if (sizeCounts[size])
            ++sizeCounts[size];
        else
        {
            sizeCounts[size] = 1;
            sizes.push_back(size);
        }
    }
    
    sort(sizes.begin(), sizes.end(), [&](int a, int b) { 
             return sizeCounts[a] > sizeCounts[b]; 
         });
    
    for (int size : sizes)
    {
        int curSizeCount = sizeCounts[size];
        
        k -= curSizeCount;
        ++answer;
    
        if (k <= 0)
            break;
    }
    
    return answer;
}











/*

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

*/