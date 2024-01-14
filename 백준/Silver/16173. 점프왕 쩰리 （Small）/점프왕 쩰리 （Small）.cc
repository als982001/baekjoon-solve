#include <iostream>
#include <queue>
#pragma warning(disable:4996)
#define MAX 4
using namespace std;

int N;
int givenMap[MAX][MAX];
bool visited[MAX][MAX];
int nr[2] = { 1, 0 };
int nc[2] = { 0, 1 };

bool IsInside(int r, int c)
{
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

int main()
{
 	ios_base::sync_with_stdio(0);
	std::cout.tie(NULL);    
	std::cin.tie(NULL);

    cin >> N;

    for (int r = 1; r <= N; ++r)
    {
        for (int c = 1; c <= N; ++c)
            cin >> givenMap[r][c];
    }

    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    visited[1][1] = true;

    bool success = false;

    while(q.empty() == false && success == false)
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();

        if (curR == N && curC == N)
        {
            success = true;
            break;
        }

        int moveSteps = givenMap[curR][curC];

        for (int i = 0; i < 2; ++i)
        {
            int nxtR = curR + (nr[i] * moveSteps);
            int nxtC = curC + (nc[i] * moveSteps);

            if (IsInside(nxtR, nxtC))
            {
                if (visited[nxtR][nxtC] == false)
                {
                    visited[nxtR][nxtC] = true;
                    q.push({ nxtR, nxtC });
                }
            }
        }
    }
    
    if (success)
        printf("HaruHaru\n");
    else
        printf("Hing\n");

	return 0;
}