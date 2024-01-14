#include <string>
#include <vector>

using namespace std;

vector<int> Check(int a, int b)
{
    while(true)
    {
        int endNum = min(a, b);
        bool finish = true;
        
        for (int i = 2; i <= endNum; ++i)
        {
            if (a % i == 0 && b % i == 0)
            {
                a /= i;
                b /= i;
                
                finish = false;
                
                break;
            }
        }
        
        if (finish)
            break;
    }
    
    return { a, b };
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int numer = (numer1 * denom2) + (numer2 * denom1);
    int denom = denom1 * denom2;
    
    vector<int> answer = Check(numer, denom);
    
    return answer;
}