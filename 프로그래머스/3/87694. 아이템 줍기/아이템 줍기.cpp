#include <string>
#include <vector>
#include <queue>

#define MAX 51
#define INF 987654321

using namespace std;

int minX = INF;
int minY = INF;
int maxX = -INF;
int maxY = -INF;
int rectanglesNum = 0;
int visited[MAX][MAX];
bool isEdge[MAX][MAX][4];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

// 값들을 초기화
void Init(vector<vector<int>>& rectangle)
{
    for (int x = 0; x < MAX; ++x)
    {
        for (int y = 0; y < MAX; ++y)
        {
            isEdge[x][y][0] = false;
            isEdge[x][y][1] = false;
            isEdge[x][y][2] = false;
            isEdge[x][y][3] = false;
            
            visited[x][y] = INF;
        }
    }
    
    for (int idx = 0; idx < rectangle.size(); ++idx)
    {
        ++rectanglesNum;
        
        int x1 = rectangle[idx][0];
        int y1 = rectangle[idx][1];
        int x2 = rectangle[idx][2];
        int y2 = rectangle[idx][3];
        
        if (minX > x1)
            minX = x1;
        if (minY > y1)
            minY = y1;
        if (maxX < x2)
            maxX = x2;
        if (maxY < y2)
            maxY = y2;
        
        for (int x = x1; x <= x2; ++x)
        {
            isEdge[x][y1][idx] = true;
            isEdge[x][y2][idx] = true;
        }
        
        for (int y = y1; y <= y2; ++y)
        {
            isEdge[x1][y][idx] = true;
            isEdge[x2][y][idx] = true;
        }
    }
}

// x, y가 범위 내에 존재한다면 true를 반환
bool IsIn(int x, int y)
{
    return minX <= x && x <= maxX && minY <= y && y <= maxY;
}

// 특정 사각형의 테두리 위라면 true를 반환
bool IsOnEdge(int fromX, int fromY, int toX, int toY)
{
    bool isOnEdge = false;
    
    for (int idx = 0; idx < rectanglesNum; ++idx)
    {
        if (isEdge[fromX][fromY][idx] && isEdge[toX][toY][idx])
        {
            isOnEdge = true;
            break;
        }
    }
    
    return isOnEdge;
}

// 사각형 내부가 아니라면 true를 반환
bool IsNotInSquare(double fromX, double fromY, double toX, double toY, vector<vector<int>>& rectangle)
{
    bool isNotInSquare = true;
    
    double midX = (fromX + toX) / 2;
    double midY = (fromY + toY) / 2;
    
    for (int idx = 0; idx < rectanglesNum; ++idx)
    {
        double x1 = (double)(rectangle[idx][0]);
        double y1 = (double)(rectangle[idx][1]);
        double x2 = (double)(rectangle[idx][2]);
        double y2 = (double)(rectangle[idx][3]);
        
        if (x1 < midX && midX < x2 && y1 < midY && midY < y2)
        {
            isNotInSquare = false;
            break;
        }
    }
    
    return isNotInSquare;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    Init(rectangle);
    
    queue<pair<pair<int, int>, int>> q;
    q.push({ { characterX, characterY }, 0 });
    
    visited[characterX][characterY] = 0;
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int times = q.front().second;
        
        q.pop();
        
        if (x == itemX && y == itemY)
        {
            answer = times;
            break;
        }
        
        for (int i = 0; i < 4; ++i)
        {
            int nxtX = x + dir[i][0];
            int nxtY = y + dir[i][1];
            int nxtTimes = times + 1;
            
            // 다음 좌표가 범위 안에 있으면서, 사각형 테두리 위이면서, 특정 사각형 내부가 아닌 경우에만 진행할 수 있다.
            if (IsIn(nxtX, nxtY) && IsOnEdge(x, y, nxtX, nxtY) && IsNotInSquare(x, y, nxtX, nxtY, rectangle) && visited[nxtX][nxtY] > nxtTimes)
            {
                visited[nxtX][nxtY] = nxtTimes;
                q.push({ { nxtX, nxtY }, nxtTimes });
            }
        }
    }
    
    return answer;
}
