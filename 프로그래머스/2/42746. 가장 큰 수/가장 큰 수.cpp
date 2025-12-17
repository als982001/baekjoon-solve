#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

bool Compare(int a, int b)
{
    string strA = to_string(a);
    string strB = to_string(b);
    
    if (strA.size() == strB.size())
        return strA > strB;
    
    return (strA + strB) > (strB + strA);
}

string solution(vector<int> numbers) {
    bool isAllZero = true;
    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] != 0)
        {
            isAllZero = false;
            break;
        }
    }
    
    if (isAllZero)
        return "0";
    
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), Compare);
    
    for (int number : numbers)
        answer += (to_string(number));
    
    
    return answer;
}