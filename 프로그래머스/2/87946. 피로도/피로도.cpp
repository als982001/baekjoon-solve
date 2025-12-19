#include <string>
#include <vector>

using namespace std;

int answer = -1;
bool isChecked[8];

void Check(vector<vector<int>>& dungeons, vector<int>& dungeonsOrder, int dungeonsNum, int k)
{
    if (dungeonsOrder.size() == dungeonsNum)
    {
        bool success = true;
        int fatigue = k;
        
        for (int idx : dungeonsOrder)
        {
            vector<int> dungeon = dungeons[idx];
            
            int minReq = dungeon[0];
            int consumedFatigue = dungeon[1];
            
            if (minReq > fatigue)
            {
                success = false;
                break;
            }
            
            fatigue -= consumedFatigue;
        }
        
        if (success)
            answer = dungeonsNum;
        
        return;
    }
    
    for (int idx = 0; idx < dungeons.size(); ++idx)
    {
        if (isChecked[idx] == false)
        {
            isChecked[idx] = true;
            dungeonsOrder.push_back(idx);
            
            Check(dungeons, dungeonsOrder, dungeonsNum, k);
            
            dungeonsOrder.pop_back();
            isChecked[idx] = false;
            
        }
    }
}
    
int solution(int k, vector<vector<int>> dungeons) {
    vector<int> dungeonsOrder;
    
    for (int dungeonsNum = dungeons.size(); dungeonsNum > 0; --dungeonsNum)
    {
        Check(dungeons, dungeonsOrder, dungeonsNum, k);
        
        if (answer != -1)
            break;
    }
    
    if (answer == -1)
        answer = 0;
    
    return answer;
}