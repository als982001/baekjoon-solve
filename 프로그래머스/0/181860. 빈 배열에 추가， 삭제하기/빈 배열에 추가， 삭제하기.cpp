#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); ++i)
    {
        int num = arr[i];
        bool curFlag = flag[i];
        
        if (curFlag)
        {
            for (int k = 0; k < num + num; ++k)
                answer.push_back(num);
        }
        else
        {
            for (int k = 0; k < num; ++k)
                answer.pop_back();
        }
    }
    
    return answer;
}