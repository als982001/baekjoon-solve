#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 2002

int R, C;
char maze[MAX][MAX];
vector<pair<int, int>> holes;
pair<int, int> befPos[MAX][MAX];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsEdge(int r, int c)
{
	return r == 1 || r == R || c == 1 || c == C;
}

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

void MarkMaze()
{
	int r = holes[1].first, c = holes[1].second;

	while(r != holes[0].first || c != holes[0].second)
	{
		maze[r][c] = '.';

		int nxtR = befPos[r][c].first;
		int nxtC = befPos[r][c].second;

		r = nxtR;
		c = nxtC;
	}

	maze[holes[0].first][holes[0].second] = '.';
}

void TheShortestPath()
{
	int startR = holes[0].first, startC = holes[0].second;
	int endR = holes[1].first, endC = holes[1].second;

	queue<pair<int, int>> q;
	q.push({ startR, startC });
	befPos[startR][startC] = holes[0];

	while(!q.empty())
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (curR == endR && curC == endC)
		{
			MarkMaze();
			return;
		}
		
		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (IsIn(nxtR, nxtC))
			{
				if (maze[nxtR][nxtC] == '@' && befPos[nxtR][nxtC].first == 0)
				{
					befPos[nxtR][nxtC] = { curR, curC };
					q.push({ nxtR, nxtC });
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> R >> C;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> maze[r][c];

			if (maze[r][c] == '.')
			{
				maze[r][c] = '@';

				if (IsEdge(r, c))
					holes.push_back({ r, c });
			}
		}
	}

	TheShortestPath();

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
			cout << maze[r][c];
				
		cout << endl;
	}

	return 0;
}
