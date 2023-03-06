#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321
#define MAX 26
#define STRAIGHT 100
#define CORNER 500

int N;  // board의 한 변의 길이
int minCost[MAX][MAX][4];   // 각 지점의 방향에 따른 최소 비용

// 다음 방향을 위한 변수들. 순서대로 아래쪽, 왼쪽, 윗쪽, 오른쪽
int nr[4] = { 1, 0, -1, 0 };    
int nc[4] = { 0, -1, 0, 1 };  

// 현재 위치가 범위 안에 있는지를 반환
bool IsIn(int r, int c)
{
	return 0 <= r && r < N && 0 <= c && c < N;
}

// 두 개의 방향이 서로 반대 방향인지 (180도 회전하여 뒤로 돌아있는지)
bool TurnBack(int dir1, int dir2)
{
	// 0이랑 2는 서로 위아래 방향이라 뒤를 도는 방향
	// 1이랑 3은 서로 좌우 방향이라 뒤를 도는 방향
	// 즉, dir1과 dir2의 차이가 2라면 뒤를 돈다고 볼 수 있다.
	if (abs(dir1 - dir2) == 2)
		return true;
	else
		return false;
}

// 두 개의 방향이 서로 직각인지 (회전을 했는지))
bool Turn(int dir1, int dir2)
{
	// 뒤를 도는 경우
	if (TurnBack(dir1, dir2))	
		return false;

	// 직진인 경우
	if (dir1 == dir2)
		return false;

	// 그 외는 전부 회전한 경우이다.
	return true;
}

// 방향에 따른 추가 비용
int Cost(int dir1, int dir2)
{   
    // 만약 회전을 한다면 직선 도로 비용 + 코너 비용
	if (Turn(dir1, dir2))
		return STRAIGHT + CORNER;
	else    // 아니라면 직선 비용만
		return STRAIGHT;
}	

// 최소 비용을 찾기 위한 함수
int Search(vector<vector<int>> board)
{
	int answer = INF;
        
    // 큐에는 순서대로 r좌표, c좌표, 현재 방향, 현재 비용이 저장된다.
	queue<pair<pair<int, int>, pair<int, int>>> q;
	for (int dir = 0; dir < 4; ++dir)
		minCost[0][0][dir] = 0;
    
    // (0, 0)에서는 (1, 0), (0, 1)로 진행할 수 있으므로
    // 나아갈 수 있다면 진행한다.
	if (board[1][0] == 0)
	{
		q.push({ { 1, 0 }, { 0, STRAIGHT } });
		minCost[1][0][0] = STRAIGHT;
	}

	if (board[0][1] == 0)
	{
		q.push({ { 0, 1 }, { 3, STRAIGHT } });
		minCost[0][1][3] = STRAIGHT;
	}

	while(!q.empty())
	{
		int curR = q.front().first.first;
		int curC = q.front().first.second;
		int curDir = q.front().second.first;
		int curCost = q.front().second.second;
		q.pop();
        
        // 만약 도착점이라면, 비용을 비교하여 비용 저장
		if (curR == N - 1 && curC == N - 1)
		{
			if (answer > curCost)
				answer = curCost;
                    
            continue;   // 이 곳에서는 더 진행할 필요 없음
		}
        
        // 다음 방향을 반복문을 이용해 진행
		for (int nxtDir = 0; nxtDir < 4; ++nxtDir)
		{   
            // 만약 현재 방향에서 180도 회전한 방향이라면, 그냥 패스
			if (TurnBack(curDir, nxtDir))
				continue;
				
			int nxtR = curR + nr[nxtDir];
			int nxtC = curC + nc[nxtDir];
			int nxtCost = curCost + Cost(curDir, nxtDir);
    
			if (IsIn(nxtR, nxtC))
			{
				if (minCost[nxtR][nxtC][nxtDir] >= nxtCost && board[nxtR][nxtC] == 0)
				{
                    // 범위 안에 있으면서 방향에 따른 최소 금액이 맞다면 진행
					minCost[nxtR][nxtC][nxtDir] = nxtCost;
					q.push({ { nxtR, nxtC }, { nxtDir, nxtCost }});
				}
			}
		}
	}

	return answer;
}

int solution(vector<vector<int>> board)
{
    // 비교의 편의를 위해서, 모든 지점에서 모든 방향에서의 비용을 가능한 크게 설정.
	for (int r = 0; r < MAX; ++r)
	{
		for (int c = 0; c < MAX; ++c)
		{
			minCost[r][c][0] = INF;
			minCost[r][c][1] = INF;
			minCost[r][c][2] = INF;
			minCost[r][c][3] = INF;
		}
	}

	N = board.size();

	int answer = Search(board);
	
	return answer;
}