#include <vector>
#include <queue>
using namespace std;

#define MAX 111

int R, C;
int id = 1;
int maxAreaSize = -1;
int areaId[MAX][MAX];
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool IsIn(int r, int c)
{
	return 0 <= r && r < R && 0 <= c && c < C;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
        {
            areaId[r][c] = 0;
        }
    }
    
    id = 0;
    maxAreaSize = -1;
	R = m;
	C = n;

	for (int r = 0; r < picture.size(); ++r)
	{
		for (int c = 0; c < picture[r].size(); ++c)
		{
			if (picture[r][c] > 0 && areaId[r][c] == 0)
			{
				int curColor = picture[r][c];
				int curAreaSize = 0;
				int curId = ++id;
				areaId[r][c] = curId;

				queue<pair<int, int>> q;
				q.push({ r, c });

				while(!q.empty())
				{
					int curR = q.front().first;
					int curC = q.front().second;
					q.pop();

					++curAreaSize;

					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curR + nr[i];
						int nxtC = curC + nc[i];

						if (IsIn(nxtR, nxtC))
						{
							if (picture[nxtR][nxtC] == curColor && areaId[nxtR][nxtC] == 0)
							{
								areaId[nxtR][nxtC] = curId;
								q.push({ nxtR, nxtC });
							}
						}
					}
				}

				if (maxAreaSize < curAreaSize)
					maxAreaSize = curAreaSize;
			}
		}
	}

	return { id, maxAreaSize };
}
