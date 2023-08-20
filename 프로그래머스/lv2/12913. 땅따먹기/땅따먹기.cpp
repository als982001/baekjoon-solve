#include <iostream>
#include <vector>
using namespace std;

#define MAX 100002

int R;
int check[MAX][4];
vector<vector<int>> lnd;

int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int DFS(int r, int c)
{


	if (r == 0)
		return lnd[r][c];

	if (check[r][c] >= 0)
		return check[r][c];

	check[r][c] = lnd[r][c];
	int& curCheck = check[r][c];

	int maxScore = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (i != c)
			maxScore = Max(maxScore, DFS(r - 1, i));
	}

	curCheck += maxScore;

	return curCheck;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;

    R = land.size();
	lnd = land;
	
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < 4; ++c)
			check[r][c] = -1;
	}

	for (int c = 0; c < 4; ++c)
		answer = Max(answer, DFS(R - 1, c));
	
    return answer;
}