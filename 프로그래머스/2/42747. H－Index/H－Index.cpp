#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end(), Compare);
    
    for (int h = citations[0]; h >= 0; --h)
    {
        int idx = 0;
        
        while(idx < citations.size() && h <= citations[idx])
            ++idx;
        
        int citeCount = idx;
        
        if (citeCount >= h && citations[idx] <= h)
        {
            answer = h;
            break;
        }
        
        
    }
    
    return answer;
}