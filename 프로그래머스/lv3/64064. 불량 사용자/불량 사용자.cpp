#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10

vector<string> userIds;
vector<string> bannedIds;
vector<int> bannedList;
vector<vector<int>> allBannedLists;
bool isMatched[MAX];

bool CanMatch(int userIdx, int banIdx)
{
	string userId = userIds[userIdx];
	string bannedId = bannedIds[banIdx];

	if (userId.size() != bannedId.size())
		return false;
	
	for (int i = 0; i < userId.size(); ++i)
	{
		if (bannedId[i] == '*')
			continue;
		if (userId[i] != bannedId[i])
			return false;
	}

	return true;
}

bool Banned(vector<int> curBannedList)
{
	for (int i = 0; i < allBannedLists.size(); ++i)
	{
		bool isEqual = true;
		
		for (int k = 0; k < curBannedList.size(); ++k)
		{
			if (curBannedList[k] != allBannedLists[i][k])
			{
				isEqual = false;
				break;
			}
		}

		if (isEqual)
			return true;
	}

	return false;
}

void Match(int banIdx)
{
	if (banIdx >= bannedIds.size())
	{
		vector<int> curBannedList = bannedList;
		sort(curBannedList.begin(), curBannedList.end());

		if (Banned(curBannedList) == false)
			allBannedLists.push_back(curBannedList);
	
		return;
	}

	for (int userIdx = 0; userIdx < userIds.size(); ++userIdx)
	{
		if (isMatched[userIdx] == false)
		{
			if (CanMatch(userIdx, banIdx))
			{
				isMatched[userIdx] = true;
				bannedList.push_back(userIdx);

				Match(banIdx + 1);
				
				bannedList.pop_back();
				isMatched[userIdx] = false;
			}
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{	
	userIds = user_id;
	bannedIds = banned_id;

	Match(0);
	
	return allBannedLists.size();
}