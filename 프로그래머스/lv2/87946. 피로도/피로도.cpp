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

/*
#include <string>
#include <vector>

using namespace std;

#define MAX 10

vector<vector<int>> info;	// 최소 필요, 소모
bool check[MAX];
int answer = 0;
vector<int> order;

void DFS(int idx, int left, int count)
{
	for (int i = 0; i < info.size(); ++i)
	{
		if (!check[i])
		{
			if (left >= info[i][0])
			{
				check[i] = true;
				order.push_back(i);

				DFS(i + 1, left - info[i][1], count + 1);

				check[i] = false;
				order.pop_back();
			}
		}
	}

	if (answer < count)
		answer = count;

	return;
}

int solution(int k, vector<vector<int>> dungeons) {
    info = dungeons;

	DFS(0, k, 0);

	return answer;
}
*/