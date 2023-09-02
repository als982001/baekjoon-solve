#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 9
using namespace std;

int answer = 0;
bool checked[MAX];
vector<string> checkIds;
vector<string> userIds;
vector<string> bannedIds;
map<vector<string>, bool> answerCheck;

bool Match(string userId, string bannedId)
{
    if (userId.length() != bannedId.length())
        return false;
    
    for (int i = 0; i < userId.length(); ++i)
    {
        if (bannedId[i] == '*')
            continue;
        
        if (userId[i] != bannedId[i])
            return false;
    }
    
    return true;
}

void Check(int idx)
{
    if (idx >= bannedIds.size())
    {
        vector<string> result = checkIds;
        
        sort(result.begin(), result.end());
        
        if (answerCheck[result] == false)
        {
            answerCheck[result] = true;
            ++answer;
        }
        
        return;
    }
    
    string bannedId = bannedIds[idx];
    
    for (int i = 0; i < userIds.size(); ++i)
    {
        if (checked[i] == false)
        {
            string userId = userIds[i];
        
            if (Match(userId, bannedId) == true)
            {
                checked[i] = true;
                checkIds.push_back(userId);

                Check(idx + 1);

                checkIds.pop_back();
                checked[i] = false;
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