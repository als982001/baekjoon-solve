#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 11

int maxScoreDiff = -1;
vector<int> lionArrow;
vector<int> apeachArrow;
vector<int> answer;

bool CanRenew(int curScoreDiff)
{
	if (curScoreDiff > maxScoreDiff)
		return true;

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
	
	return false;
}

void ScoreCheck(int leftArrow, int score)
{
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

		if (lionScore > apeachScore)
		{
			int curScoreDiff = lionScore - apeachScore;

			if (CanRenew(curScoreDiff))
			{
				maxScoreDiff = curScoreDiff;
				answer = lionArrow;
			}
		}

		return;
	}

	if (score == 0 && leftArrow > 0)
	{
		lionArrow[0] = leftArrow;
		ScoreCheck(0, score - 1);
		lionArrow[0] = 0;
	}

	int curRequiredArrow = apeachArrow[score] + 1;

	if (leftArrow >= curRequiredArrow)
	{
		lionArrow[score] = curRequiredArrow;
		ScoreCheck(leftArrow - curRequiredArrow, score - 1);
		lionArrow[score] = 0;
	}

	ScoreCheck(leftArrow, score - 1);
}

vector<int> solution(int n, vector<int> info) 
{
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

	ScoreCheck(n, 10);

	if (maxScoreDiff == -1)
		return { -1 };

	reverse(answer.begin(), answer.end());

	return answer;
}

/*
#define MAX 11

int maxScore;
bool check[MAX];
vector<int> ans;

void Renewal_Score(int n, vector<int> required)
{
	vector<int> tempAns;
	int myScore = 0;
	int rivalScore = 0;

	for (int i = 0; i < MAX; ++i)
	{
		if (check[i])
		{
			if (n >= required[i])
			{
				tempAns.push_back(required[i]);
				n -= required[i];

			}
			else
				tempAns.push_back(n);

			myScore += (10 - i);
		}
		else
		{
			tempAns.push_back(0);

			if (required[i] >= 2)
				rivalScore += (10 - i);
		}
	}

	if (myScore - rivalScore > maxScore)
	{
		maxScore = myScore - rivalScore;
		ans = tempAns;
		return;
	}
	else if (myScore - rivalScore == maxScore)
	{
		if (ans.size() == 0)
		{
			maxScore = myScore - rivalScore;
			ans = tempAns;
			return;
		}
		else
		{
			for (int i = tempAns.size() - 1; i >= 0; --i)
			{
                if (tempAns[i] < ans[i])
                    return;
                
				if (tempAns[i] > ans[i])
				{
					maxScore = myScore - rivalScore;
					ans = tempAns;
					return;
				}
			}
		}
	}
}

void DFS(int n, int leftArrows, int idx, vector<int> required)
{
	if (leftArrows < 0)
	{
		if (idx >= MAX)
			Renewal_Score(n, required);
		
		return;
	}

	if (leftArrows == 0)
	{
		Renewal_Score(n, required);

		return;
	}

	for (int i = idx; i < MAX; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			DFS(n, leftArrows - required[i], i + 1, required);
			check[i] = false;
		}
	}
}

vector<int> solution(int n, vector<int> info) {
	vector<int> answer;

	for (int i = 0; i < MAX; ++i)
		check[i] = false;
	ans.clear();
	maxScore = 0;

	vector<int> required(MAX, 0);

	for (int i = 0; i < info.size(); ++i)
		required[i] = info[i] + 1;

	DFS(n, n, 0, required);

	if (maxScore == 0)
		answer.push_back(-1);
	else
		answer = ans;
	return answer;
}
*/