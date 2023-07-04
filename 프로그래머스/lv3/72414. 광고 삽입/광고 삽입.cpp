#include <string>
#include <vector>

using namespace std;

long long StringToNum(string time)
{
    string strHour = time.substr(0, 2);
    string strMinute = time.substr(3, 2);
    string strSecond = time.substr(6);
    
    long long hour = stoll(strHour);
    long long minute = stoll(strMinute);
    long long second = stoll(strSecond);
    
    return hour * 3600 + minute * 60 + second;
}

string NumToString(long long time)
{
    string result = "";
    
    long long hour = time / 3600;
    time %= 3600;
    
    long long minute = time / 60;
    time %= 60;
    
    long long second = time;
    
    if (hour < 10)
        result = "0" + to_string(hour);
    else
        result += to_string(hour);
    result += ":";
    
    if (minute < 10)
        result += ("0" + to_string(minute));
    else
        result += to_string(minute);
    result += ":";
    
    if (second < 10)
        result += ("0" + to_string(second));
    else
        result += to_string(second);
    
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    long long advStartTime = 1;
    
    long long playTime = StringToNum(play_time);
    long long advTime = StringToNum(adv_time);
    
    vector<int> playCheck(361000, 0);
    
    for (int i = 0; i < logs.size(); ++i)
    {
        string log = logs[i];
        
        long long startTime = StringToNum(log.substr(0, 8));
        long long endTime = StringToNum(log.substr(9));
        
        for (int t = startTime + 1; t <= endTime; ++t)
            ++playCheck[t];
    }
    
    long long curPlayCount = 0;
    long long maxPlayCount = 0;
    
    for (int t = 1; t <= advTime; ++t)
    {
        curPlayCount += playCheck[t];
        maxPlayCount += playCheck[t];
    }
    
    for (int t = 2; t <= playTime - advTime + 1; ++t)
    {
        curPlayCount -= playCheck[t - 1];
        curPlayCount += playCheck[t + advTime - 1];

        if (maxPlayCount < curPlayCount)
        {
            maxPlayCount = curPlayCount;
            advStartTime = t;
        }
    }
    
    return NumToString(advStartTime - 1);
}