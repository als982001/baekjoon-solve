#include <string>
#include <vector>
#include <memory.h>

using namespace std;

/*
#define MAX 101
#define MOD 1000000007

int R, C;
int visited[MAX][MAX];
bool isPuddle[MAX][MAX];

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Go(int r, int c)
{
	if (IsIn(r, c) == false)
		return 0;

	if (visited[r][c] >= 0)
		return visited[r][c];
		
	if (r == 1 && c == 1)
		return 1;

	if (isPuddle[r][c])
		return 0;

	int& dp = visited[r][c];
	dp = 0;

	dp += ((Go(r - 1, c) + Go(r, c - 1)) % MOD);

	return dp %= MOD;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
	R = n;
	C = m;

	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
			visited[r][c] = -1;
	}

	for (int i = 0; i < puddles.size(); ++i)
	{
		vector<int> puddle = puddles[i];	
		int puddleR = puddle[0];
		int puddleC = puddle[1];

		isPuddle[puddleR][puddleC] = true;
	}

	int answer = Go(R, C);

	return answer;
}
*/

// ================================
#define MAX 111

int R, C;
int dp[MAX][MAX];
bool puddle[MAX][MAX];

int Is_In(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

int Solve(int r, int c)
{
	if (!Is_In(r, c))
		return 0;

	if (dp[r][c] >= 0)
		return dp[r][c];

	if (puddle[r][c])
		return 0;

	if (r == 1 && c == 1)
		return 1;

	dp[r][c] = 0;
	int& curDp = dp[r][c];

	return curDp += ((Solve(r - 1, c) + Solve(r, c - 1)) % 1000000007);
}

int solution(int m, int n, vector<vector<int>> puddles)
{
	R = n;
	C = m;

	for (int i = 0; i < puddles.size(); ++i)
	{
		vector<int> curPuddle = puddles[i];

		puddle[curPuddle[1]][curPuddle[0]] = true;
	}

	memset(dp, -1, sizeof(dp));

	int answer = Solve(R, C);

	return answer;
}
