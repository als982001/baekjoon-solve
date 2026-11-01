#include <string>
#include <vector>
#include <queue>

using namespace std;

int GetRequiredDay(int progress, int speed)
{
    int leftProgress = 100 - progress;
    
    int reqDay = leftProgress / speed;
    
    if (leftProgress % speed != 0)
        ++reqDay;
    
    return reqDay;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int curReqDay = -1;
    int deployCnt = 0;
    queue<int> reqDays;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        int progress = progresses[i];
        int speed = speeds[i];
        
        int reqDay = GetRequiredDay(progress, speed);
        
        reqDays.push(reqDay);
    }
    
    while(!reqDays.empty())
    {
        if (curReqDay == -1)
        {
            curReqDay = reqDays.front();
            
            reqDays.pop();
            deployCnt = 1;
        }
        
        while(!reqDays.empty())
        {
            int nxtReqDay = reqDays.front();
            
            if (curReqDay >= nxtReqDay)
            {
                reqDays.pop();
                ++deployCnt;
            }
            else 
            {
                answer.push_back(deployCnt);
                curReqDay = -1;
                
                break;
            }      
        }
    }
    
    if (deployCnt > 0)
        answer.push_back(deployCnt);
    
    return answer;
}