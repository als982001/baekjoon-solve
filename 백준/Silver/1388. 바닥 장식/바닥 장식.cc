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
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 51

int R, C;
char homeFloor[MAX][MAX];
bool checked[MAX][MAX];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Check()
{
	int count = 0;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (checked[r][c] == false)
			{
				++count;

				char shape = homeFloor[r][c];
				checked[r][c] = true;

				queue<pair<int, int>> q;
				q.push({ r, c });

				while(!q.empty())
				{
					int curR = q.front().first;
					int curC = q.front().second;
					q.pop();

					for (int i = 0; i < 2; ++i)
					{
						int nxtR = curR + (shape == '|' ? nr[i] : nr[i + 2]);
						int nxtC = curC + (shape == '|' ? nc[i] : nc[i + 2]);

						if (IsIn(nxtR, nxtC))
						{
							if (checked[nxtR][nxtC] == false && homeFloor[nxtR][nxtC] == shape)
							{
								checked[nxtR][nxtC] = true;
								q.push({ nxtR, nxtC });
							}
						}
					}
				}
			}
		}
	}

	return count;
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
			cin >> homeFloor[r][c];
		}
	}

	int answer = Check();

	cout << answer << endl;

	return 0;
}
