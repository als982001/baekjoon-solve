#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 8

// 문제에서 주어지는 조건들의 타입형
typedef struct
{
	int person1;
	int person2;
	char type;
	int distance;
} Condition;

int answer = 0;		// 답을 젖아할 변수
bool checked[MAX];	// i번 사람이 줄을 섰는지를 저장할 변수
int personPos[MAX];	// i번 사람의 현재 줄 위치
vector<int> line;	// 사람들이 선 줄
vector<Condition> conditions;	// 주어진 조건들을 저장할 배열
map<char, int> personIdx;		// A 등의 사람 이름을 숫자로 바꾸기 위함

void Check()
{	
	// 2-2, 만약 모든 사람들이 줄을 섰다면, 이 줄으 기능한 줄인지 확인한다.
	if (line.size() >= MAX)	
	{	
		bool success = true;	// 현재 줄이 가능한 줄이라면 true

		// 2-2-1. 현재 각 사람들의 줄 위치를 저장한다.
		for (int i = 0; i < line.size(); ++i)
		{
			int curPerson = line[i];
			personPos[curPerson] = i;
		}

		// 2-2-2. 모든 조건들을 하나씩 검사하면서 가능한 줄인지 확인한다. 
		for (int i = 0; i < conditions.size(); ++i)
		{
			Condition condition = conditions[i];
			
			int person1Pos = personPos[condition.person1];
			int person2Pos = personPos[condition.person2];

			switch(condition.type)
			{
				case '=':
					if (abs(person1Pos - person2Pos) != condition.distance)
						success = false;
						break;
				case '>':
					if (abs(person1Pos - person2Pos) <= condition.distance)
						success = false;
						break;
				case '<':
					if (abs(person1Pos - person2Pos) >= condition.distance)
						success = false;
						break;
			}

			// 2-2-3. 만약 불가능한 줄이라면 return으로 빠져나간다.
			if (success == false)
				return;
		}
		
		// 2-2-4. 만약 가능한 줄이라면 답을 +1 한다.
		++answer;
		return;
	}
	
	// 2-1. 모든 사람들을 한 번씩 검사하면서, 줄을 서지 않았다면 줄을 세운다.
	for (int i = 0; i < MAX; ++i)
	{
		if (checked[i] == false)
		{
			checked[i] = true;
			line.push_back(i);

			Check();

			line.pop_back();
			checked[i] = false;
		}
	}
}

int solution(int n, vector<string> data) 
{	
	// 1. 전부 초기화한다.
	answer = 0;

	for (int i = 0; i < MAX; ++i)
	{
		checked[i] = false;
		personPos[i] = -1;
	}

	line.clear();
	conditions.clear();

	personIdx['A'] = 0;
	personIdx['C'] = 1;
	personIdx['F'] = 2;
	personIdx['J'] = 3;
	personIdx['M'] = 4;
	personIdx['N'] = 5;
	personIdx['R'] = 6;
	personIdx['T'] = 7;

	for (int i = 0; i < data.size(); ++i)
	{
		string curData = data[i];

		Condition condition;
		condition.person1 = personIdx[curData[0]];
		condition.person2 = personIdx[curData[2]];
		condition.type = curData[3];
		condition.distance = curData[4] - '0' + 1;

		conditions.push_back(condition);
	}

	// 2. 순열 개념을 이용해 줄을 세운 후, 줄이 세워졌을 때 검사한다. 
	Check();

	return answer;
}