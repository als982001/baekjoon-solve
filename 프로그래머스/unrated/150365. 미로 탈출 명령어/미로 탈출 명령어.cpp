#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51
#define IMPOSSIBLE "impossible"

int R, C, limit;
int nr[4] = { 1, 0, 0, -1 };
int nc[4] = { 0, -1, 1, 0 };
string visited[MAX][MAX];
string dir[4] = { "d", "l", "r", "u" };

bool IsIn(int r, int c)
{
	return 1 <= r && r <= R && 1 <= c && c <= C;
}

string Go(pair<int, int> start, pair<int, int> end)
{
	queue<pair<pair<int, int>, string>> q;
	q.push( { { start.first, start.second }, "" } );

	while(!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		string curRoute = q.front().second;
		q.pop();

		if (curRoute.size() >= limit)
		{
			if (curR == end.first && curC == end.second)
				return curRoute;
			else
				continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nxtR = curR + nr[i];
			int nxtC = curC + nc[i];

			if (IsIn(nxtR, nxtC))
			{
				string nxtRoute = curRoute + dir[i];

				if (visited[nxtR][nxtC] == "" || visited[nxtR][nxtC].size() < nxtRoute.size() || visited[nxtR][nxtC] > nxtRoute)
				{
					visited[nxtR][nxtC] = nxtRoute;
					q.push({ { nxtR, nxtC }, nxtRoute });
				}
			}
		}
	}

	return IMPOSSIBLE;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    R = n;
	C = m;
	limit = k;

	answer = Go({ x, y }, { r, c });
    
    return answer;
}