#include <string>
#include <vector>

using namespace std;

double discountRates[4] = { 0.1, 0.2, 0.3, 0.4 };

vector<vector<double>> userInfos;
vector<double> emoticonCosts;
double discounts[11];
vector<int> answer;

void Discount(int idx)
{
	if (idx >= emoticonCosts.size())
	{
		int memberNum = 0;
		double totalCost = 0;

		for (int u = 0; u < userInfos.size(); ++u)
		{
			vector<double> userInfo = userInfos[u];

			double userTotalCost = 0;

			for (int e = 0; e < emoticonCosts.size(); ++e)
			{
				double discountRate = discounts[e];
				double emoticonCost = emoticonCosts[e] * (1 - discountRate);

				if ((userInfo[0] * 0.01) <= discountRate)
					userTotalCost += emoticonCost;
			}

			if (userInfo[1] <= userTotalCost)
				++memberNum;
			else
				totalCost += userTotalCost;
		}


		if (answer[0] < memberNum)
		{
			answer[0] = memberNum;
			answer[1] = totalCost;
		}
		else if (answer[0] == memberNum)
		{
			if (answer[1] < totalCost)
			{
				answer[0] = memberNum;
				answer[1] = totalCost;
			}
		}

		return;
	}

	for (int rateIdx = 0; rateIdx < 4; ++rateIdx)
	{
		discounts[idx] = discountRates[rateIdx];
		Discount(idx + 1);
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) 
{
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

	Discount(0);

	return answer;
}


/*
vector<vector<int>> realUsers;
vector<double> emoticonsCosts;
vector<int> chosenRates;
pair<int, int> bestResult = { 0, 0 };

double discountRates[4] = { 0.1, 0.2, 0.3, 0.4 };

void Discount(int idx)
{
	if (idx >= emoticonsCosts.size())
	{
		vector<int> costs(realUsers.size(), 0);

		for (int i = 0; i < chosenRates.size(); ++i)
		{
			int rateIdx = chosenRates[i];
			double curRate = discountRates[rateIdx];
			double curCost = emoticonsCosts[i] * (1 - curRate);

			for (int i = 0; i < realUsers.size(); ++i)
			{
				double rateUserWant = (double)realUsers[i][0] / 100;
				
				if (curRate >= rateUserWant)
					costs[i] += curCost;
			}
			
		}

		int joinNum = 0;
		int totalCost = 0;

		for (int i = 0; i < realUsers.size(); ++i)
		{
			int costLimit = realUsers[i][1];

			if (costs[i] >= costLimit)
				++joinNum;
			else
				totalCost += costs[i];
		}

		if (bestResult.first < joinNum || (bestResult.first == joinNum && bestResult.second < totalCost))
			bestResult = { joinNum, totalCost };
		
		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		chosenRates.push_back(i);

		Discount(idx + 1);
		
		chosenRates.pop_back();
	}
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {    
    vector<int> answer;

	realUsers = users;
	for (int i = 0; i < emoticons.size(); ++i)
		emoticonsCosts.push_back(double(emoticons[i]));

	Discount(0);

	answer.push_back(bestResult.first);
	answer.push_back(bestResult.second);
    
    return answer;
}
*/