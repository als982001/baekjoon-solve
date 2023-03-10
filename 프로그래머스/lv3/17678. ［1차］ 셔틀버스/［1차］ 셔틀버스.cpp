#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define CASE 6

#define HOUR 60
#define MAX 10

int lastBusTime = 0;
vector<vector<int>> buses;
vector<int> crewTimes;

int IntTime(string time)
{
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3));

	return hour * HOUR + minute;
}

string StringTime(int time)
{
	string strHour = "0";
	string strMinute = "0";

	int hour = time / HOUR;
	int minute = time % HOUR;

	if (hour < 10)
		strHour += to_string(hour);
	else
		strHour = to_string(hour);

	if (minute < 10)
		strMinute += to_string(minute);
	else
		strMinute = to_string(minute);

	return strHour + ":" + strMinute;
}


string solution(int n, int t, int m, vector<string> timetable)
{
	lastBusTime = 0;
	buses.clear();
	crewTimes.clear();

	// 1. 주어진 timetable의 값들을 전부 int형 값으로 바꾼다.
	for (int i = 0; i < timetable.size(); ++i)
		crewTimes.push_back(IntTime(timetable[i]));

	// 2. 크루들의 도착 시간을 빨리 온 순으로 정렬한다.
	sort(crewTimes.begin(), crewTimes.end());

	int crewIdx = 0;

	// 3. 모든 버스에 크루들을 우선적으로 탑승시킨다.
	for (int busIdx = 0, busTime = IntTime("09:00"); busIdx < n; ++busIdx, busTime += t)
	{
		vector<int> bus;

		// 3-1. 만약 모든 크루들이 탑승한 상태라면, 반복문을 그만한다.
		if (crewIdx >= crewTimes.size())
			break;
		
		// 3-2. 버스에 자리가 남았으면서, 아직 크루들이 버스 도착 시간 전에 왔다면 태운다.
		while(bus.size() < m && crewTimes[crewIdx] <= busTime)
		{
			bus.push_back(crewTimes[crewIdx]);
			++crewIdx;

			// 만약 크루들이 전부 탐승했으면 그만 한다.
			if (crewIdx >= crewTimes.size())
				break;
		}

		buses.push_back(bus);
		lastBusTime = busTime;
	}

	// 4. 만약에 한 명도 탑승하지 않은 버스가 있다면, 이는 마지막 버스일 것이므로
	// 마지막 버스의 도착 시간을 return한다.
	if (buses.size() < n)
		return StringTime(lastBusTime);

	// 5. 만약 마지막 버스에 자리가 남는다면, 마지막 버스 도착 시간에 와도 된다는 뜻이므로
	// 마지막 버스의 도착 시간을 return 한다.
	if (buses[n - 1].size() < m)
		return StringTime(lastBusTime);

	int lastCrewTime = buses[n - 1].back();
    
   	return StringTime(lastCrewTime - 1);

	for (int i = buses[n - 1].size() - 1; i >= 0; --i)
	{
		if (buses[n - 1][i] < lastCrewTime)	
			return StringTime(buses[n - 1][i]);
	}

	return StringTime(lastCrewTime - 1);
}

