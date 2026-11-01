#include <string>
#include <vector>

#define MAX 21

using namespace std;

int cnt = 0;
int plusMinus[2] = { 1, -1 };
int plusMinusRecord[MAX];
vector<int> givenNumbers;

void Check(int idx, int target)
{
    if (idx >= givenNumbers.size())
    {
        int sum = 0;
        
        for (int g = 0; g < givenNumbers.size(); ++g)
        {
            int num = givenNumbers[g];
            
            sum += (num * plusMinusRecord[g]);
        }
        
        if (sum == target)
            ++cnt;
        
        return;
    }
    
    for (int pmIdx = 0; pmIdx < 2; ++pmIdx)
    {
        plusMinusRecord[idx] = plusMinus[pmIdx];
        Check(idx + 1, target);
        plusMinusRecord[idx] = 0;
    }
}

int solution(vector<int> numbers, int target) 
{
    
    for (int i = 0; i < numbers.size(); ++i)
        plusMinusRecord[i] = 0;
    givenNumbers = numbers;
    
    Check(0, target);
    
    return cnt;
}