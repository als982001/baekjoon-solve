#include <string>
#include <vector>

using namespace std;

int solution(int balls, int share) {
    if (share < 0 || share > balls) 
        return 0;
    
    // nCk = nC(n-k) 최소화
    if (share > balls - share) 
        share = balls - share;

    long long ans = 1;  
    
    for (int i = 1; i <= share; ++i) 
        ans = ans * (balls - share + i) / i;
    
    return static_cast<int>(ans); 
}