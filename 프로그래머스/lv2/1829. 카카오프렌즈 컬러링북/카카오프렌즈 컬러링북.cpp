#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int R, C;
int lastId;
int maxSize;
int id[MAX][MAX];

bool IsInside(int r, int c)
{
    return (0 <= r && r < R) && (0 <= c && c < C);
}

void Check(vector<vector<int>> picture)
{
    int nr[4] = { 1, -1, 0, 0 };
    int nc[4] = { 0, 0, 1, -1 };
    
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (id[r][c] == -1 && picture[r][c]  > 0)
            {
                int curSize = 0;
                int curColor = picture[r][c];

                int curId = lastId++;   
                id[r][c] = curId;

                queue<pair<int, int>> q;
                q.push({ r, c });

                while(!q.empty())
                {
                    int curR = q.front().first;
                    int curC = q.front().second;
                    q.pop();
                    
                    ++curSize;

                    for (int i = 0; i < 4; ++i)
                    {
                        int nxtR = curR + nr[i];
                        int nxtC = curC + nc[i];

                        if (IsInside(nxtR, nxtC))
                        {
                            if (picture[nxtR][nxtC] == curColor && id[nxtR][nxtC] == -1)
                            {
                                id[nxtR][nxtC] = curId;
                                q.push({ nxtR, nxtC });
                            }
                        }
                    }
                }

                if (maxSize < curSize)
                    maxSize = curSize;
            }
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    R = m;
    C = n;
    lastId = 0;
    maxSize = -1;
        
    for (int r = 0; r < MAX; ++r)
    {
        for (int c = 0; c < MAX; ++c)
            id[r][c] = -1;
    }
    
    Check(picture);
    
    return { lastId, maxSize };
}