#include <string>
#include <vector>

using namespace std;

#define MAX 10

int answer = 0;
int initFatigue;
vector<vector<int>> allDungeons;
bool checked[MAX];
vector<int> dungeonIdxes;

void Check()
{
    if (dungeonIdxes.size() == allDungeons.size())
    {
        int fatigue = initFatigue;
        int dungeonCount = 0;
        
        for (int i = 0; i < dungeonIdxes.size(); ++i)
        {
            int dungeonIdx = dungeonIdxes[i];
            vector<int> dungeon = allDungeons[dungeonIdx];
            
            int minReqFatigue = dungeon[0];
            int consumedFatigue = dungeon[1];
            
            if (fatigue >= minReqFatigue)
            {
                fatigue -= consumedFatigue;
                ++dungeonCount;
            }
            else
                break;
        }
        
        if (answer < dungeonCount)
            answer = dungeonCount;
        
        return;
    }
    
    for (int i = 0; i < allDungeons.size(); ++i)
    {
        if (checked[i]  == false)
        {
            checked[i] = true;
            dungeonIdxes.push_back(i);
            
            Check();
            
            dungeonIdxes.pop_back();
            checked[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    initFatigue = k;
    allDungeons = dungeons;

    Check();
    
    return answer;
    
}