#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, w, v;

int weights[101];
int values[101];
int dp[101][111111];

void Solve()
{
	for (int things_idx = 1; things_idx <= N; ++things_idx)
	{
		for (int bag_capacity = 1; bag_capacity <= K; ++bag_capacity)
		{
			if (bag_capacity >= weights[things_idx])
				dp[things_idx][bag_capacity] 
				= max(dp[things_idx - 1][bag_capacity], dp[things_idx - 1][bag_capacity - weights[things_idx]] + values[things_idx]);
			else
				dp[things_idx][bag_capacity] = dp[things_idx - 1][bag_capacity];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> weights[i] >> values[i];
	}
	
	Solve();

	cout << dp[N][K] << endl;

	return 0;
}