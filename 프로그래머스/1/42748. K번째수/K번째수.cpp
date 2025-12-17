#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int> command : commands)
    {
        int startIdx = command[0] - 1;
        int endIdx = command[1] - 1;
        int targetIdx = command[2] - 1;
        
        vector<int> nums;
        
        for (int idx = startIdx; idx <= endIdx; ++idx)
            nums.push_back(array[idx]);
        
        sort(nums.begin(), nums.end());
        
        answer.push_back(nums[targetIdx]);
    }
    
    
    return answer;
}