#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 11

int maxScoreDiff = -1;		// 라이언과 어피치의 가장 큰 점수 차이
vector<int> lionArrow;		// 라이언의 화살
vector<int> apeachArrow;	// 어피치의 화살 (문제에서 주어짐))
vector<int> answer;			// 답

bool CanRenew(int curScoreDiff)
{	
	// 2-4-2. 만약, 기존의 점수차보다 더 크다면 당연히 갱신할 수 있으므로 true를 반환한다.
	if (curScoreDiff > maxScoreDiff)
		return true;

	// 2-4-3. 만약, 기존의 점수차와 같은 점수차라면 
	// 문제의 조건인 '가장 낮은 점수를 더 많이 맞힌 경우'인지 확인한다.
	// 이를 통해 갱신가능하다면 true를 반환한다.
	if (curScoreDiff == maxScoreDiff)
	{
		for (int score = 0; score <= 10; ++score)
		{
			if (answer[score] < lionArrow[score])
				return true;
			else if (answer[score] > lionArrow[score])
				return false;
		}
	}
	
	return false;	// 결국 갱신할 수 없는 경우이므로 false 반환
}

// 10점부터 시작해서 0점까지 활을 쏘는 경우를 검사하는 함수
void ScoreCheck(int leftArrow, int score)
{
	// 2-4. 만약, 모든 점수에 대해 고려를 끝낸 상황이라면, 라이언의 점수와 어피치의 점수를 비교한다.
	if (score < 0)
	{	
		int lionScore = 0;
		int apeachScore = 0;

		for (int score = 0; score <= 10; ++score)
		{
			if (lionArrow[score] == 0 && apeachArrow[score] == 0)
				continue;

			if (lionArrow[score] > apeachArrow[score])
				lionScore += score;
			else
				apeachScore += score;
		}

		// 2-4-1. 만약, 라이언의 점수가 어피치의 점수보다 크다면, 
		// 답이 될 수 있는 상황이다.
		if (lionScore > apeachScore)
		{
			int curScoreDiff = lionScore - apeachScore;

			// 2-4-4. 만약, 답을 갱신할 수 있다면 갱신한다.
			if (CanRenew(curScoreDiff))
			{
				maxScoreDiff = curScoreDiff;
				answer = lionArrow;
			}
		}

		return;
	}

	// 2-3. 만약 현재 고려중인 점수가 0점이면서, 남은 화살이 있는 경우
	// 0점에 모든 화살을 쏜다.
	// 왜냐하면 문제 조건에서 '가장 낮은 ㅈ머수를 더 많이 맞힌 경우'를 구하라고 했기 때문이다.
	if (score == 0 && leftArrow > 0)
	{
		lionArrow[0] = leftArrow;
		ScoreCheck(0, score - 1);
		lionArrow[0] = 0;
	}

	// 2-1. 만약 득점에 필요한 화살 수(현재 점수의 어피치화살 수 + 1)보다 많은 화살을 가지고 있다면
	// 득점할 수 있는 기회이므로 이 점수를 획들한 후의 상황을 점검한다.
	int curRequiredArrow = apeachArrow[score] + 1;

	if (leftArrow >= curRequiredArrow)
	{
		lionArrow[score] = curRequiredArrow;
		ScoreCheck(leftArrow - curRequiredArrow, score - 1);
		lionArrow[score] = 0;
	}

	// 2-2. 이 점수를 획득하지 않고 진행하는 경우도 확인한다.
	ScoreCheck(leftArrow, score - 1);
}

vector<int> solution(int n, vector<int> info) 
{	
	// 1. 문제를 풀기 위해 필요한 변수들의 값을 초기화한다.
	maxScoreDiff = -1;

	answer.clear();
	lionArrow.clear();
	apeachArrow.clear();

	for (int i = 0; i < MAX; ++i)
	{
		answer.push_back(0);
		lionArrow.push_back(0);
		apeachArrow.push_back(0);
	}

	for (int infoIdx = 0, score = 10; infoIdx < info.size(); ++infoIdx, --score)
		apeachArrow[score] = info[infoIdx];

	// 2. 라이언이 득점할 수 있는 모든 경우를 체크한다.
	ScoreCheck(n, 10);

	// 3. 만약, 최대 점수차가 갱신되지 않았다면,
	// 어피치를 이길 수 없는 상황이라는 뜻이므로 
	// 문제의 조건에 따라 { -1 }을 반환한다.
	if (maxScoreDiff == -1)
		return { -1 };

	// 아니라면 answer를 reverse하여 반환한다.
	// 왜냐하면 answer[10]은 10점의 화살 개수인데, 
	// 문제에서 요구하는 답은 거꾸로 answer[0]에 10점의 화살 개수가 담긴 형태이기 때문이다.
	reverse(answer.begin(), answer.end());

	return answer;
}