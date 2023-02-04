#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
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
#define MAX 511

int R, C;
int map[MAX][MAX];
int dp[MAX][MAX];
int nr[4] = { 1, -1,  0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Go(int r, int c)
{
	if (r == 1 && c == 1)
		return 1;

	if (dp[r][c] >= 0)
		return dp[r][c];

	int& curDp = dp[r][c];
	curDp = 0;

	for (int dir = 0; dir < 4; ++dir)
	{
		int nxtR = r + nr[dir];
		int nxtC = c + nc[dir];

		if (IsIn(nxtR, nxtC) && (map[r][c] < map[nxtR][nxtC]))
			curDp += Go(nxtR, nxtC);
	}

	return curDp;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> R >> C;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
			cin >> map[r][c];
	}

	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
			dp[r][c] = -1;
	}

	Go(R, C);

	int answer = dp[R][C];

	cout << answer << endl;

	return 0;
}