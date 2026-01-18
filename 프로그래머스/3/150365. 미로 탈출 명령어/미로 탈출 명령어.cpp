#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

#define MAX 51
#define IMPOSSIBLE "impossible"

using namespace std;

int R, C;
int endR, endC;
char dirs[4] = { 'd', 'l', 'r', 'u' };
string visited[MAX][MAX];
map<char, pair<int, int>> coordDirs;

void Init()
{
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            visited[r][c] = "";
    }
    
    coordDirs['l'] = { 0, -1 };
    coordDirs['r'] = { 0, 1 };
    coordDirs['u'] = { -1, 0 };
    coordDirs['d'] = { 1, 0 };
}

bool IsIn(int r, int c)
{
    return 1 <= r && r <= R && 1 <= c && c <= C;
}

bool CanChange(int r, int c, string route)
{   
    // 더 최신 루트면 return true;
    if (visited[r][c].size() < route.size())
        return true;
    
    // 사전 순으로 했을 때 더 빠르면 true
    return visited[r][c] > route;
}

string Check(int startR, int startC, int limit)
{
    string result = IMPOSSIBLE;
    
    queue<pair<pair<int, int>, string>> q;
    q.push({ { startR, startC }, "" });
    
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        string route = q.front().second;
        
        q.pop();
        
        if (route.size() >= limit)
        {
            if (r == endR && c == endC)
            {
                result = route;
                break;
            }
            else
                continue;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            char dir = dirs[i];
            pair<int, int> coordDir = coordDirs[dir];
            
            int nxtR = r + coordDir.first;
            int nxtC = c + coordDir.second;
            string nxtRoute = route + dir;
            
            if (IsIn(nxtR, nxtC) && CanChange(nxtR, nxtC, nxtRoute))
            {
                visited[nxtR][nxtC] = nxtRoute;
                q.push({ { nxtR, nxtC }, nxtRoute });
            }
        }
    }
    
    return result;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    Init();
    
    R = n;
    C = m;
    endR = r;
    endC = c;
    
    string answer = Check(x, y, k);
    
    return answer;
}






















/*


#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 52
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


*/