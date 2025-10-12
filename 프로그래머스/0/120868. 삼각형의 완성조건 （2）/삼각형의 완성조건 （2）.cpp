#include <string>
#include <vector>

using namespace std;

// sides에 있는 변이 가장 길이가 긴 경우
int Case1(int longgestSide, int leftSide)
{
    int result = 0;
    
    for (int len = 1; len <= longgestSide; ++len)
    {
        if (len + leftSide > longgestSide)
            ++result;
    }
        
    return result;
}

// sides에 없는 변의 길이가 가장 긴 경우
int Case2(int longgestSide, int leftSide)
{
    int sum = longgestSide + leftSide;
    
    return sum - longgestSide - 1;
}

int solution(vector<int> sides) {
    int answer = 0;
    
    int longgestSide = max(sides[0], sides[1]);
    int leftSide = min(sides[0], sides[1]);
    
    answer = Case1(longgestSide, leftSide) + Case2(longgestSide, leftSide);
    
    return answer;
}