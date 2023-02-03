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
#define MAX 101
#define INF 987654321

int R, C;
char maze[MAX][MAX];
int breakCount[MAX][MAX];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Solve()
{
	int result = INF;

	queue<pair<pair<int, int>, int>> q;
	q.push({ { 1, 1 }, 0 });
	breakCount[1][1] = 0;

	while (!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curCount = q.front().second;
		q.pop();

		if (curR == R && curC == C)
		{
			if (result > curCount)
				result = curCount;

			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (IsIn(nxtR, nxtC))
			{
				if (maze[nxtR][nxtC] == '0' && breakCount[nxtR][nxtC] > curCount)
				{
					breakCount[nxtR][nxtC] = curCount;
					q.push({ {nxtR, nxtC}, curCount });
				}
				else if (maze[nxtR][nxtC] == '1' && breakCount[nxtR][nxtC] > curCount + 1)
				{
					breakCount[nxtR][nxtC] = curCount + 1;
					q.push({ {nxtR, nxtC}, curCount + 1 });
				}
			}
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	
	cin >> C >> R;
	
    for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> maze[r][c];
			
			breakCount[r][c] = INF;
		}
	}

	int answer = Solve();

	cout << answer << endl;

	return 0;
}