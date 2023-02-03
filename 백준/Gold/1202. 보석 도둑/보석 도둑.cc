#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
using namespace std;

#define MAX 300011

long long jewNum, bagNum;
priority_queue<long long> chosen;
vector<pair<long long, long long>> jew;
vector<long long> bag;

bool Compare_Jewel(pair<long long, long long> a, pair<long long, long long> b)
{
	if (a.first < b.first)
		return true;
	else if (a.first > b.first)
		return false;
	else
	{
		if (a.second > b.second)
			return true;
		else
			return false;
	}
}

long long Solve()
{
	long long answer = 0;

	long long jewIdx = 0;
	for (int b = 0; b < bag.size(); ++b)
	{
		long long curBag = bag[b];

		while (jewIdx < jewNum)
		{
			long long curJewWgt = jew[jewIdx].first;
			long long curJewVal = jew[jewIdx].second;

			if (curJewWgt > curBag)
				break;

			chosen.push(curJewVal);
			++jewIdx;
		}

		if (!chosen.empty())
		{
			answer += chosen.top();
			chosen.pop();
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> jewNum >> bagNum;

	long long weight, value;
	for (int i = 0; i < jewNum; ++i)
	{
		cin >> weight >> value;

		jew.push_back(make_pair(weight, value));
	}

	long long bagInput;
	for (int i = 0; i < bagNum; ++i)
	{
		cin >> bagInput;

		bag.push_back(bagInput);
	}
	
	sort(jew.begin(), jew.end(), Compare_Jewel);
	sort(bag.begin(), bag.end());

	long long answer = Solve();

	cout << answer << endl;
	
	return 0;
}