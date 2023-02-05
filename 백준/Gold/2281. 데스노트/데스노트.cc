#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 1001
using namespace std;

int n, m, answer;
int names[MAX];
int dp[MAX][MAX];

int Solve(int cur, int cur_len)
{
   	if (cur > n)
		return 0;
    
	if (dp[cur][cur_len] > -1)
		return dp[cur][cur_len];

	int& cur_dp = dp[cur][cur_len];

	cur_dp = pow(m - cur_len + 1, 2) + Solve(cur + 1, names[cur] + 1);

	if (cur_len + names[cur] <= m)
		cur_dp = min(cur_dp, Solve(cur + 1, cur_len + names[cur] + 1));

	return cur_dp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> names[i];
		
	}

	memset(dp, -1, sizeof(dp));
	answer = Solve(1, 0);

	cout << answer << endl;

	return 0;
}