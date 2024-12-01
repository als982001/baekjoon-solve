#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 601

using namespace std;

int N, M;
int visitCount = 0;
int startN, startM;
string campus[MAX];
bool visited[MAX][MAX];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

bool IsIn(int n, int m)
{
    return 0 <= n && n < N && 0 <= m && m < M;
}

void DFS(int n, int m)
{
    if (visited[n][m])
        return;
    visited[n][m] = true;
    
    if (campus[n][m] == 'P')
    {
        ++visitCount;
    }
    
    for (int i = 0; i < 4; ++i)
    {
        int nxtN = n + dir[i][0];
        int nxtM = m + dir[i][1];
        
        if (IsIn(nxtN, nxtM) && campus[nxtN][nxtM] != 'X')
            DFS(nxtN, nxtM);
    }
    
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for (int n = 0; n < N; ++n)
    {
        cin >> campus[n];
        
        for (int m = 0; m < M; ++m)
        {
            if (campus[n][m] == 'I')
            {
                startN = n;
                startM = m;
            }
        }
    }
    
    DFS(startN, startM);

    if (visitCount == 0)
        printf("TT\n");
    else
        printf("%d\n", visitCount);

    return 0;
}