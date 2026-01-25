#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int TimeToInt(string time)
{
    string hour = "";
    hour = hour + time[0] + time[1];
    
    string minute = "";
    minute = minute + time[3] + time[4];
        
    return stoi(hour) * 60 + stoi(minute);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int lastTime = TimeToInt("23:59");
    
    map<string, int> inTime;
    map<string, int> totalTime;
    vector<pair<string, int>> cars;

    
    for (string record : records)
    {
        stringstream ss(record);
        string segment;
        
        vector<string> recordInfo;
        
        while(getline(ss, segment, ' '))
            recordInfo.push_back(segment);
        
        int recordTime = TimeToInt(recordInfo[0]);
        string car = recordInfo[1];
        string recordType = recordInfo[2];
        
        // IN인 경우: 시간 등록
        if (recordType == "IN")
        {
            inTime[car] = recordTime;
            
            // 처음 들어오는 차라면 별도로 저장
            if (totalTime[car] == 0)
                cars.push_back({ car, 0 });
        }
        // OUT인 경우: 시간 누적
        else
        {
            totalTime[car] += (recordTime - inTime[car]);
            inTime[car] = -1;
        }
    }
    
    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    
    for (int i = 0; i < cars.size(); ++i)
    {
        string car = cars[i].first;
        
        if (inTime[car] >= 0)
            totalTime[car] += (lastTime - inTime[car]);
                
        // 누적 주차 시간이 기본 시간 이하라면 기본 요금
        if (totalTime[car] <= basicTime)
            cars[i].second = basicFee;
        // 누적 주차 시간이 기본 시간 초과하면 기본 요금 + 단위 요금
        else
        {
            int totalFee = basicFee;
            
            int restTime = (totalTime[car] - basicTime + (unitTime - 1)) / unitTime;
            totalFee += (restTime * unitFee);
            
            cars[i].second = totalFee;
        }
    }
    
    sort(cars.begin(), cars.end());
    
    for (pair<string, int> carInfo : cars)
        answer.push_back(carInfo.second);
    
    return answer;
}
