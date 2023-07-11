#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define HOUR 60
#define MAX 11

int lastBusTime = 0;
vector<vector<int>> buses;
vector<int> crewTimes;

// "09:10"과 같은 string형의 시간을 int형 값으로 바꾼다.
int IntTime(string time)
{
	int hour = stoi(time.substr(0, 2));
	int minute = stoi(time.substr(3));

	return hour * HOUR + minute;
}

// 5410과 같은 int형의 시간을 string형 값으로 바꾼다.
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

	// 6. 위의 상황들에도 해당되지 않는다면,
	// 가장 마지막에 도착한 크루의 시간보다 1분 빠르게 오면 된다.
	int lastCrewTime = buses[n - 1].back();	// 마지막 버스의 마지막 크루의 도착 시간

	return StringTime(lastCrewTime - 1);	// 마지막 사람보다 1분 일찍
}
