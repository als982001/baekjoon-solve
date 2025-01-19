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
using namespace std;

#define MAX 101
int R, C;
int shootTimes;
vector<vector<char>> map;
vector<vector<char>> tmpMap;
vector<int> shoot;
bool check[MAX][MAX];

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

void Print_Map()
{
	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cout << map[r][c];
		}
		cout << endl;
	}
}

bool Compare(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

bool Is_In(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

void Check_Fall(int startR, int startC)
{
	queue<pair<int, int>> q;
	vector<int> fallenList[MAX];

	q.push(make_pair(startR, startC));
	fallenList[startC].push_back(startR);

	check[startR][startC] = true;

	bool fallOff = true;
	int minHeight = -MAX;

	while (!q.empty())
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		if (curR == R)
			fallOff = false;

		if (minHeight < curR)
			minHeight = curR;

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (!Is_In(nxtR, nxtC))
				continue;

			if (check[nxtR][nxtC])
				continue;

			if (tmpMap[nxtR][nxtC] == 'x')
			{
				q.push(make_pair(nxtR, nxtC));
				fallenList[nxtC].push_back(nxtR);
				check[nxtR][nxtC] = true;
			}
		}
	}

	if (fallOff)
	{
		int heightMove = R - minHeight;
		int minMoveVal = MAX;

		for (int c = 1; c <= C; ++c)
		{
			if (fallenList[c].size() > 0)
			{
				sort(fallenList[c].begin(), fallenList[c].end(), Compare);

				int curHeight = fallenList[c][0];
				int moveVal = 0;

				for (int i = 0; i < heightMove; ++i)
				{
					++moveVal;

					if (map[curHeight + moveVal][c] == 'x')
					{
						--moveVal;
						break;
					}
				}
				

				if (minMoveVal > moveVal)
					minMoveVal = moveVal;
			}
		}

		for (int c = 1; c <= C; ++c)
		{
			if (fallenList[c].size() > 0)
			{
				for (int i = 0; i < fallenList[c].size(); ++i)
				{
					int curHeight = fallenList[c][i];

					tmpMap[curHeight][c] = '.';
					tmpMap[curHeight + minMoveVal][c] = 'x';
				}
			}
		}

		
	}
}
void Solve()
{
	int shootSize = shoot.size();

	for (int t = 0; t < shootSize; ++t)
	{
		int curHeight = shoot[t];

		for (int r = 1; r <= R; ++r)
		{
			for (int c = 1; c <= C; ++c)
				check[r][c] = false;
		}

		if (t % 2 == 0)		// 왼쪽 -> 오른쪽 막대기
		{
			for (int c = 1; c <= C; ++c)
			{
				if (map[curHeight][c] == 'x')
				{
					map[curHeight][c] = '.';
					
					tmpMap = map;

					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curHeight + nr[i];
						int nxtC = c + nc[i];

						if (map[nxtR][nxtC] == 'x')
						{
							if (check[nxtR][nxtC] == false)
								Check_Fall(nxtR, nxtC);
						}
					}
				
					map = tmpMap;
                    
					break;
				}
			}
		}
		else					// 오른쪽 -> 왼쪽 막대기
		{
			for (int c = C; c >= 1; --c)
			{
				if (map[curHeight][c] == 'x')
				{
					map[curHeight][c] = '.';

					tmpMap = map;

					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curHeight + nr[i];
						int nxtC = c + nc[i];

						if (map[nxtR][nxtC] == 'x')
						{
							if (check[nxtR][nxtC] == false)
								Check_Fall(nxtR, nxtC);
						}
					}

					map = tmpMap;

					break;
				}
			}
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> R >> C;

	map.resize(R + 10, vector<char>(C + 10, '.'));

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> map[r][c];
		}
	}

	cin >> shootTimes;

	for (int i = 0; i < shootTimes; ++i)
	{
		int h;
		cin >> h;

		shoot.push_back(R + 1 - h);
	}

	Solve();

	Print_Map();


	return 0;
}