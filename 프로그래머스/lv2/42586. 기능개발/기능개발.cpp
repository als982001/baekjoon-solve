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

/*
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int size = progresses.size();
    
    vector<int> days;
    for (int i = 0; i < size; ++i) {

        int leftWork = 100 - progresses[i];
        int leftDay = leftWork / speeds[i];
        if (leftWork % speeds[i] > 0)
            leftDay += 1;
        
        days.push_back(leftDay);
    }

    for (int idx = 0; idx < size; ) {

        int curLeftDay = days[idx];

        int nxtIdx = idx + 1;

        while (nxtIdx < size && days[nxtIdx] <= curLeftDay)
            ++nxtIdx;

        answer.push_back(nxtIdx - idx);
        
        idx = nxtIdx;
    }
    
    return answer;
}
*/