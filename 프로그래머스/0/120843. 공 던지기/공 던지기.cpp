#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int qqq = 0;
    
    for (int t = 1; t < k; ++t)
    {
        qqq += 2;
        
        if (qqq >= numbers.size())
            qqq -= numbers.size();
    }
    
    return numbers[qqq];
}