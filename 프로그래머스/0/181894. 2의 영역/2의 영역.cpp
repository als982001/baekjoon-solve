#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int startIndex = -1;
    int endIndex = -1;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == 2)
        {
            startIndex = startIndex == -1 ? i : startIndex;
            endIndex = i;
        }
    }
    
    if (startIndex == -1)
        answer.push_back(-1);
    else
    {
        for (int i = startIndex; i <= endIndex; ++i)
            answer.push_back(arr[i]);
    }
    
    return answer;
}