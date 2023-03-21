#include <vector>
#include <queue>
using namespace std;

#define MAX 111

int R, C;                   // 주어진 picture의 행, 열 길이
int id = 0;                 // 각 영역의 시작 id이자, 영역의 개수를 저장할 변수
int maxAreaSize = -1;       // 최대 영역의 크기
int areaId[MAX][MAX];       // 각 지점마다, 자신이 속한 영역의 id를 저장할 2차원 배열
int nr[4] = { 1, -1, 0, 0 };
int nc[4] = { 0, 0, 1, -1 };    

// (r, c)가 주어진 범위 안에 있는지를 검사하는 함수
bool IsIn(int r, int c)
{
	return 0 <= r && r < R && 0 <= c && c < C;
}

vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    // 1. 변수들을 전부 초기화한다.
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
        {
            areaId[r][c] = 0;
        }
    }
    
    id = 0;
    maxAreaSize = -1;
	R = m;
	C = n;
    
    // 2. 모든 점들을 한 번씩 살펴본다.
	for (int r = 0; r < picture.size(); ++r)
	{
		for (int c = 0; c < picture[r].size(); ++c)
		{   
            // 2-1. 만약 (r, c) 위치에 색이 칠해져 있으면서, 한 번도 검사한 적이 없는 곳이면
            // 이 곳을 시작으로 검사를 시작한다.
			if (picture[r][c] > 0 && areaId[r][c] == 0)
			{
				int curColor = picture[r][c];   // 현재 색
				int curAreaSize = 0;            // 현재 영역의 크기
				int curId = ++id;               // 현재 영역의 id
				areaId[r][c] = curId;

				queue<pair<int, int>> q;
				q.push({ r, c });

				while(!q.empty())
				{
					int curR = q.front().first;
					int curC = q.front().second;
					q.pop();

					++curAreaSize;  // 현재 영역의 크기를 1 증가히킨다.

                    // 2-2. 만약 상하좌우의 다음 지점의 색이 현재 색이랑 같으면서 한 번도 검사한 적이 없는 곳이라면
                    // 검사한 적 없는 같은 영역이라는 뜻이므로 queue에 push한다.
					for (int i = 0; i < 4; ++i)
					{
						int nxtR = curR + nr[i];
						int nxtC = curC + nc[i];

						if (IsIn(nxtR, nxtC))
						{
							if (picture[nxtR][nxtC] == curColor && areaId[nxtR][nxtC] == 0)
							{
								areaId[nxtR][nxtC] = curId;
								q.push({ nxtR, nxtC });
							}
						}
					}
				}
                
                // 2-3. 모든 검사가 끝난 후, 최대 영역 크기를 갱신할 수 있으면 한다.
				if (maxAreaSize < curAreaSize)
					maxAreaSize = curAreaSize;
			}
		}
	}
    
    // 첫 번째 영역의 id는 1이고 두 번째 영역의 id는 2이다.
    // 즉, id의 값은 영역의 개수이다.
	return { id, maxAreaSize };
}
