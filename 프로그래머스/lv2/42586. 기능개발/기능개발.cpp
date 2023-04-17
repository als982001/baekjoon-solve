#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for (int i = 0; i < progresses.size(); ++i)
    {
        int progress = progresses[i];
        int speed = speeds[i];
        int leftProgress = 100 - progress;
        
        int reqDay = leftProgress / speed;
        if (leftProgress % speed > 0)
            ++reqDay;
        
        q.push(reqDay);
    }
    
    while(!q.empty())
    {
        int count = 1;
        int deployDay = q.front();
        q.pop();

        while(!q.empty())
        {
            int nxtReqDay = q.front();

            if (deployDay >= nxtReqDay)
            {
                q.pop();
                ++count;
            }
            else
                break;
    }
    
    answer.push_back(count);
    }
    
    return answer;
}