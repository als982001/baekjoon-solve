#include <iostream>
#define MAX 51
using namespace std;

int R, C;
char map[MAX][MAX];

int Check(int cri_r, int cri_c, char even)
{
	int change = 0;
	char odd = even == 'W' ? 'B' : 'W';

	for (int r = cri_r; r <= cri_r + 7; ++r)
	{
		for (int c = cri_c; c <= cri_c + 7; ++c)
		{
			if ((r + c) % 2 == 0)
			{
				if (map[r][c] != even)
				{
					++change;
				}
			}
			else
			{
				if (map[r][c] != odd)
				{
					++change;
				}
			}
		}
	}
	
	return change;
}

int Before_Check(char even)
{
	int change = MAX * MAX;
	
	for (int cri_r = 1; cri_r <= R - 7; ++cri_r)
	{
		for (int cri_c = 1; cri_c <= C - 7; ++cri_c)
		{
			int result = Check(cri_r, cri_c, even);

			if (change > result)
				change = result;
		}
	}

	return change;
}

int main()
{
	cin >> R >> C;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
		{
			cin >> map[r][c];
		}
	}

	int res1 = Before_Check('W');
	int res2 = Before_Check('B');

	cout << (res1 < res2 ? res1 : res2) << endl;

	return 0;
}