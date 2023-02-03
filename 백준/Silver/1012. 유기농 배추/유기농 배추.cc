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

int T, R, C, K;
bool cabbage[MAX][MAX];
bool visited[MAX][MAX];
vector<int> answers;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

void Init()
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			cabbage[r][c] = false;
			visited[r][c] = false;
		}
	}
}

bool IsIn(int r, int c)
{
	return 0 <= r && r < R && 0 <= c && c < C;
}

int Check()
{
	int count = 0;

	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			if (cabbage[r][c] && !visited[r][c])
			{
				++count;

				queue<pair<int, int>> q;
				q.push({ r, c });
				visited[r][c] = true;

				while (!q.empty())
				{
					int curR = q.front().first;
					int curC = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curR + nr[i];
						int nxtC = curC + nc[i];

						if (IsIn(nxtR, nxtC))
						{
							if (!visited[nxtR][nxtC] && cabbage[nxtR][nxtC])
							{
								visited[nxtR][nxtC] = true;
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
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		Init();

		cin >> C >> R >> K;

		int cabbageR, cabbageC;

		for (int k = 0; k < K; ++k)
		{
			cin >> cabbageC >> cabbageR;
			cabbage[cabbageR][cabbageC] = true;
		}

		int answer = Check();
		answers.push_back(answer);
	}

	for (int a = 0; a < answers.size(); ++a)
		cout << answers[a] << endl;

	return 0;
}