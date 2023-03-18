#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 111		// 'n은 5 이상 100 이하인 자연수'
#define PILLAR 0	// 기둥
#define CROSSBEAM 1	// 보
#define REMOVE 0	// 삭제
#define BUILD 1		// 설치

bool pillar[MAX][MAX];		// pillar[x][y] = true -> (x, y)에 기둥 설치되어 있다는 뜻
bool crossbeam[MAX][MAX];	// crossbeam[x][y] = true -> (x, y)에 보 설치되어 있다는 뜻

// 해당 좌표에 기둥을 세울 수 있는지를 반환하는 함수
bool CanBuildPillar (int x, int y)
{
	// 기둥이 바닥 위에 있는 경우
	if (y == 0)
		return true;

	// 2. 보의 한쪽 끝 부분 위에 있는 경우
	// 어떤 보의 오른쪽 위에 있는 경우 => (x-1, y)
	// 어떤 보의 왼쪽 끝에 있는 경우 => (x, y)
	if (crossbeam[x - 1][y] == true || crossbeam[x][y] == true)
		return true;

	// 3. 다른 기둥 위에 있는 경우
	if (pillar[x][y - 1] == true)
		return true;

	return false;
}

// 해당 좌표에 보를 세울 수 있는지를 반환하는 함수
bool CanBuildCrossbean(int x, int y)
{
	// 1. 한쪽 끝 부분이 기둥 위에 있는 경우
	if (pillar[x][y - 1] == true || pillar[x + 1][y - 1] == true)
		return true;

	// 2. 양쪽 끝 부분이 다른 보와 동시에 연결되어 있는 경우
	if (crossbeam[x - 1][y] == true && crossbeam[x + 1][y] == true)
		return true;

	return false;
}

// (x, y)의 기둥을 삭제할 수 있는지를 return 하는 함수
bool CanRemovePillar(int x, int y)
{	
	// 우선, 기둥이 삭제되었다고 가정한 후,
	// 이 기둥 주위의 구조물이 존재할 수 있는지(설치될 수 있는지) 판단한다.
	bool canRemove = true;	// 삭제할 수 있다면 true
	pillar[x][y] = false;	// 미리 삭제한 상태로 진행

	// 우선, 기둥은 다른 기둥 위에 설치할 수 있기 때문에,
	// 현재 기둥 위에 기둥이 하나 있으면 현재 기둥 없이도 설치될 수 있는지 확인
	if (pillar[x][y + 1] == true)
		canRemove = canRemove && CanBuildPillar(x, y + 1);

	// 보는 다른 기둥 위에 있을 경우 설치할 수 있다.
	// 그래서, 어떤 보의 오른쪽 부분이 기둥 위에 있으면,
	// 그 보가 이 기둥 없이 설치될 수 있는지를 확인한다. 
	if (crossbeam[x - 1][y + 1] == true)
		canRemove = canRemove && CanBuildCrossbean(x - 1, y + 1);
	
	// 마찬가지로 어떤 보의 왼쪽이 현재 기둥 위에 있다면,
	// 그 보가 현재 기둥 없이 설치될 수 있는지를 확인한다.
	if (crossbeam[x][y + 1] == true)
		canRemove = canRemove && CanBuildCrossbean(x, y + 1);

	// 만약 현재 기둥을 삭제할 수 있다면, true를 반환
	if (canRemove)
		return true;
	else	// 아니라면 다시 설치한 상태로 만든 후 false를 반환
	{
		pillar[x][y] = true;
		return false;
	}
}

