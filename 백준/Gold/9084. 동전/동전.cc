#include <iostream>
#include <cstring>
#define MAX 21
#define INF 10001
using namespace std;

int T, N, M, val;
int coin[MAX];
int dp[MAX][INF];
int answer[10];

int Solve(int curCoin, int curCost)
{
	if(curCoin > N || curCost < 0)
		return 0;

	if (curCost == 0)
		return 1;

	if (dp[curCoin][curCost] > -1)
		return dp[curCoin][curCost];

	if (curCost >= coin[curCoin])
		return dp[curCoin][curCost] = Solve(curCoin, curCost - coin[curCoin]) + Solve(curCoin + 1, curCost);

	else
		return dp[curCoin][curCost] = Solve(curCoin + 1, curCost);

	return dp[curCoin][curCost];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;

		for (int idx = N; idx >= 1; --idx)
			cin >> coin[idx];

		cin >> M;

		memset(dp, -1, sizeof(dp));

		answer[i] = Solve(1, M);
	}

	for (int i = 0; i < T; ++i)
		cout << answer[i] << endl;

	return 0;
}