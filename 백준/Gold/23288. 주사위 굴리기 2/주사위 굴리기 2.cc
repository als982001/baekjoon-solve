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
#include <typeinfo>

using namespace std;

#define SIZE 21

typedef struct DICE 
{
	int top;
	int bottom;
	int left;
	int right;
	int front;
	int back;

	DICE(int _top, int _bottom, int _left, int _right, int _front, int _back)
		: top(_top), bottom(_bottom), left(_left), right(_right), front(_front), back(_back) {}
	void Go(int dir);
} Dice;

int R, C, K;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];
int nr[4] = { 0, 0, 1, -1 };
int nc[4] = { 1, -1, 0, 0 };

void DICE::Go(int dir)
{
	// 0 = 동쪽
	// 1 = 서쪽
	// 2 = 남쪽
	// 3 = 북쪽
	switch (dir)
	{
	case 0:
	{
		int temp = this->right;
		this->right = this->top;
		this->top = this->left;
		this->left = this->bottom;
		this->bottom = temp;

		break;
	}
	case 1:
	{
		int temp = this->left;
		this->left = this->top;
		this->top = this->right;
		this->right = this->bottom;
		this->bottom = temp;

		break;
	}
	case 2:
	{
		int temp = this->front;
		this->front = this->bottom;
		this->bottom = this->back;
		this->back = this->top;
		this->top = temp;

		break;
	}
	case 3:
	{
		int temp = this->back;
		this->back = this->bottom;
		this->bottom = this->front;
		this->front = this->top;
		this->top = temp;

		break;
	}
	}
}

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int GetScore(int r, int c)
{
	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
			visited[r][c] = false;
	}

	int num = board[r][c];
	int cnt = 0;

	int curR = r;
	int curC = c;

	queue<pair<int, int>> q;
	q.push({ r, c });

	visited[curR][curC] = true;

	while (!q.empty())
	{
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		++cnt;


		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (!IsIn(nxtR, nxtC))
				continue;

			if (board[nxtR][nxtC] != num)
				continue;

			if (visited[nxtR][nxtC])
				continue;

			visited[nxtR][nxtC] = true;
			q.push({ nxtR, nxtC });
		}
	}
	return num * cnt;
}

int Solve()
{
	int score = 0;

	// 0 = 동쪽
	// 1 = 서쪽
	// 2 = 남쪽
	// 3 = 북쪽
	int dir = 0;
	int r = 1, c = 1;
	Dice dice(1, 6, 4, 3, 2, 5);

	for (int t = 0; t < K; ++t)
	{
		int nxtR = r + nr[dir];
		int nxtC = c + nc[dir];
		
		if (!IsIn(nxtR, nxtC))
		{
			switch (dir)
			{
			case 0:
				dir = 1;
				nxtR = r + nr[dir];
				nxtC = c + nc[dir];
				break;
			case 1:
				dir = 0;
				nxtR = r + nr[dir];
				nxtC = c + nc[dir];
				break;
			case 2:
				dir = 3;
				nxtR = r + nr[dir];
				nxtC = c + nc[dir];
				break;
			case 3:
				dir = 2;
				nxtR = r + nr[dir];
				nxtC = c + nc[dir];
				break;
			}
        }
        
		score += GetScore(nxtR, nxtC);	
		dice.Go(dir);

		int bottom = dice.bottom;
		int boardNum = board[nxtR][nxtC];

		if (bottom > boardNum)
		{
			switch (dir)
			{
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
		}
		else if (bottom < boardNum)
		{
			switch (dir)
			{
			case 0:
				dir = 3;
				break;
			case 1:
				dir = 2;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 1;
				break;
			}
		}
		else
		{
			
		}

		r = nxtR;
		c = nxtC;
	}

	return score;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> R >> C >> K;

	for (int r = 1; r <= R; ++r)
	{
		for (int c = 1; c <= C; ++c)
			cin >> board[r][c];
	}
	
	int answer = Solve();

	cout << answer << endl;

	return 0;
}
