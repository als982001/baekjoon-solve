#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else
        return false;
}

int Time_To_Int(string record)
{
    int hour = stoi(record.substr(0, 2));
    int minute = stoi(record.substr(3, 2));

    return hour * 60 + minute;
}

int Cost_Time(int parkTime, int defaultTime, int unitTime)
{
    int timeDiff = parkTime - defaultTime;
    
    if (timeDiff % unitTime)
        return (timeDiff / unitTime) + 1;
    else
        return timeDiff / unitTime;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    map<int, int> parkStart;
    map<int, int> parkTime;
    map<int, bool> isParked;

    int timeCheck[10000] = { 0 };

    int defaultTime = fees[0];
    int defaultCost = fees[1];
    int unitTime = fees[2];
    int unitCost = fees[3];
    int endTime = Time_To_Int("23:59");

    for (int i = 0; i < records.size(); ++i)
    {
        string curRecord = records[i];

        int curNum = stoi(curRecord.substr(6, 4));
        int curTime = Time_To_Int(curRecord);

        if (isParked[curNum] == false)
        {
            isParked[curNum] = true;
            parkStart[curNum] = curTime;
        }
        else
        {
            isParked[curNum] = false;
  
            if (parkTime[curNum] == 0)
                parkTime[curNum] = curTime - parkStart[curNum];
            else
                parkTime[curNum] += (curTime - parkStart[curNum]);            
        }
    }

    map<int, bool>::iterator iter;

    for (iter = isParked.begin(); iter != isParked.end(); ++iter)
    {
        if (iter->second == true)
        {
            int curNum = iter->first;

            if (parkTime[curNum] == 0)
                parkTime[curNum] = endTime - parkStart[curNum];
            else
                parkTime[curNum] += (endTime - parkStart[curNum]);
        }
    }
       
    vector<pair<int, int>> costs;

    map<int, int>::iterator timeIter;
    for (timeIter = parkTime.begin(); timeIter != parkTime.end(); ++timeIter)
    {
        int curNum = timeIter->first;
        int curTime = timeIter->second;
        int curCost = defaultCost;

        if (curTime > defaultTime)
            curCost += Cost_Time(curTime, defaultTime, unitTime) * unitCost;
        
        costs.push_back(make_pair(curNum, curCost));

    }

    sort(costs.begin(), costs.end(), Compare);

    for (int i = 0; i < costs.size(); ++i)
        answer.push_back(costs[i].second);
    
    return answer;
}