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