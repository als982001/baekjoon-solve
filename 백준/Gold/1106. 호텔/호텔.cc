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
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3
#define CITY 21
#define COST 100001

int wantedGuestNum, cityNum;
int costs[CITY];
int guests[CITY];
int dp[COST];

int Bigger(int a, int b)
{
	return a > b ? a : b;
}

int Solve()
{
	for (int cost = 0; cost <= COST; ++cost)
	{
		for (int city = 1; city <= cityNum; ++city)
		{
			int cityCost = costs[city];
			int cityGuest = guests[city];

			if (cost % cityCost == 0)
				dp[cost] = Bigger(dp[cost], (cost / cityCost) * cityGuest);

			if (cost - cityCost >= 0)
				dp[cost] = Bigger(dp[cost], dp[cost - cityCost] + cityGuest);
		}

		if (dp[cost] >= wantedGuestNum)
			return cost;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> wantedGuestNum >> cityNum;

	for (int cityIdx = 1; cityIdx <= cityNum; ++cityIdx)
		cin >> costs[cityIdx] >> guests[cityIdx];

	int answer = Solve();

	cout << answer << endl;

	return 0;
}