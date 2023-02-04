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


#define MAX 111

int len;
int minR = MAX, maxR = -1;
int minC = MAX, maxC = -1;
string moving;
char maze[MAX][MAX];
int nr[5] = { 0, 0, 1, 0, -1 };
int nc[5] = { 0, -1, 0, 1, 0 };

// 1 = 서쪽, 2 = 남쪽, 3 = 동쪽, 4 = 북쪽
void Left(int& dir)
{
	if (dir == 4)
		dir = 1;
	else
		++dir;
}

// 1 = 서쪽, 2 = 남쪽, 3 = 동쪽, 4 = 북쪽
void Right(int& dir)
{
	if (dir == 1)
		dir = 4;
	else
		--dir;
}

void Front(int& r, int& c, int dir)
{
	r += nr[dir];
	c += nc[dir];
	maze[r][c] = '.';
}

void CheckRow(int r)
{
	if (minR > r)
		minR = r;

	if (maxR < r)
		maxR = r;
}

void CheckCol(int c)
{
	if (minC > c)
		minC = c;

	if (maxC < c)
		maxC = c;
}

// 1 = 서쪽, 2 = 남쪽, 3 = 동쪽, 4 = 북쪽
void Solve()
{
	int r = 50, c = 50;
	int dir = 2;

	CheckRow(r);
	CheckCol(c);
	maze[r][c] = '.';

	for (int i = 0; i < len; ++i)
	{
		char curMoving = moving[i];

		switch (curMoving)
		{
		case 'L':
			Left(dir);
			break;
		case 'R':
			Right(dir);
			break;
		case 'F':
		{
			Front(r, c, dir);
			CheckRow(r);
			CheckCol(c);

			break;
		}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	
	cin >> len;
	cin >> moving;

	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
			maze[r][c] = '#';
	}

	Solve();

	for (int r = minR; r <= maxR; ++r)
	{
		for (int c = minC; c <= maxC; ++c)
			cout << maze[r][c];
		cout << endl;
	}
	
	return 0;
}