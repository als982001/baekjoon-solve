#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

struct Process {
    int priority;
    int idx;
    
    Process(int priority, int idx)
    {
        this->priority = priority;
        this->idx = idx;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    int maxPriority = -1;
    
    queue<Process> processes;
    priority_queue<int> prs;
    
    for (int idx = 0; idx < priorities.size(); ++idx)
    {
        int priority = priorities[idx];
        
        prs.push(priority);
        
        Process process(priority, idx);
        
        processes.push(process);
    }
    
    while(!processes.empty())
    {
        Process process = processes.front();
        processes.pop();
        
        if (process.priority >= prs.top())
        {
            ++answer;
            
            prs.pop();
            
            if (process.idx == location)
                break;
        }
        else
            processes.push(process);
    }

    
    return answer;
}
