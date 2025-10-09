#include <string>
#include <vector>

using namespace std;

int SumAllValues (vector<int> numList)
{
    int sum = 0;
    
    for (int i = 0; i < numList.size(); ++i)
        sum += numList[i];
    
    return sum;
}

int MultipleAllValues (vector<int> numList)
{
    int result = numList[0];
    
    for (int i = 1; i < numList.size(); ++i)
        result *= numList[i];
    
    return result;
}

int solution(vector<int> num_list) {
    int answer = 0;
    
    if (num_list.size() >= 11)
        answer = SumAllValues(num_list);
    else
        answer = MultipleAllValues(num_list);
    
    return answer;
}