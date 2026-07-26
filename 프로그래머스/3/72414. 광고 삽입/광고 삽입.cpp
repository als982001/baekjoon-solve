#include <string>
#include <vector>
#include <sstream>

#define MINUTE 60
#define HOUR 3600
#define MAX_TIME 360000

using namespace std;

long long record[MAX_TIME];

long long TimeToNum(string t)
{
    vector<long long> timeInfo;
    
    stringstream ss(t);
    string segment;
    
    while(getline(ss, segment, ':'))
        timeInfo.push_back(stoll(segment));
    
    int num = 0;
    
    num += timeInfo[2];
    num += (timeInfo[1] * MINUTE);
    num += (timeInfo[0] * HOUR);
    
    return num;
}

string NumToTime(long long num)
{
    string result = "";
    
    long long hour = num / HOUR;
    num -= (hour * HOUR);
    
    long long minute = num / MINUTE;
    
    long long second = num - (minute * MINUTE);
    
    if (hour < 10)
        result = "0";
    result += to_string(hour);
    result += ":";
    
    if (minute < 10)
        result += "0";
    result += to_string(minute);
    result += ":";
    
    if (second < 10)
        result += "0";
    result += to_string(second);
    
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";
    
    for (int t = 0; t < MAX_TIME; ++t)
        record[t] = 0;

    long long advTime = TimeToNum(adv_time);
    long long playTime = TimeToNum(play_time);
    
    long long recordsSum = 0;
    long long maxRecordsSum = 0;
    
    for (string log : logs)
    {
        string strLogStartTime = log.substr(0, 8);
        string strLogEndTime = log.substr(9, 8);
        
        long long logStartTime = TimeToNum(strLogStartTime);
        long long logEndTime = TimeToNum(strLogEndTime);
        
        // 누적합 적용
        record[logStartTime]++;
        record[logEndTime]--;
    }
    
    // 누적합 활용해서 record 기록
    for (int t = 1; t <= playTime; ++t)
    {
        record[t] += record[t - 1];
    }
    
    for (int t = 0; t < advTime; ++t)
    {
        recordsSum += record[t];
        maxRecordsSum += record[t];
    }
    
    for (int advStartTime = 1; advStartTime + advTime <= playTime; ++advStartTime)
    {
        recordsSum = recordsSum - record[advStartTime - 1] + record[advStartTime + advTime - 1];
        
        if (maxRecordsSum < recordsSum)
        {
            maxRecordsSum = recordsSum;
            answer = NumToTime(advStartTime);
        }
    }
    
    return answer;
}