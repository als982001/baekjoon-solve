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

#define MAX 41

int N, M;
vector<int> vip;
int dp[MAX];

int Solve()
{
	int answer = 1;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	int start = 0;
	int vipSize = vip.size();

	for (int i = 0; i < vipSize; ++i)
	{
		int curVip = vip[i];

		answer *= dp[curVip - start - 1];
		
		start = curVip;
	}

	answer *= dp[N - start];

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int vipSeat;
		cin >> vipSeat;

		vip.push_back(vipSeat);
	}

	int answer = Solve();

	cout << answer << endl;

	return 0;
}