/*
#define CASE 6

#define MAX 12
#define HOUR 60

string NumToStr(int time)
{
    int hour = time / HOUR;
    int minute = time % HOUR;

    string strHour = to_string(hour);
    if (hour < 10)
        strHour = "0" + strHour;
    
    string strMinute = to_string(minute);
    if (minute < 10)
        strMinute = "0" + strMinute;

    return (strHour + ":" + strMinute);
}

int StrToNum(string time)
{
    string strHour = time.substr(0, 2);
    string strMinute = time.substr(3, 2);

    int hour = stoi(strHour);
    int minute = stoi(strMinute);

    return hour * HOUR + minute;
}

// n: 셔틀 운행 횟수, t: 셔틀 운행 간격, m: 셔틀에 탈 수 있는 최대 크루 수
string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";

    vector<vector<int>> buses;
    vector<int> crewTimetable;
    int startTime = StrToNum("09:00");
    int crewIdx = 0;

    for (int t = 0; t < timetable.size(); ++t)
    {
        string strCurCrew = timetable[t];
        int curCrew = StrToNum(strCurCrew);

        crewTimetable.push_back(curCrew);
    }

    sort(crewTimetable.begin(), crewTimetable.end());

    for (int busIdx = 0; busIdx < n; ++busIdx)
    {
        vector<int> bus;
        int busStartTime = startTime + (t * busIdx);

        while (true)
        {
            int curCrew = crewTimetable[crewIdx];
            if (curCrew <= busStartTime)
            {
                bus.push_back(curCrew);
                ++crewIdx;
            }
            else
                break;

            if (bus.size() >= m)
                break;
        }

        buses.push_back(bus);
    }

    vector<int> lastBus = buses.back();
    int lastBusTime = startTime + (t * (n - 1));

    if (lastBus.size() < m)
        answer = NumToStr(lastBusTime);
    else
    {
        int lastCrew = lastBus.back();
        int answerTime = lastCrew - 1;

        answer = NumToStr(answerTime);
    }
    
    return answer;
}
*/
/*
string solution(int n, int t, int m, vector<string> timetable) 
{
    vector<int> Crew;
    for (int i = 0; i < timetable.size(); i++)
    {
        string S_Hour = "";
        S_Hour = S_Hour + timetable[i][0];
        S_Hour = S_Hour + timetable[i][1];
        int Hour = stoi(S_Hour);
        
        string S_Minute = "";
        S_Minute = S_Minute + timetable[i][3];
        S_Minute = S_Minute + timetable[i][4];
        int Minute = stoi(S_Minute);
        
        int Time = Hour * 60 + Minute;
        Crew.push_back(Time);
    }
    sort(Crew.begin(), Crew.end());
 
    int Shuttle_Time = 540;
    int Crew_Idx = 0;
    int Answer_Time;
    for (int i = 1; i <= n; i++, Shuttle_Time = Shuttle_Time + t)
    {
        int Cnt = 0;
        for (int j = Crew_Idx; j < Crew.size(); j++)
        {
            if (Crew[j] <= Shuttle_Time)
            {
                Crew_Idx++;
                Cnt++;
                if (Cnt == m) break;
            }
        }
 
        if (i == n)
        {
            if (Cnt == m) Answer_Time = Crew[Crew_Idx - 1] - 1;
            else Answer_Time = Shuttle_Time;
        }
    }
    
    string answer = "";
    int Hour = Answer_Time / 60;
    int Minute = Answer_Time % 60;
    char A = Hour / 10 + '0';
    char B = Hour % 10 + '0';
    char C = Minute / 10 + '0';
    char D = Minute % 10 + '0';
    answer = answer + A;
    answer = answer + B;
    answer = answer + ':';
    answer = answer + C;
    answer = answer + D;
    return answer;
}

int Time_to_Int(string time)
{
	string strHour = time.substr(0, 2);
	string strMinute = time.substr(3, 2);

	return stoi(strHour) * 60 + stoi(strMinute);
}

string Time_to_Str(int time)
{
	int hour = time / 60;
	int minute = time % 60;

	string strHour = hour < 10 ? "0" + to_string(hour) : to_string(hour);
	string strMinute = minute < 10 ? "0" + to_string(minute) : to_string(minute);

	return strHour + ":" + strMinute;
}

string solution(int n, int t, int m, vector<string> timetable)
{
	int answer = 0;

	vector<int> tmtable;

	for (auto time : timetable)
		tmtable.push_back(Time_to_Int(time));

	sort(tmtable.begin(), tmtable.end());

	vector<vector<int>> buses;

	int busTime = 540;
	int lastBusTime = 0;
	int passenger = 0;

	for (int busCome = 0; busCome < n; ++busCome)
	{
		vector<int> bus;

		while (bus.size() < m && passenger < tmtable.size())
		{
			if (tmtable[passenger] > busTime)
				break;

			bus.push_back(tmtable[passenger]);
			++passenger;
		}

		buses.push_back(bus);
		lastBusTime = busTime;
		busTime += t;
	}

	vector<int> lastBus = buses.back();

	if (lastBus.size() < m)
		answer = lastBusTime;
	else

		answer = lastBus.back() - 1;

	return Time_to_Str(answer);
}
*/