#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int fac = 1;
    int num = 1;
    
    while(true)
    {
        fac *= num;
        
        if (fac > n)
            break;
        
        ++num;
    }
    
    if (fac > n)
    {
        --num;
    }
    
    
    answer = num;
    
    return answer;
}