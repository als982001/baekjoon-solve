#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321
#define MAX 26
#define STRAIGHT 100
#define CORNER 500

int N;
int minCost[MAX][MAX][4];
int nr[4] = { 1, 0, -1, 0 };
int nc[4] = { 0, -1, 0, 1 };

bool IsIn(int r, int c)
{
	return 0 <= r && r < N && 0 <= c && c < N;
}

bool TurnBack(int dir1, int dir2)
{
	// 0이랑 2는 서로 위아래 방향이라 뒤를 도는 방향
	// 1이랑 3은 서로 좌우 방향이라 뒤를 도는 방향
	// 즉, dir1과 dir2의 차이가 2라면 뒤를 돈다고 볼 수 있다.
	if (abs(dir1 - dir2) == 2)
		return true;
	else
		return false;
}

bool Turn(int dir1, int dir2)
{
	// 뒤를 도는 경우
	if (TurnBack(dir1, dir2))	
		return false;

	// 직진인 경우
	if (dir1 == dir2)
		return false;

	// 그 외는 전부 회전한 경우이다.
	return true;
}

int Cost(int dir1, int dir2)
{
	if (Turn(dir1, dir2))
		return STRAIGHT + CORNER;
	else
		return STRAIGHT;
}	

int Search(vector<vector<int>> board)
{
	int answer = INF;

	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int dir = 0; dir < 4; ++dir)
		minCost[0][0][dir] = 0;

	if (board[1][0] == 0)
	{
		q.push({ { 1, 0 }, { 0, STRAIGHT } });
		minCost[1][0][0] = STRAIGHT;
	}

	if (board[0][1] == 0)
	{
		q.push({ { 0, 1 }, { 3, STRAIGHT } });
		minCost[0][1][3] = STRAIGHT;
	}

	while(!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curDir = q.front().second.first;
		int curCost = q.front().second.second;
		q.pop();

		if (curR == N - 1 && curC == N - 1)
		{
			if (answer > curCost)
				answer = curCost;
		}

		for (int nxtDir = 0; nxtDir < 4; ++nxtDir)
		{
			if (TurnBack(curDir, nxtDir))
				continue;
				
			int nxtR = curR + nr[nxtDir];
			int nxtC = curC + nc[nxtDir];
			int nxtCost = curCost + Cost(curDir, nxtDir);

			if (IsIn(nxtR, nxtC))
			{
				if (minCost[nxtR][nxtC][nxtDir] >= nxtCost && board[nxtR][nxtC] == 0)
				{
					minCost[nxtR][nxtC][nxtDir] = nxtCost;
					q.push({ { nxtR, nxtC }, { nxtDir, nxtCost }});
				}
			}
		}
	}

	return answer;
}

int solution(vector<vector<int>> board)
{
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			minCost[r][c][0]= INF;
			minCost[r][c][1] = INF;
			minCost[r][c][2] = INF;
			minCost[r][c][3] = INF;
		}
	}

	N = board.size();

	int answer = Search(board);
	
	return answer;
}

/*
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

#define MAX 30
#define INF 2e9

int R, C;
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };
int costs[MAX][MAX][4];

bool Is_In(int r, int c)
{
    return 0 <= r && r <= R && 0 <= c && c <= C;
}

int Min(int a, int b)
{
    return a < b ? a : b;
}

int solution(vector<vector<int>> board)
{
    int answer = INF;

    R = board.size() - 1;
    C = board.size() - 1;

    for (int r = 0; r <= R; ++r)
    {
        for (int c = 0; c <= C; ++c)
        {
            for (int i = 0; i < 4; ++i)
                costs[r][c][i] = INF;

        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, -1)));
    

    for (int i = 0; i < 4; ++i)
        costs[0][0][i] = 0;
    
    while (!q.empty())
    {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int curCost = q.front().second.first;
        int befDir = q.front().second.second;
        q.pop();

        if (curR == R && curC == C)
        {
            answer = Min(answer, costs[curR][curC][befDir]);
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nxtR = curR + nr[i];
            int nxtC = curC + nc[i];

            if (Is_In(nxtR, nxtC) && board[nxtR][nxtC] == 0)
            {
                int newCost = 0;

                if (befDir == -1 || i == befDir)
                    newCost = curCost + 100;
                else
                    newCost = curCost + 600;

                if (costs[nxtR][nxtC][i] >= newCost)
                {
                    costs[nxtR][nxtC][i] = newCost;
                    q.push(make_pair(make_pair(nxtR, nxtC), make_pair(newCost, i)));
                }
            }
        }
    }

    return answer;
}
*/
/*
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

#define MAX 26
#define INF 987654321
int check[MAX][MAX][4];

using namespace std;

int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };

bool Is_In(int r, int c, int N)
{
	return 0 <= r && r <= N && 0 <= c && c <= N;
}

bool Is_Back(int curDir, int nxtDir)
{
	switch (curDir)
	{
	case 0:
		if (nxtDir == 1)
			return true;
		else
			return false;
		break;
	case 1:
		if (nxtDir == 0)
			return true;
		else
			return false;
		break;
	case 2:
		if (nxtDir == 3)
			return true;
		else
			return false;
		break;
	case 3:
		if (nxtDir == 2)
			return true;
		else
			return false;
		break;
	}
    
    return true;
}

bool Is_Turn(int curDir, int nxtDir)
{
	switch (curDir)
	{
	case 0:
	case 1:
		if (nxtDir == 2 || nxtDir == 3)
			return true;
		else
			return false;
		break;
	case 2:
	case 3:
		if (nxtDir == 0 || nxtDir == 1)
			return true;
		else
			return false;
		break;
	}
    
    return true;
}

int solution(vector<vector<int>> board)
{
	int answer = INF;

	int end = board.size() - 1;

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0, 0}, {0, 0} });
	q.push({ {0, 0}, {0, 2} });
	
	check[0][0][0] = 1;
	check[0][0][2] = 1;

	while (!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curCost = q.front().second.first;
		int curDir = q.front().second.second;
		q.pop();

		if (curR == end && curC == end)
		{
			if (answer > curCost)
				answer = curCost;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];
			int nxtDir = i;

			if (Is_Back(curDir, nxtDir))
				continue;

			if (!Is_In(nxtR, nxtC, end))
				continue;

			if (board[nxtR][nxtC] == 1)
				continue;

			int nxtCost = curCost + 100;
			if (Is_Turn(curDir, nxtDir))
				nxtCost += 500;
			
			if (check[nxtR][nxtC][nxtDir] == 0 ||
				check[nxtR][nxtC][nxtDir] > nxtCost)
			{
				check[nxtR][nxtC][nxtDir] = nxtCost;
				q.push({ { nxtR, nxtC }, { nxtCost, nxtDir } });
			}
		}
	}

	return answer;
}
*/