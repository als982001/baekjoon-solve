#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define HOUR 60
#define CLEAN_TIME 10

using namespace std;

int GetIntTime(string str)
{    
    stringstream ss(str);
    string segment;
    
    vector<string> times;
    
    while(getline(ss, segment, ':'))
        times.push_back(segment);
    
    return (stoi(times[0]) * HOUR) + stoi(times[1]);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int, int>> bookTimes;
    vector<int> roomAvailableTimes;
    
    for(vector<string> bookTime : book_time)
    {
        int startTime = GetIntTime(bookTime[0]);
        int endTime = GetIntTime(bookTime[1]) + CLEAN_TIME;
        
        bookTimes.push_back({ startTime, endTime });
    }
    
    sort(bookTimes.begin(), bookTimes.end());
    
    for (pair<int, int> bookTime : bookTimes)
    {
        int startTime = bookTime.first;
        int endTime = bookTime.second;
        
        bool isAssigned = false;
        
        if (roomAvailableTimes.empty() == false)
        {
            for (int idx = 0; idx < roomAvailableTimes.size(); ++idx)
            {
                int roomEndTime = roomAvailableTimes[idx];
                
                if (roomEndTime <= startTime)
                {
                    roomAvailableTimes[idx] = endTime;
                    isAssigned = true;
                    break;
                }
            }
        }
        
        if (isAssigned == false)
        {
            ++answer;
            roomAvailableTimes.push_back(endTime);
        }
    }
    
    
    
    return answer;
}