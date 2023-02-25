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

/*
#define MAX 10

int answer;
int userNum, bannedNum;
bool selected[MAX];
int selectIdx[MAX];
vector<string> userId, bannedId;
vector<vector<string>> matchedList;

bool CanMatch(string user, string banned)
{
    if (user.size() != banned.size())
        return false;

    for (int i = 0; i < user.size(); ++i)
    {
        if (banned[i] == '*')
            continue;

        if (user[i] != banned[i])
            return false;
    }

    return true;
}

bool AlreadyExistingResult(vector<string> matched)
{
    for (int m = 0; m < matchedList.size(); ++m)
    {
        vector<string> curResult = matchedList[m];

        bool equal = true;

        for (int i = 0; i < matched.size(); ++i)
        {
            if (curResult[i] != matched[i])
            {
                equal = false;
                break;
            }
        }

        if (equal == true)
            return true;
    }

    return false;
}

bool Match()
{
    bool success = true;
    vector<string> matched;

    for (int b = 0; b < bannedNum; ++b)
    {
        if (selectIdx[b] >= 0)
        {
            int userIdx = selectIdx[b];

            string banned = bannedId[b];
            string user = userId[userIdx];

            if (CanMatch(user, banned) == false)
                return false;

            matched.push_back(user);
        }
    }

    sort(matched.begin(), matched.end());
    if (AlreadyExistingResult(matched))
        return false;

    matchedList.push_back(matched);

    return true;
}

void Select(int banIdx)
{
    if (banIdx >= bannedNum)
    {
       bool success = Match();

        if (success == true)
            ++answer;

        return;
    }

    for (int u = 0; u < userNum; ++u)
    {
        if (selected[u] == false)
        {
            selected[u] = true;
            selectIdx[banIdx] = u;

            Select(banIdx + 1);

            selectIdx[banIdx] = -1;
            selected[u] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    userNum = user_id.size();
    bannedNum = banned_id.size();

    userId = user_id;
    bannedId = banned_id;

    Select(0);

    return answer;
}
*/
/*
int ans;
bool check[10];
int match[10][10];      // 1이면 가능, -1이면 불가능
vector<string> user;
vector<string> ban;
vector<int> tmpList;
vector<vector<int>> idList;

int Match_Check(int userIdx, int banIdx)
{
    if (match[userIdx][banIdx] != 0)
    {
        return match[userIdx][banIdx];
    }

    string userId = user[userIdx];
    string banId = ban[banIdx];

    if (userId.size() != banId.size())
    {
        match[userIdx][banIdx] = -1;
        return  -1;
    }

    for (int i = 0; i < userId.size(); ++i)
    {
        if (banId[i] == '*')
            continue;

        if (userId[i] != banId[i])
        {
            match[userIdx][banIdx] = -1;
            return -1;
        }
    }
    
    match[userIdx][banIdx] = 1;
    return 1;
}

bool Is_Overlap(vector<int> tmp)
{
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < idList.size(); ++i)
    {
        vector<int> curList = idList[i];

        bool equal = true;

        for (int k = 0; k < tmp.size(); ++k)
        {
            if (tmp[k] != curList[k])
            {
                equal = false;
                break;
            }
        }

        if (equal)
            return true;
    }

    idList.push_back(tmp);
    return false;
}

void Solve(int userIdx, int banIdx)
{
    if (banIdx >= ban.size())
    {
        if (!Is_Overlap(tmpList))
            ++ans;

        return;
    }

    for (int i = 0; i < user.size(); ++i)
    {
        
        if (!check[i] && (Match_Check(i, banIdx) == 1))
        {
            check[i] = true;
            tmpList.push_back(i);

            Solve(i, banIdx + 1);

            tmpList.pop_back();
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    user = user_id;
    ban = banned_id;

    for (int r = 0; r < 10; ++r)
    {
        for (int c = 0; c < 10; ++c)
            match[r][c] = 0;
    }

    Solve(0, 0);

    answer = ans;

    return answer;
}


int answer;
int userNum;
int bannedNum;
bool check[10];
bool banCheck[10];
vector<string> userIds;
vector<string> bannedIds;
vector<int> idxes;
vector<int> banIdxes;
vector<vector<string>> matcheds;

bool Match_Ids(string user, string banned)
{
	if (user.size() != banned.size())
		return false;

	int len = user.size();

	for (int i = 0; i < len; ++i)
	{
		if (banned[i] == '*')
			continue;

		if (user[i] != banned[i])
			return false;
	}

	return true;
}

bool Check_Ids()
{
	vector<string> curMatched;

	for (int i = 0; i < idxes.size(); ++i)
	{
		int banIdx = banIdxes[i];
		string bannedId = bannedIds[banIdx];

		int idx = idxes[i];
		string userId = userIds[idx];

		if (Match_Ids(userId, bannedId) == false)
			return false;

		curMatched.push_back(userId);
	}

	sort(curMatched.begin(), curMatched.end());

	for (int i = 0; i < matcheds.size(); ++i)
	{
		bool isEqual = true;
		vector<string> matched = matcheds[i];

		for (int m = 0; m < matched.size(); ++m)
		{
			if (matched[m] != curMatched[m])
			{
				isEqual = false;
				break;
			}
		}

		if (isEqual)
			return false;
	}

	matcheds.push_back(curMatched);
	return true;
}

void DFS(int idx, int cnt)
{
	if (cnt == bannedNum)
	{
		bool result = Check_Ids();

		if (result == true)
			++answer;
	}

	for(int i=idx;i<userNum;++i)
	{
		if (check[i] == false)
		{
			check[i] = true;
			idxes.push_back(i);

			DFS(i + 1, cnt + 1);

			check[i] = false;
			idxes.pop_back();
		}
	}
}

void Mix_Orders(int cnt)
{
	if (cnt == bannedNum)
	{	
		DFS(0, 0);

		return;
	}

	for (int i = 0; i < bannedNum; ++i)
	{
		if (banCheck[i] == false)
		{
			banCheck[i] = true;
			banIdxes.push_back(i);

			Mix_Orders(cnt + 1);

			banCheck[i] = false;
			banIdxes.pop_back();
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id)
{
	answer = 0;
	userNum = user_id.size();
	bannedNum = banned_id.size();

	userIds = user_id;
	bannedIds = banned_id;

	idxes.clear();
	banIdxes.clear();
	matcheds.clear();

	Mix_Orders(0);

	return answer;
}
*/

