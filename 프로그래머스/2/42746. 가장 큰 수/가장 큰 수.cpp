#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Compare(int a, int b)
{
    string strA = to_string(a);
    string strB = to_string(b);
    
    string resultA = strA + strB;
    string resultB = strB + strA;
    
    return resultA > resultB;
}

bool CheckAllZero(string str)
{
    bool allZero = true;
    
    for (int idx = 0; idx < str.size(); ++idx)
    {
        if (str[idx] != '0')
        {
            allZero = false;
            break;
        }
    }
    
    return allZero;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), Compare);
    
    for (int number : numbers)
        answer += to_string(number);
    
    // 에지케이스
    if (CheckAllZero(answer))
        return "0";
    
    return answer;
}