#include <string>
#include <vector>
#include <map>

using namespace std;

int numberOfTypes = 0;
vector<string> gemTypes;
map<string, int> numberOfGem;

vector<int> solution(vector<string> gems) {
    
    vector<int> answer;
    
    for (int i = 0; i < gems.size(); ++i)
    {
        string gem = gems[i];
        
        if (numberOfGem[gem] == 0)
        {
            gemTypes.push_back(gem);
            ++numberOfTypes;
        }
        
        ++numberOfGem[gem];
    }
    
    int start = 0;
    int end = 0;
    int currentNumberOfTypes = 0;
    map<string, int> currentNumberOfGem;
    
    while(currentNumberOfTypes < numberOfTypes)
    {
        string gem = gems[end];
        
        if (currentNumberOfGem[gem] == 0)
            ++currentNumberOfTypes;
        ++currentNumberOfGem[gem];

        ++end;
    }
    --end;
    
    answer.push_back(start);
    answer.push_back(end);
    
    while(end < gems.size())
    {
        string removedGem = gems[start];
        ++start;
        --currentNumberOfGem[removedGem];
        
        if (currentNumberOfGem[removedGem] == 0)
        {
            --currentNumberOfTypes;
            ++end;
            
            while(end < gems.size() && currentNumberOfTypes < numberOfTypes)
            {
                string newGem = gems[end];
                
                if (currentNumberOfGem[newGem] == 0)
                    ++currentNumberOfTypes;
                ++currentNumberOfGem[newGem];
                
                ++end;
            }
            
            if (currentNumberOfTypes < numberOfTypes)
                break;
            else
                --end;
        }
        else
        {
            if (answer[1] - answer[0] > end - start)
            {
                answer[0] = start;
                answer[1] = end;
            }
        }
    
    }
    
    return { answer[0] + 1, answer[1] + 1 };
}

/*
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int typeNum = 0;				// 보석의 총 몇 종류인지 기록
int currentTypeNum = 0;			// (나중에 실행할) 반복문에서, 소지하고 있는 보석의 종류 수
map<string, int> gemsInfo;	// 시작할 때 주어진 보석의 개수
map<string, int> gemsNum;	// (나중에 실행할) 반복문에서, 소지하고 있는 보석 각각의 개수


int Length(int end, int start)
{
	return end - start + 1;
}

vector<int> solution(vector<string> gems)
{
	vector<int> answer(2, 0);

	// 1. 보석의 정보를 기록한다.
	for (int i = 0; i <gems.size(); ++i)
	{
		string gem = gems[i];

		if (gemsInfo[gem] == 0)
			++typeNum;

		++gemsInfo[gem];
	}

	// 2. (C++ 기준) 0번부터 모든 보석을 가질 수 있는 인덱스를 구한다.
	int left = 0, right = 0;

	while(right < gems.size() && currentTypeNum < typeNum)
	{
		if (gemsNum[gems[right]] == 0)
			++currentTypeNum;
		++gemsNum[gems[right]];
		++right;	
	}
	--right;

	// 2-1. 이 때의 값을 일단 answer에 기록한다.
	answer[0] = left + 1;
	answer[1] = right + 1;

	// 3. 최소 길이를 찾기 위해 반복문을 이용한다.
	while(left <= right && right < gems.size())
	{
		// 3-1. 왼쪽 보석을 하나 제거한다.
		string removedGem = gems[left];
		++left;
		--gemsNum[removedGem];

		if (gemsNum[removedGem] == 0)
			--currentTypeNum;

		if (currentTypeNum < typeNum)
		{
			// 3-2. 만약 보석의 종류가 줄었다면, 오른쪽으로 하나씩 늘려간다.
			
			++right;
			while(right < gems.size() && currentTypeNum < typeNum)
			{
				string addedGem = gems[right];

				// 만약 추가된 부석이 현재 가지고 있지 않던 보석이라면
				// 현재 보석의 종류를 +1 한다.
				if (gemsNum[addedGem] == 0)
					++currentTypeNum;

				++gemsNum[addedGem];
				++right;
			}
			--right;

			// 3-2-1. 만약 다시 보석의 종류가 복구되었다면, 
			// 답을 갱신할 수 있으면 갱신한다.
			if (currentTypeNum == typeNum)
			{
				if (Length(answer[1], answer[0]) > Length(right, left))
				{
					answer[0] = left + 1;
					answer[1] = right + 1;
				}
			}
		}
		else
		{
			// 3-3. 만약 보석의 종류가 줄어들지 않았다면,
			// 답을 갱신할 수 있는 경우에는 갱신한다.

			if (Length(answer[1], answer[0]) > Length(right, left))
			{
				answer[0] = left + 1;
				answer[1] = right + 1;
			}
		}

	}

	// 4. 답을 반환한다.
	return answer;
}
*/