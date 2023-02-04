#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#define MAX 101
#define INF 2000000
using namespace std;

int id, N, cityFrom, cityTo;
int cost[MAX];
int cityID[MAX];
bool finished[MAX];
vector<int> cityLnk[MAX];
vector<vector<int>> SCC;
stack<int> stk;

int Solve(int curCity)
{

	cityID[curCity] = ++id;

	stk.push(curCity);

	int parentCity = cityID[curCity];
	int cityLnkSize = cityLnk[curCity].size();

	for (int idx = 0; idx < cityLnkSize; ++idx)
	{	
		int nxtCity = cityLnk[curCity][idx];

		if (cityID[nxtCity] == 0)
			parentCity = min(parentCity, Solve(nxtCity));
		else if (!finished[nxtCity])
			parentCity = min(parentCity, cityID[nxtCity]);
	}

	if (parentCity == cityID[curCity])
	{
		vector<int> tempSCC;

		while (1)
		{
			int city = stk.top();
			stk.pop();
			tempSCC.push_back(city);
			finished[city] = true;	
			if (city == curCity)
				break;
		}

		SCC.push_back(tempSCC);
	}

	return parentCity;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	
	for (int idx = 1; idx <= N; ++idx)
		cin >> cost[idx];

	for (int fromIdx = 1; fromIdx <= N; ++fromIdx)
	{
		string cityToCity;
		cin >> cityToCity;

		for (int toIdx = 0; toIdx < cityToCity.size(); ++toIdx)
		{
			if (cityToCity[toIdx] == '1')
				cityLnk[fromIdx].push_back(toIdx + 1);
		}
	}
	
	for (int idx = 1; idx <= N; ++idx)
	{
		if (cityID[idx] == 0)
			Solve(idx);
	}

	int answer = 0;

	for (int sccIdx = 0; sccIdx < SCC.size(); ++sccIdx)
	{
		int minVal = INF;
		for (int k = 0; k < SCC[sccIdx].size(); ++k)
		{
			int checkSub = SCC[sccIdx][k];
			if (minVal > cost[checkSub])
				minVal = cost[checkSub];
		}
		answer += minVal;
	}

	cout << answer << endl;
	
	return 0;
}