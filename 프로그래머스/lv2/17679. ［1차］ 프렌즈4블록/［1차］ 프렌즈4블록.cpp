#include <string>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

#define MAX 31

int nxt[3][2] = { { 1, 0 }, { 0, 1 }, { 1, 1 } };

bool Is_In(int r, int c, int R, int C)
{
	return 0 <= r && r < R && 0 <= c && c < C;
}

vector<string> Fall_Blocks(vector<string> board)
{
	for (int r = board.size() - 1; r > -1; --r)
	{
		for (int c = 0; c < board[0].size(); ++c)
		{
			if (board[r][c] == ' ')
			{
				int nxtR = r - 1;

				while (nxtR > -1)
				{
					if (board[nxtR][c] == ' ')
						--nxtR;
					else
						break;
				}

				if (nxtR > -1)
				{
					char fallenChar = board[nxtR][c];
					board[nxtR][c] = ' ';
					board[r][c] = fallenChar;
					
				}
			}
		}
	}

	return board;
}

int solution(int m, int n, vector<string> board)
{
	int answer = 0;

	bool isEnd = false;

	while (true)
	{
		vector<string> nxtBoard = board;
		bool removed = false;

		for (int r = 0; r < m; ++r)
		{
			for (int c = 0; c < n; ++c)
			{
				if (board[r][c] != ' ')
				{
					char curChar = board[r][c];

					bool canRemove = true;

					queue<pair<int, int>> q;

					for (int i = 0; i < 3; ++i)
					{
						int nxtR = r + nxt[i][0];
						int nxtC = c + nxt[i][1];

						if (!Is_In(nxtR, nxtC, m, n))
						{
							canRemove = false;
							continue;
						}

						if (board[nxtR][nxtC] == curChar)
							q.push({ nxtR, nxtC });
						else
							canRemove = false;
					}

					if (canRemove)	// 지워질 블록이 있을 경우 지운다
					{
						removed = true;
						nxtBoard[r][c] = ' ';

						while (!q.empty())
						{
							int curR = q.front().first;
							int curC = q.front().second;
							q.pop();

							nxtBoard[curR][curC] = ' ';
						}
					}
				}
			}
		}

		
		
		if (removed == false)
			break;

		board = Fall_Blocks(nxtBoard);
	}

	for (int r = 0; r < board.size(); ++r)
	{
		for (int c = 0; c < board[0].size(); ++c)
			if (board[r][c] == ' ')
				++answer;
	}

	return answer;
}