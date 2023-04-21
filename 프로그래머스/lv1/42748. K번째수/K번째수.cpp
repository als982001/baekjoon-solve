#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> command = commands[i];
        
        int startIdx = command[0] - 1;
        int endIdx = command[1] - 1;
        int targetIdx = command[2] - 1;
        
        vector<int> sliced;
        
        for (int idx = startIdx; idx <= endIdx; ++idx)
            sliced.push_back(array[idx]);
        
        sort(sliced.begin(), sliced.end());
        
        answer.push_back(sliced[targetIdx]);
    }
    
    return answer;
}