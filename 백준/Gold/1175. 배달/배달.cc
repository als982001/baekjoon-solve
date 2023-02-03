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

typedef struct
{
	int r;
	int c;
	int dir;
	int left;
	int time;
}minsik;

int R, C;
int startR, startC;
int targetR[2], targetC[2];
char classroom[MAX][MAX];
bool visited[MAX][MAX][4][4];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int TargetIndex(int r, int c)
{
	if (targetR[0] == r && targetC[0] == c)
		return 1;
	else if (targetR[1] == r && targetC[1] == c)
		return 2;
	else
		return -1;
}

int Solve()
{
	queue<minsik> q;
	int startLeft = (1 | 2);

	for (int dir = 0; dir < 4; ++dir)
	{
		minsik start;
		start.r = startR;
		start.c = startC;
		start.dir = dir;
		start.left = startLeft;
		start.time = 0;

		q.push(start);
	}

	while (!q.empty())
	{
		minsik cur = q.front();
		q.pop();

		if (cur.left == 0)
			return cur.time;

		for (int dir = 0; dir < 4; ++dir)
		{
			if (dir == cur.dir)
				continue;

			int nxtR = cur.r + nr[dir];
			int nxtC = cur.c + nc[dir];

			if (IsIn(nxtR, nxtC))
			{
				if (classroom[nxtR][nxtC] != '#' && visited[nxtR][nxtC][dir][cur.left] == false)
				{
					if (classroom[nxtR][nxtC] == 'C')
					{
						int target = TargetIndex(nxtR, nxtC);

						if (target == -1)
							continue;

						minsik nxt;
						nxt.r = nxtR;
						nxt.c = nxtC;
						nxt.dir = dir;
						nxt.left = (cur.left ^ target);
						nxt.time = cur.time + 1;

						visited[nxtR][nxtC][dir][nxt.left] = true;
						q.push(nxt);
					}
					else
					{
						minsik nxt;
						nxt.r = nxtR;
						nxt.c = nxtC;
						nxt.dir = dir;
						nxt.left = cur.left;
						nxt.time = cur.time + 1;

						visited[nxtR][nxtC][dir][nxt.left] = true;
						q.push(nxt);
					}
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

	cin >> R >> C;

	int targetIdx = 0;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> classroom[r][c];

			if (classroom[r][c] == 'S')
			{
				startR = r;
				startC = c;
			}
			else if (classroom[r][c] == 'C')
			{
				targetR[targetIdx] = r;
				targetC[targetIdx] = c;
				++targetIdx;
			}
		}
	}

	int answer = Solve();
	
	cout << answer << endl;
	

	return 0;
}