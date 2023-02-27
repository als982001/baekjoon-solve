#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 511

#define VAL 60

typedef struct 
{
	int hour;
	int minute;
	int second;
} Time;

Time startTime, endTime;
vector<Time> answer;

Time Work(Time start, Time end)
{
	Time workingTime;

	if (end.second >= start.second)
		workingTime.second = end.second - start.second;
	else
	{
		end.minute -= 1;
		end.second += VAL;

		workingTime.second = end.second - start.second;

		if (end.minute < 0)
		{
			end.minute += VAL;
			end.hour -= 1;
		}
	}

	if (end.minute >= start.minute)
		workingTime.minute = end.minute - start.minute;
	else
	{
		end.hour -= 1;
		end.minute += VAL;

		workingTime.minute = end.minute - start.minute;
	}

	workingTime.hour = end.hour - start.hour;

	return workingTime;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	for (int i = 0; i < 3; ++i)
	{
		cin >> startTime.hour >> startTime.minute >> startTime.second >> endTime.hour >> endTime.minute >> endTime.second;

		Time workingTime = Work(startTime, endTime);
		answer.push_back(workingTime);
	}

	for (int i = 0; i < 3; ++i)
		printf("%d %d %d \n", answer[i].hour, answer[i].minute, answer[i].second);

	return 0;
}
