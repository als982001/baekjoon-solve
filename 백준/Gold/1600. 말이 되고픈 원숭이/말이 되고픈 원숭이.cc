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
#define MAX 201

int R, C, K;
int map[MAX][MAX];
bool visited[MAX][MAX][31];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };
int knightR[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int knightC[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Move()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1, 1 }, { K, 0 } });
	visited[1][1][K] = true;

	while (!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curJump = q.front().second.first;
		int curTime = q.front().second.second;
		q.pop();

		if (curR == R && curC == C)
			return curTime;

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (IsIn(nxtR, nxtC) == false)
				continue;

			if (visited[nxtR][nxtC][curJump] == false && map[nxtR][nxtC] == 0)
			{
				visited[nxtR][nxtC][curJump] = true;
				q.push({ { nxtR, nxtC }, { curJump, curTime + 1 } });
			}
		}

		if (curJump > 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				int nxtR = curR + knightR[i];
				int nxtC = curC + knightC[i];

				if (IsIn(nxtR, nxtC) == false)
					continue;

				if (visited[nxtR][nxtC][curJump - 1] == false && map[nxtR][nxtC] == 0)
				{
					visited[nxtR][nxtC][curJump - 1] = true;
					q.push({ { nxtR, nxtC }, { curJump - 1, curTime + 1 } });
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	cin >> C >> R;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
			cin >> map[r][c];
	}

	int answer = Move();

	cout << answer << endl;
	
	return 0;
}