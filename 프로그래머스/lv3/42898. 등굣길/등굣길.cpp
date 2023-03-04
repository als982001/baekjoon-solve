#include <string>
#include <vector>
#include <memory.h>

using namespace std;

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
    
    if (isPuddle[r][c])
		return 0;
		
	if (r == 1 && c == 1)
		return 1;

    visited[r][c] = 0;
    int& dp = visited[r][c];
    
	dp += ((Go(r - 1, c) + Go(r, c - 1)) % MOD);
    
    return dp;
}

int solution(int m, int n, vector<vector<int>> puddles)
{
	R = n;
	C = m;

	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
        {
            visited[r][c] = -1;
            isPuddle[r][c] = false;
        }
	}

	for (int i = 0; i < puddles.size(); ++i)
	{
		vector<int> puddle = puddles[i];	
		int puddleR = puddle[1];
		int puddleC = puddle[0];

		isPuddle[puddleR][puddleC] = true;
	}

	int answer = Go(R, C);

	return answer;
}
 