// 보를 삭제할 수 있는지를 반환하는 함수
bool CanRemoveCrossbeam(int x, int y)
{	
	// 우선, 보가 삭제되었다고 가정한 후,
	// 이 보 주위의 구조물이 존재할 수 있는지(설치될 수 있는지) 판단한다.
	bool canRemove = true;		// 삭제할 수 있다면 true
	crossbeam[x][y] = false;	// 미리 삭제한 상태로 진행

	// 기둥은 다른 보의 위에 있어야 하기 때문에, 
	// 만약 현재 보의 왼쪽에 기둥이 존재한다면,
	// 이 보 없이도 기둥이 설치될 수 있는지를 판단한다.
	if (pillar[x][y] == true)
		canRemove = canRemove && CanBuildPillar(x, y);
	
	// 위와 마찬가지로, 보의 왼쪽에 기둥이 존재한다면,
	// 이 보 없이도 기둥이 설치될 수 있는지를 판단한다.
	if (pillar[x + 1][y] == true)
		canRemove = canRemove && CanBuildPillar(x + 1, y);

	// 보는 양쪽 끝에 다른 보와 연결되어 있어야 한다. 
	// 만약 현재 보의 왼쪽에 다른 보가 존재한다면
	// 이 보 없이도 그 보가 설치될 수 있는지를 판단한다.
	if (crossbeam[x - 1][y] == true)
		canRemove = canRemove && CanBuildCrossbean(x - 1, y);

	// 위와 마찬가지로, 현재 보의 오른쪽에 보가 존재한다면	
	// 이 보 없이도 그 보가 설치될 수 있는지를 판단한다.
	if (crossbeam[x + 1][y] == true)
		canRemove = canRemove && CanBuildCrossbean(x + 1, y);		

	// 만약 현재 기둥을 삭제할 수 있다면, true를 반환
	if (canRemove)
		return true;
	else	// 아니라면 다시 설치한 상태로 만든 후 false를 반환
	{
		crossbeam[x][y] = true;
		return false;
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) 
{
	vector<vector<int>> answer;

	// 시작 전 초기화
	for (int a = 0; a < MAX; ++a)
	{
		for (int b = 0; b < MAX; ++b)
		{
			pillar[a][b] = false;
			crossbeam[a][b] = false;
		}
	}

	for (int i = 0; i < build_frame.size(); ++i)
	{
		vector<int> frame = build_frame[i];

		int x = frame[0];			// 교차점 좌표 중 x
		int y = frame[1];			// 교차점 좌표 중 y
		int structure = frame[2];	// 구조물 종류
		int buildType = frame[3];	// 설치할지 삭제할지

		// 구조물을 삭제하는 경우
		if (buildType == REMOVE)
		{
			// 기둥을 삭제하는 경우
			if (structure == PILLAR)
			{	
				// 삭제가 가능하면 삭제한다.
				if (CanRemovePillar(x, y))
					pillar[x][y] = false;
			}
			
			// 보를 삭제하는 경우
			if (structure == CROSSBEAM)
			{
				// 삭제가 가능하면 삭제한다.
				if (CanRemoveCrossbeam(x, y))
					crossbeam[x][y] = false;
			}

		}
		
		// 구조물을 설치하는 경우
		if (buildType == BUILD)
		{
			// 기둥을 설치하는 경우
			if (structure == PILLAR)
			{
				// 설치 가능하면 설치
				if (CanBuildPillar(x, y))
					pillar[x][y] = true;
			}
			
			// 보를 설치하는 경우
			if (structure == CROSSBEAM)
			{
				// 설치 가능하면 설치
				if (CanBuildCrossbean(x, y))
					crossbeam[x][y] = true;
			}
		}
	}


	// 'return 하는 배열은 x좌표 기준으로 오름차순 정렬'
	for (int x = 0; x < MAX; ++x)
	{	
		// 'x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬'
		for (int y = 0; y < MAX; ++y)
		{
			// 'x, y좌표가 모두 같은 경우 기둥이 보보다 앞에 오면 됩니다.'
			if (pillar[x][y] == true)
				answer.push_back({ x, y, PILLAR });
			if (crossbeam[x][y] == true)
				answer.push_back({ x, y, CROSSBEAM });
		}
	}

	return answer;
}