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

#define MAX 111
#define INF 987654321

int R, C, K;
long long dp[MAX][MAX];
bool cannotGo[MAX][MAX][2];

bool Is_In(int r, int c)
{
	return 0 <= r && r <= R && 0 <= c && c <= C;
}

long long Solve(int r, int c)
{
	if (!Is_In(r, c))
		return 0;

	if (r == 0 && c == 0)
		return 1;

	if (dp[r][c] >= 0)
		return dp[r][c];

	dp[r][c] = 0;
	long long& curDp = dp[r][c];

	if (Is_In(r - 1, c)) 
	{
		if (!cannotGo[r][c][0])
			curDp += Solve(r - 1, c);
	}

	if (Is_In(r, c - 1))
	{
		if (!cannotGo[r][c][1])
			curDp += Solve(r, c - 1);
	}

	return curDp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> R >> C;

	cin >> K;

	for (int i = 0; i < K; ++i)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		if (c1 == c2)
		{
			if (r1 < r2)
				cannotGo[r2][c2][0] = true;
			else
				cannotGo[r1][c1][0] = true;
		}
		else if (r1 == r2)
		{
			if (c1 < c2)
				cannotGo[r2][c2][1] = true;
			else
				cannotGo[r1][c1][1] = true;
		}
	}

	for (int r = 0; r <= R; ++r)
	{
		for (int c = 0; c <= C; ++c)
			dp[r][c] = -1;
	}
	
	long long answer = Solve(R, C);

	cout << answer << endl;

	return 0;
}