#include <iostream>
#include <queue>

#define MAX 301

using namespace std;

int R, C;
int cityMap[MAX][MAX];
bool visited[MAX][MAX];
int nxtDir[2][2] = { { 1, 0 }, { 0, 1 } };

bool IsIn(int r, int c)
{
    return 1 <= r && r <= R && 1 <= c && c <= C;
}

bool Check()
{
    bool canGo = false;
    
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    
    visited[1][1] = true;
    
    while(!q.empty())
    {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
                
        if (curR == R && curC == C)
        {
            canGo = true;
            break;
        }
        
        for (int i = 0; i < 2; ++i)
        {
            int nxtR = curR + nxtDir[i][0];
            int nxtC = curC + nxtDir[i][1];
            
            if (IsIn(nxtR, nxtC) && cityMap[nxtR][nxtC] == 1 && visited[nxtR][nxtC] == false)
            {
                visited[nxtR][nxtC] = true;
                q.push({ nxtR, nxtC });
            }
        }
    }
    
    return canGo;
}

int main()
{
    ios_base::sync_with_stdio(0);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    
    cin >> C >> R;
    
    for (int r = 1; r <= R; ++r)
    {
        for (int c = 1; c <= C; ++c)
        {
            cin >> cityMap[r][c];
        }
    }
    
    bool canGo = Check();
    
    if (canGo) 
    {
        cout << "Yes" << endl;
    } 
    else
    {
        cout << "No" << endl;
    }

    return 0;
}