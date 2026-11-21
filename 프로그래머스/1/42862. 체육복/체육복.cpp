#include <string>
#include <vector>

#define MAX 31

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int cloth[MAX];
    
    for (int idx = 1; idx <= n; ++idx)
        cloth[idx] = 1;
    
    for (int l : lost)
        --cloth[l];
    
    for (int r : reserve)
        ++cloth[r];
    
    for (int idx = 1; idx <= n; ++idx)
    {
        if (cloth[idx] == 0)
        {
            int befIdx = idx - 1;
            int nxtIdx = idx + 1;
            
            if (befIdx >= 1 && cloth[befIdx] > 1)
            {
                ++cloth[idx];
                --cloth[befIdx];
            }
            else if (nxtIdx <= n && cloth[nxtIdx] > 1)
            {
                ++cloth[idx];
                --cloth[nxtIdx];
                
            }
        }
    }
    
    for (int idx = 1; idx <= n; ++idx)
    {
        if (cloth[idx] > 0)
            ++answer;
    }
    
    return answer;
}