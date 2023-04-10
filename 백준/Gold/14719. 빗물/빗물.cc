#include <iostream>
using namespace std;

int R, C;
int map[500][500];	// 9:벽, 1: 물
int height[500];
int sum;

void 빗물()
{
	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			if (map[r][c] == 0 && map[r][c - 1] == 9)
			{
				int cur_c = c;
				while (c <= C && map[r][c] == 0)
					++c;
				if (c > C)
					break;
				else
				{
					sum += c - cur_c;
				}
				
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int c = 1; c <= C; ++c)
	{
		cin >> height[c];
	}

	for (int c = 1; c <= C; ++c)
	{
		for (int h = 1; h <= height[c]; ++h)
		{
			map[h][c] = 9;
		}
	}

	빗물();

	cout << sum << endl;

	return 0;
}