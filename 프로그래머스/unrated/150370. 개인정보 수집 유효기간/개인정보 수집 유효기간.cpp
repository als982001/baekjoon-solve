#include <string>
#include <vector>
#include <map>

using namespace std;

#define CASE 2
#define MONTH 12
#define DAY 28

typedef struct 
{
	int year;
	int month;
	int day;
} info;

info todayInfo;
map<string, int> termInfos;
vector<info> privacyInfos; 

info Info(string strInfo)
{
	int year = stoi(strInfo.substr(0, 4));
	int month = stoi(strInfo.substr(5, 2));
	int day = stoi(strInfo.substr(8, 2));

	info today;
	today.year = year;
	today.month = month;
	today.day = day;

	return today;
}

info Limit(info startTime, int term)
{
	int year = startTime.year;
	int month = startTime.month;
	int day = startTime.day;

	if (month + term > MONTH)
	{
		year += ((month + term) / MONTH);
		month = (month + term) % MONTH;
        
        if (month == 0)
		{
			month = 12;
			year -= 1;
		}
	}
	else
		month += term;
	
	if (day - 1 <= 0)
	{
		day = DAY;

		if (month - 1 <= 0)
		{
			month = MONTH;
			--year;
		}
		else
			--month;
	}
	else
		--day;

	info limit;
	limit.year = year;
	limit.month = month;
	limit.day = day;

	return limit;
}

bool IsOverdue(info today, info limit)
{
	if (today.year > limit.year)
		return true;
	else if (today.year < limit.year)
		return false;
	else
	{
		if (today.month > limit.month)
			return true;
		else if (today.month < limit.month)	
			return false;
		else
		{
			if (today.day > limit.day)
				return true;
			else
				return false;
		}
	}
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

	todayInfo = Info(today);

	for (int i = 0; i < privacies.size(); ++i)
		privacyInfos.push_back(Info(privacies[i]));
	
	for (int i = 0; i < terms.size(); ++i)
		termInfos[terms[i].substr(0, 1)] =  stoi(terms[i].substr(2));

	for (int i = 0; i < privacies.size(); ++i)
	{
		info privacy = privacyInfos[i];
		int term = termInfos[privacies[i].substr(11)];

		info limit = Limit(privacy, term);

		if (IsOverdue(todayInfo, limit))
			answer.push_back(i + 1);
	}

    return answer;
}