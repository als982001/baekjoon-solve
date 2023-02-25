#include <iostream>
#include <string>
#include <sstream>
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
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 51
#define ITEM 5

int R, C;
int startR, startC;
int itemIdx = 0, allItems = 0;
char home[MAX][MAX];
bool visited[MAX][MAX][(1 << (ITEM + 1))];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Go()
{
	int answer = 0;

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { startR, startC }, { 0, 0 } });
	visited[startR][startC][0] = true;

	while(!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curItems = q.front().second.first;
		int curTime = q.front().second.second;
		q.pop();

		if (home[curR][curC] == 'E' && curItems == allItems)
		{
			answer = curTime;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (IsIn(nxtR, nxtC))
			{
				if (home[nxtR][nxtC] != '#' && visited[nxtR][nxtC][curItems] == false)
				{
					visited[nxtR][nxtC][curItems] = true;

					if ('0' <= home[nxtR][nxtC] && home[nxtR][nxtC] <= '9')
					{
						int nxtItem = home[nxtR][nxtC] - '0';
						int nxtItems = (curItems | (1 << nxtItem));

						q.push({ { nxtR, nxtC }, { nxtItems, curTime + 1} });
					}
					else
						q.push({ { nxtR, nxtC }, { curItems, curTime + 1 } });
				}
			}
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> C >> R;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> home[r][c];

			if (home[r][c] == 'X')
			{
				home[r][c] = (itemIdx + '0');
				++itemIdx;
			}
			else if (home[r][c] == 'S')
			{
				startR = r;
				startC = c;
			}
		}	
	}

	for (int i = 0; i < itemIdx; ++i)
		allItems = (allItems | (1 << i));

	int answer = Go();

	cout << answer << endl;
	
	return 0;
}

