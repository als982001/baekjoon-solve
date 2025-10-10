#include <string>
#include <vector>

using namespace std;

int EMPTY = -1;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    int i = 0;
    
    while(i < arr.size())
    {
        if (answer.size() == 0)
            answer.push_back(arr[i++]);
        else
        {
            if (answer.back() == arr[i])
            {
                answer.pop_back();
                ++i;
            }
            else
                answer.push_back(arr[i++]);
        }
    }
    
    if (answer.size() == 0)
        answer.push_back(EMPTY);
    
    return answer;
}