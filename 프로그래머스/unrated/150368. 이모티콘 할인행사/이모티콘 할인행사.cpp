#include <string>
#include <vector>

using namespace std;

double discountRates[4] = { 0.1, 0.2, 0.3, 0.4 };	// 문제에서 주어진 할인율 4가지

vector<vector<double>> userInfos;	// 문제에서 주어진 유저 정보
vector<double> emoticonCosts;		// 문제에서 주어진 이모티콘 가격
double discounts[11];				// 첫 이모티콘부터 마지막 이모터콘까지의 할인율
vector<int> answer;					// 정답을 저장할 벡터

// 모든 이모티콘마다 할인율을 정해주는 함수
// idx: 이모티콘의 인덱스. 마지막 이모티콘의 idx는 이모티콘 길이 - 1이다.
void Discount(int idx)
{	
	// 2-2. 만약, 모든 이모티콘에 할인율을 적용하였다면, 
	// 몇 명이 가입할지, 판매액이 얼마일지를 계산한다.
	if (idx >= emoticonCosts.size())
	{
		int memberNum = 0;		// 이번 경우의 가입자 수
		double totalCost = 0;	// 이번 경우의 판매액

		// 2-2-1. 첫 번째 유저부터 마지막 유저까지 검사한다.
		for (int u = 0; u < userInfos.size(); ++u)
		{
			vector<double> userInfo = userInfos[u];

			double userTotalCost = 0;

			// 2-2-2. 만약 현재 이모티콘의 할인율과 할인한 금액을 유저 정보와 비교하여
			// 가입할지, 단순히 구매할지를 결정한다.
			for (int e = 0; e < emoticonCosts.size(); ++e)
			{
				double discountRate = discounts[e];
				double emoticonCost = emoticonCosts[e] * (1 - discountRate);

				// userInfo[0]에는 10, 20 등 %로 저장되어 있기 때문에 100을 나누어서 비교한다.
				if ((userInfo[0] * 0.01) <= discountRate)
					userTotalCost += emoticonCost;
			}

			// 만약 구매액이 일정 수치를 넘긴다면 가입자 수를 증가시키고 아니면 판매액을 증가시킨다.
			if (userInfo[1] <= userTotalCost)
				++memberNum;
			else
				totalCost += userTotalCost;
		}

		// 2-2-3. 만약 답을 갱신할 수 있는 상황이라면, 갱신한다.
		if (answer[0] < memberNum || (answer[0] == memberNum && answer[1] < totalCost))
		{
			answer[0] = memberNum;
			answer[1] = totalCost;
		}
	
		return;
	}

	// 2-1. 각 이모티콘마다 10%부터 40%까지 모든 할인율을 적용한다.
	for (int rateIdx = 0; rateIdx < 4; ++rateIdx)
	{
		discounts[idx] = discountRates[rateIdx];
		Discount(idx + 1);
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{	
	// 1. 문제를 풀기 위해 이용할 벼수, 배열 등을 세팅한다.
	// 주어진 값들은 int형인데, 할인율은 소수점이므로 
	// 계산하기 편하게 하기 위해 double로 바꿔서 전역으로 저장한다.
	answer = { -1, -1 };

	for (int i = 0; i < users.size(); ++i)
	{
		vector<double> user;

		user.push_back(users[i][0]);
		user.push_back(users[i][1]);

		userInfos.push_back(user);
	}

	for (int i = 0; i < emoticons.size(); ++i)
	{
		double cost = emoticons[i];
		emoticonCosts.push_back(cost);
	}

	// 2. 각 이모티콘모다 모든 할인율을 적용해서, 모든 경우의 수를 검사한다.
	Discount(0);

	return answer;
}
