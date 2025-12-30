#include <string>
#include <vector>

using namespace std;

int givenOperators[2] = { 1, -1 };
int operators[21];

void Check(vector<int>& numbers, int idx, int target, int& answer)
{
    if (idx == numbers.size())
    {
        int sum = 0;
        
        for (int i = 0; i < numbers.size(); ++i)
            sum += (operators[i] * numbers[i]);
        
        if (sum == target)
            ++answer;
        
        return;
    }
    
    for (int i = 0; i < 2; ++i)
    {
        int curOperator = givenOperators[i];
        
        operators[idx] = curOperator;
        Check(numbers, idx + 1, target, answer);
        operators[idx] = 0;
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    for (int i = 0; i < 21; ++i)
        operators[i] = 0;
    
    Check(numbers, 0, target, answer);
    
    return answer;
}