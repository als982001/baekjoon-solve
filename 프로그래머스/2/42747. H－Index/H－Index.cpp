#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool Compare(int a, int b)
{
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
        
    sort(citations.begin(), citations.end(), Compare);
    
    int lastIdx = citations.size() - 1;
    
    // 6 5 3 1 0
    
    for (int h = citations[0]; h >= 0; --h)
    {
        int idx = 0; 
        
        while(idx <= lastIdx && citations[idx] >= h)
            ++idx;
        
        int h이상 = idx;
        
        if (h이상 >= h && citations[idx] <= h)
        {
            if (answer < h)
                answer = h;
        }
    }
    
    
    return answer;
}
