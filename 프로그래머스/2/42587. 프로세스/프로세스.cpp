#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int leftProcesses[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int targetPriority = priorities[location];
    
    queue<pair<int, int>> q;
    
    for (int i = 0; i < priorities.size(); ++i)
    {
        int priority = priorities[i];
        
        ++leftProcesses[priority];
        
        q.push({ priority, i });
    }
    
    while(!q.empty())
    {
        pair<int, int> process = q.front();
        q.pop();
        
        bool canExecute = true;
        
        for (int i = process.first + 1; i <= 9; ++i)
        {
            if (leftProcesses[i] > 0)
            {
                canExecute = false;
                break;
            }
        }
        
        if (canExecute)
        {
            ++answer;
            --leftProcesses[process.first];
            
            if (process.second == location)
                break;
        }
        else
            q.push(process);
            
    }
    
    
    
    
    
    return answer;
}