#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

#define MAX 51

int rectangleNum = 0;
int minX = MAX * MAX;
int minY = MAX * MAX;
int maxX = -1;
int maxY = -1;
bool visited[MAX][MAX];
int nx[4] = { 1, -1, 0, 0 };
int ny[4] = { 0, 0, 1, -1 };
map<int, bool> edge[MAX][MAX];
vector<vector<int>> allRectangles;

bool IsIn(int x, int y)
{
	return minX <= x && x <= maxX && minY <= y && y <= maxY;
}

bool CanGo(int fromX, int fromY, int toX, int toY)
{
	for (int rectangleIdx = 1; rectangleIdx <= rectangleNum; ++rectangleIdx)
	{
		if (edge[fromX][fromY][rectangleIdx] == true && edge[toX][toY][rectangleIdx] == true)
			return true;
	}

	return false;
}

bool IsRealEdge(double fromX, double fromY, double toX, double toY)
{	
	double midX = (fromX + toX) / 2;
	double midY = (fromY + toY) / 2;

	for (int i = 0; i < allRectangles.size(); ++i)
	{
		vector<int> rectangle = allRectangles[i];

		int leftBottomX = rectangle[0];
		int leftBottomY = rectangle[1];
		int rightTopX = rectangle[2];
		int rightTopY = rectangle[3];

		if (leftBottomX < midX && midX < rightTopX && leftBottomY < midY && midY < rightTopY)
			return false;
	}
    
    return true;
}

int Check(int startX, int startY, int endX, int endY) 
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { startX, startY } , 0 });
	visited[startX][startY]= true;

	while(!q.empty())
	{
		int curX = q.front().first.first;
		int curY = q.front().first.second;
		int curTime = q.front().second;
		q.pop();

		if (curX == endX && curY == endY)
			return curTime;

		for (int i = 0; i < 4; ++i)
		{
			int nxtX = curX + nx[i];
			int nxtY = curY + ny[i];

			if (IsIn(nxtX, nxtY))
			{
				if (visited[nxtX][nxtY] == false && CanGo(curX, curY, nxtX, nxtY) && IsRealEdge(curX, curY, nxtX, nxtY))
				{
					visited[nxtX][nxtY] = true;
					q.push({ { nxtX, nxtY }, curTime + 1 });
				}
			}
		}
	}
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    int answer = 0;
	
	allRectangles = rectangle;

	for (int i = 0; i < rectangle.size(); ++i)
	{
		vector<int> rectangle = allRectangles[i];

		int leftBottomX = rectangle[0];
		int leftBottomY = rectangle[1];
		int rightTopX = rectangle[2];
		int rightTopY = rectangle[3];
		int rectangleIdx = ++rectangleNum;

		for (int x = leftBottomX; x <= rightTopX; ++x)
		{
			edge[x][leftBottomY][rectangleIdx] = true;
			edge[x][rightTopY][rectangleIdx] = true;
		}

		for (int y = leftBottomY; y <= rightTopY; ++y)
		{
			edge[leftBottomX][y][rectangleIdx] = true;
			edge[rightTopX][y][rectangleIdx] = true;
		}

		if (minX > leftBottomX)
			minX = leftBottomX;
		if (minY > leftBottomY)
			minY = leftBottomY;
		if (maxX < rightTopX)
			maxX = rightTopX;
		if (maxY < rightTopY)
			maxY = rightTopY;
	}

	answer = Check(characterX, characterY, itemX, itemY);

    return answer;
}