#include <string>
#include <vector>
#include <algorithm>
#define MAX 10
using namespace std;

int answer;
bool matched[MAX];
vector<string> userIds;
vector<string> bannedIds;
vector<string> matchingList;
vector<vector<string>> allMatchingList; 

bool Match(string id, string bannedId)
{
    if (id.size() != bannedId.size())
        return false;
    
    for (int i = 0; i < id.size(); ++i)
    {
        if (bannedId[i] == '*')
            continue;
        
        if (id[i] != bannedId[i])
            return false;
    }
    
    return true;
}

bool UniqueMatchingList()
{
    bool isUnique = true;
    
    vector<string> curMatchingList = matchingList;
    sort(curMatchingList.begin(), curMatchingList.end());
    
    for (int i = 0; i < allMatchingList.size(); ++i)
    {
        bool isSame = true;
        
        for (int k = 0; k < allMatchingList[i].size(); ++k)
        {
            if (allMatchingList[i][k] != curMatchingList[k])
            {
                isSame = false;
                break;
            }
        }
        
        if (isSame)
            return false;
    }
    
    allMatchingList.push_back(curMatchingList);
    
    return true;
}

void Check(int bannedIdx)
{
    if (bannedIdx >= bannedIds.size())
    {
        if (UniqueMatchingList() == true)
            ++answer;
        
        return;
    }
    
    for (int i = 0; i < userIds.size(); ++i)
    {
        if (matched[i] == false)
        {
            string userId = userIds[i];
            
            if (Match(userId, bannedIds[bannedIdx]) == true)
            {
                matched[i] = true;
                matchingList.push_back(userId);
                
                Check(bannedIdx + 1);
                
                matchingList.pop_back();
                matched[i] = false;
            }
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    
    userIds = user_id;
    bannedIds = banned_id;
    
    Check(0);
    
    return answer;
}

/*
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
*/