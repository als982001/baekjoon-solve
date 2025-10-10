#include <string>
#include <vector>

using namespace std;

bool Check합성수(int num)
{
    bool is합성수 = false;
    
    if (num == 1)
        return false;
    
    for (int i = 2; i < num; ++i)
    {
        if (num % i == 0)
        {
            is합성수 = true;
            break;
        }
    }
    
    return is합성수;
}

int solution(int n) {
    int answer = 0;
    
    for (int num = 1; num <= n; ++num)
    {
        bool is합성수 = Check합성수(num);
        
        if (is합성수)
            ++answer;
    }
    
    return answer;
}