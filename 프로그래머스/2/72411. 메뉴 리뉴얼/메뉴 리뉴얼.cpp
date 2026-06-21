#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;

bool isChosen[11];
map<string, int> record;

void Check(string order, string choice, int num, int cnt, int startIdx)
{
    if (num == cnt)
    {
        if (record[choice] > 0)
            ++record[choice];
        else
            record[choice] = 1;
        return;
    }

    for (int i = startIdx; i < order.size(); ++i)
    {
        if (!isChosen[i])
        {
            isChosen[i] = true;
            choice.push_back(order[i]);

            Check(order, choice, num, cnt + 1, i + 1);
            
            choice.pop_back();
            isChosen[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < orders.size(); ++i)
        sort(orders[i].begin(), orders[i].end());
    
    for (int c = 0; c < course.size(); ++c)
    {
        int curCourse = course[c];
        
        record.clear();
        memset(isChosen, false, sizeof(isChosen));

        for (int i = 0; i < orders.size(); ++i)
        {
            string curOrder = orders[i];

            if (curOrder.size() >= curCourse)
                Check(curOrder, "", curCourse, 0, 0);
        }

        map<string, int>::iterator iter;

        int maxNum = 0;
        string maxOrder = "";

        for (iter = record.begin(); iter != record.end(); ++iter)
        {
            int curNum = iter->second;

            if (curNum > 1 && maxNum < curNum)
                maxNum = curNum;
        }
        
        for (iter = record.begin(); iter != record.end(); ++iter)
        {
            int curNum = iter->second;

            if (curNum == maxNum)
                answer.push_back(iter->first);
        }
          
    }

    sort(answer.begin(), answer.end());

    return answer;
}

