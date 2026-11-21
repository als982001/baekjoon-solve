#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
        
    for (vector<int> command : commands)
    {
        int startIdx = command[0] - 1;
        int endIdx = command[1] - 1;
        int targetIdx = command[2] - 1;
        
        priority_queue<int> q;
        
        for (int idx = startIdx; idx <= endIdx; ++idx)
            q.push(-array[idx]);
        
        for (int idx = 0; idx < targetIdx; ++idx)
            q.pop();
        
        answer.push_back(-q.top());
    }
    
    return answer;
}