#include <string>
#include <vector>

#define EMPTY -1

using namespace std;

int GetRequiredDays(int leftProgress, int speed)
{
    int requiredDays = leftProgress / speed;
    
    if (leftProgress % speed > 0)
        ++requiredDays;
    
    return requiredDays;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int maxReqDays = EMPTY;
    int stackedJobNum = 0;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        int progress = progresses[i];
        int speed = speeds[i];
        
        int requiredDays = GetRequiredDays(100 - progress, speed);
        
        if (maxReqDays == EMPTY)
        {
            maxReqDays = requiredDays;
            stackedJobNum = 1;
        }
        else if (maxReqDays < requiredDays)
        {
            int deployedJobNums = stackedJobNum;
            
            answer.push_back(deployedJobNums);
            
            maxReqDays = requiredDays;
            stackedJobNum = 1;
        }
        else
            ++stackedJobNum;
    }
    
    if (stackedJobNum > 0)
        answer.push_back(stackedJobNum);
    
    return answer;
}