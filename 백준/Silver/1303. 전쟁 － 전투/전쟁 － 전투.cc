#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int N, M;					// N: 가로(열), M: 세로(행)
int power[2];				// power[0] : W의 위력, power[1] : B의 위력
bool check[MAX][MAX];		// BFS에서 검사를 했는지의 여부
char soldier[MAX][MAX];		// 병사들 옷 색 저장할 배열
queue<pair<int, int>> q;	// BFS를 위한 큐

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };
	
bool IsIn(int r, int c)
{
	return M >= r && r >= 1 && N >= c && c >= 1;
}

void BFS()
{
	for (int r = 1; r <= M; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			if (!check[r][c])
			{
				char cur_color = soldier[r][c];
				int soldier_nums = 1;
				q.push(make_pair(r, c));
				check[r][c] = true;

				while (!q.empty())
				{
					int cur_r = q.front().first;
					int cur_c = q.front().second;
					q.pop();

					for (int i = 0; i < 4; ++i)
					{
						int nxt_r = cur_r + nr[i];
						int nxt_c = cur_c + nc[i];

						if (IsIn(nxt_r, nxt_c))
						{
							if (soldier[nxt_r][nxt_c] == cur_color && !check[nxt_r][nxt_c])
							{
								q.push(make_pair(nxt_r, nxt_c));
								check[nxt_r][nxt_c] = true;
								++soldier_nums;
							}
						}
					}
				}

				if (cur_color == 'W')
					power[0] += soldier_nums * soldier_nums;
				else
					power[1] += soldier_nums * soldier_nums;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	for (int r = 1; r <= M; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			cin >> soldier[r][c];
		}
	}

	BFS();

	printf("%d %d \n", power[0], power[1]);

	return 0;
}