#include <string>
#include <vector>

using namespace std;

int CheckLength(int arrLen)
{
    int result = 2;
    
    while(arrLen > result)
        result *= 2;
    
    return result;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr);
    
    if (arr.size() == 1)
        return arr;
    
    int requiredLen = CheckLength(arr.size());
    
    for (int i = arr.size(); i < requiredLen; ++i)
        answer.push_back(0);
    
    return answer;
}