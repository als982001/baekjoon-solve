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

#define MAX 100011
#define MOD 9901

int N;
int dp[MAX][3];

int Solve()
{
	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;

	for (int r = 2; r <= N; ++r)
	{
		dp[r][0] = (dp[r - 1][0] + dp[r - 1][1] + dp[r - 1][2]) % MOD;
		dp[r][1] = (dp[r - 1][0] + dp[r - 1][2]) % MOD;
		dp[r][2] = (dp[r - 1][0] + dp[r - 1][1]) % MOD;
	}

	return (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N;

	int answer= Solve();

	cout << answer << endl;

	return 0;
}