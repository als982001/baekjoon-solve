#include <vector>
#include <string>
#define MAX 111
#define MAX_INF 987654321
#define MIN_INF -987654321
using namespace std;

int dpMax[MAX][MAX];
int dpMin[MAX][MAX];

int solution(vector<string> arr)
{
    vector<int> numbers;
    vector<char> operators;
    
    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < MAX; ++b)
        {
            dpMax[a][b] = MIN_INF;
            dpMin[a][b] = MAX_INF;
        }
    }
    
    for (string str : arr)
    {
        if (str == "+" || str == "-")
            operators.push_back(str[0]);
        else
            numbers.push_back(stoi(str));
    }
    
    for (int i = 0; i < numbers.size(); ++i)
    {
        int number = numbers[i];
        
        dpMax[i][i] = number;
        dpMin[i][i] = number;
    }
    
    // 0 1 2 3 4 5 6 7 8
    // 5 3 1 2 4 8 2 4 7
    // - + + - + - + -
    
    for (int len = 2; len <= numbers.size(); ++len)
    {
        for (int startIdx = 0; startIdx + len <= numbers.size(); ++startIdx)
        {
            int endIdx = startIdx + len - 1;
            
            for (int midIdx = startIdx; midIdx < endIdx; ++midIdx)
            {
                char curOperator = operators[midIdx];
                
                if (curOperator == '+')
                {
                    dpMax[startIdx][endIdx] = max(dpMax[startIdx][endIdx], dpMax[startIdx][midIdx] + dpMax[midIdx + 1][endIdx]);
                    dpMin[startIdx][endIdx] = min(dpMin[startIdx][endIdx], dpMin[startIdx][midIdx] + dpMin[midIdx + 1][endIdx]);
                }
                else
                {
                    dpMax[startIdx][endIdx] = max(dpMax[startIdx][endIdx], dpMax[startIdx][midIdx] - dpMin[midIdx + 1][endIdx]);
                    dpMin[startIdx][endIdx] = min(dpMin[startIdx][endIdx], dpMin[startIdx][midIdx] - dpMax[midIdx + 1][endIdx]);
                }
            }
        }
    }
    
    return dpMax[0][numbers.size() - 1];
}
