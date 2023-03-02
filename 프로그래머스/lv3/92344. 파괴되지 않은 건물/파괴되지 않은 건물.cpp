#include <string>
#include <vector>

using namespace std;

#define MAX 1011
#define HEAL 2
#define DESTROY 0

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
	int answer = 0;

	int R = board.size();
	int C = board[0].size();

	// 1. 누적합을 기록할 변수를 선언한다.
	vector<vector<int>> skillsHistory(R + 2, vector<int>(C + 2, 0));

	// 2. 모든 skill의 누적합을 기록한다.
	for (int s = 0; s < skill.size(); ++s)
	{
		vector<int> curSkill = skill[s];

		int skillType = curSkill[0];
		int startR = curSkill[1];
		int startC = curSkill[2];
		int endR = curSkill[3];
		int endC = curSkill[4];
		int degree = skillType == HEAL ? curSkill[5] : -curSkill[5];

		skillsHistory[startR][startC] += degree;
		skillsHistory[endR + 1][startC] -= degree;
		skillsHistory[startR][endC + 1] -= degree;
		skillsHistory[endR + 1][endC + 1] += degree;
	}

	// 3. 누적합을 계산하여 각 구역마다의 degree 값들을 구한다/
	// 3-1. 각 열에 따른 값들 우선 계산
	for (int c = 0; c <= C; ++c)
	{
		for (int r = 1; r <= R; ++r)
			skillsHistory[r][c] += skillsHistory[r - 1][c];
	}

	// 3-2. 각 행에 따른 값 계산
	for (int r = 0; r <= R; ++r)
	{
		for (int c = 0; c <= C; ++c)
			skillsHistory[r][c + 1] += skillsHistory[r][c];
	}

	// 4. 각 구역에 degree 값을 더한 후, 파괴되지 않은 건물 수를 구한다.
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; ++c)
		{
			if (board[r][c] + skillsHistory[r][c] > DESTROY)
				++answer;
		}
	}

	return answer;
}

