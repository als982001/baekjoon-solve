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
#define MAX 51

int R, C;
int maxTime;
char board[MAX][MAX];
int visited[MAX][MAX];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Check()
{
	int count = 0;

	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visited[1][1] = 1;

	while (!q.empty())
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (visited[curR][curC] > maxTime)
			return -1;

		if (count < visited[curR][curC])
			count = visited[curR][curC];

		int range = board[curR][curC] - '0';

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + (nr[i] * range);
			int nxtC = curC + (nc[i] * range);

			if (IsIn(nxtR, nxtC))
			{
				if (board[nxtR][nxtC] != 'H' && visited[nxtR][nxtC] < visited[curR][curC] + 1)
				{
					visited[nxtR][nxtC] = visited[curR][curC] + 1;
					q.push({ nxtR, nxtC });
				}
			}
		}
	}

	return count;
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
			cin >> board[r][c];
	}

	maxTime = R * C;
	int answer = Check();

	cout << answer << endl;

	return 0;
}