#include <string>
#include <vector>

using namespace std;

#define MAX 21

int answer = 0;
int nums[MAX];
vector<int> allNumbers;

void Check(int idx, int target)
{
    if (idx >= allNumbers.size())
    {
        int sum = 0;
        
        for (int i = 0; i < allNumbers.size(); ++i)
            sum += nums[i];
        
        if (sum == target)
            ++answer;
        
        return;
    }
    
    nums[idx] = allNumbers[idx];
    Check(idx + 1, target);
    
    nums[idx] = -allNumbers[idx];
    Check(idx + 1, target);
    
    nums[idx] = 0;
}

int solution(vector<int> numbers, int target) {
    allNumbers = numbers;
    
    Check(0, target);
    
    return answer;
}