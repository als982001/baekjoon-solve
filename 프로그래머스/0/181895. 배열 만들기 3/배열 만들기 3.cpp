#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (int i = 0; i < intervals.size(); ++i)
    {
        vector<int> interval = intervals[i];
        
        for (int k = interval[0]; k <= interval[1]; ++k)
            answer.push_back(arr[k]);
    }
    
    return answer;
}