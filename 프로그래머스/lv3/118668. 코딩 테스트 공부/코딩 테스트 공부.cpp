#include <string>
#include <vector>

using namespace std;

#define MAX 151
#define INF 987654321

int targetAlp, targetCop;
int check[MAX][MAX];
vector<vector<int>> allProblems;

void Init()
{
	for (int a = 0; a < MAX; ++a)
	{
		for (int b = 0; b < MAX; ++b)
			check[a][b] = INF;
	}
	
	targetAlp = -1;
	targetCop = -1;
	allProblems.clear();
}

int Smaller(int a, int b)
{
	return a < b ? a : b;
}

int Check(int alp, int cop)
{
	if (alp >= targetAlp && cop >= targetCop)
		return 0;

	if (check[alp][cop] < INF)
		return check[alp][cop];

	int& result = check[alp][cop];

	// 알고리즘 공부
	if (alp < targetAlp)
	{
		int alResult = Check(alp + 1, cop) + 1;

		result = Smaller(result, alResult);
	}

	// 코딩 공부
	if (cop < targetCop)
	{
		int coResult = Check(alp, cop + 1) + 1;

		result = Smaller(result, coResult);
	}

	// 문제 풀기
	for (int i = 0; i < allProblems.size(); ++i)
	{
		vector<int> problem = allProblems[i];

		int alpReq = problem[0];
		int copReq = problem[1];
		int alpReward = problem[2];
		int copReward = problem[3];
		int timeCost = problem[4];

		if (alp >= alpReq && cop >= copReq)
		{
			int levelupAlp = alp + alpReward >= targetAlp ? targetAlp : alp + alpReward;
			int levelupCop = cop + copReward >= targetCop ? targetCop : cop + copReward;
			int problemResult = Check(levelupAlp, levelupCop) + timeCost;

			result = Smaller(result, problemResult);
		}
	}

	return result;
}

int solution(int alp, int cop, vector<vector<int>> problems)
{
	for (int a = 0; a < MAX; ++a)
	{
		for (int b = 0; b < MAX; ++b)
			check[a][b] = INF;
	}

	for (int i = 0; i < problems.size(); ++i)
	{	
		// alp 요구치, cop 요구치, alp 보상, cop 보상, 걸리는 시간
		vector<int> problem = problems[i];

		allProblems.push_back(problem);

		int alpReq = problem[0];
		int copReq = problem[1];

		if (targetAlp < alpReq)
			targetAlp = alpReq;
		
		if (targetCop < copReq)
			targetCop = copReq;
	}

	int answer = Check(alp, cop);

	return answer;
}


/*
#define MAX 151
#define INF 987654321

int reqAlp, reqCop;
int record[MAX][MAX];
vector<vector<int>> problemss;

void Init()
{
    reqAlp = 0, reqCop = 0;
    problemss.clear();

    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < MAX; ++b)
            record[a][b] = INF;
    }
}

int Smaller(int a, int b)
{
    return a < b ? a : b;
}

int Check(int alp, int cop)
{
    if (record[alp][cop] < INF)
        return record[alp][cop];

    if (alp >= reqAlp && cop >= reqCop)
        return 0;

    int& curRecord = record[alp][cop];
    
    if (alp < 150)
        curRecord = Smaller(curRecord, Check(alp + 1, cop) + 1);

    if (cop < 150)
        curRecord = Smaller(curRecord, Check(alp, cop + 1) + 1);

    for (int p = 0; p < problemss.size(); ++p)
    {
        vector<int> problem = problemss[p];

        int curReqAlp = problem[0];
        int curReqCop = problem[1];
        int rwdAlp = problem[2];
        int rwdCop = problem[3];
        int cost = problem[4];

        if (alp >= curReqAlp && cop >= curReqCop)
        {
            int nxtAlp = alp + rwdAlp;
            int nxtCop = cop + rwdCop;

            if (nxtAlp >= 150)
                nxtAlp = 150;
            if (nxtCop >= 150)
                nxtCop = 150;

            curRecord = Smaller(curRecord, Check(nxtAlp, nxtCop) + cost);
        }
    }

    return curRecord;
}

int solution(int alp, int cop, vector<vector<int>> problems)
{
    Init();
    
    problemss = problems;
    
    for (int p = 0; p < problems.size(); ++p)
    {
        vector<int> problem = problems[p];
        int curReqAlp = problem[0];
        int curReqCop = problem[1];

        if (reqAlp < curReqAlp)
            reqAlp = curReqAlp;
        if (reqCop < curReqCop)
            reqCop = curReqCop;
    }

    int answer = Check(alp, cop);

    return answer;
}
*/
/*
#define MAX 151
#define INF 987654321

int targetAlp, targetCop;
int dp[MAX][MAX];
pair<pair<int, int>, int> record[MAX][MAX];
vector<vector<int>> tempProblems;

int Smaller(int a, int b)
{
    return a < b ? a : b;
}

int Check(int alp, int cop)
{
    if (alp >= targetAlp && cop >= targetCop)
        return 0;

    if (dp[alp][cop] < INF)
        return dp[alp][cop];

    int& curDp = dp[alp][cop];

    if (alp < targetAlp)
        curDp = Smaller(curDp, Check(alp + 1, cop) + 1);

    if (cop < targetCop)
        curDp = Smaller(curDp, Check(alp, cop + 1) + 1);

    for (int i = 0; i < tempProblems.size(); ++i)
    {
        vector<int> problem = tempProblems[i];

        int reqAlp = problem[0];
        int reqCop = problem[1];
        int rwdAlp = problem[2];
        int rwdCop = problem[3];
        int cost = problem[4];

        if (alp >= reqAlp && cop >= reqCop)
        {
            int nxtAlp = alp + rwdAlp >= MAX ? MAX - 1 : alp + rwdAlp;
            int nxtCop = cop + rwdCop >= MAX ? MAX - 1 : cop + rwdCop;

            curDp = Smaller(curDp, Check(nxtAlp, nxtCop) + cost);
        }
    }

    return curDp;
}

int solution(int alp, int cop, vector<vector<int>> problems)
{
    tempProblems = problems;
    targetAlp = 0;
    targetCop = 0;

    for (int i = 0; i < problems.size(); ++i)
    {
        vector<int> problem = problems[i];

        int requiredAlp = problem[0];
        int requiredCop = problem[1];

        if (targetAlp < requiredAlp)
            targetAlp = requiredAlp;

        if (targetCop < requiredCop)
            targetCop = requiredCop;
    }

    for (int a = 0; a < MAX; ++a)
    {
        for (int b = 0; b < MAX; ++b)
            dp[a][b] = INF;
    }

    int answer = Check(alp, cop);


    return answer;
}
*/