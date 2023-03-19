#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 8

typedef struct
{
	int person1;
	int person2;
	char type;
	int distance;
} Condition;

int answer = 0;
bool checked[MAX];
int personPos[MAX];
vector<int> line;
vector<Condition> conditions;
map<char, int> personIdx;

void Check()
{
	if (line.size() >= MAX)
	{
		bool success = true;

		for (int i = 0; i < line.size(); ++i)
		{
			int curPerson = line[i];
			personPos[curPerson] = i;
		}

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

			if (success == false)
				return;
		}
		
		++answer;
		return;
	}

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

	Check();

	return answer;
}


/*
using namespace std;

int lineNum;
bool check[8];
vector<int> line;
vector<string> datas;
map<char, int> characterNum;

void Line_Up(int cnt)
{
    if (cnt == 8)
    {
        for (int dataIdx = 0; dataIdx < datas.size(); ++dataIdx)
        {
            string curData = datas[dataIdx];

            int curChar1 = characterNum[curData[0]];
            int curChar2 = characterNum[curData[2]];
            int between = curData[4] - '0' + 1;
            
            int curChar1Pos = 0, curChar2Pos = 0;

            for (int i = 0; i < line.size(); ++i)
            {
                if (line[i] == curChar1)
                    curChar1Pos = i;
                else if (line[i] == curChar2)
                    curChar2Pos = i;
            }

            switch (curData[3])
            {
                case '=':
                {
                    if (abs(curChar1Pos - curChar2Pos) != between)
                        return;
                    break;
                }
                case '>':
                {
                    if (abs(curChar1Pos - curChar2Pos) <= between)
                        return;
                    break;
                }
                case '<':
                {
                    if (abs(curChar1Pos - curChar2Pos) >= between)
                        return;
                    break;
                }
            }
        }

        ++lineNum;

        return;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            line.push_back(i);

            Line_Up(cnt + 1);
            
            line.pop_back();
            check[i] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;

    lineNum = 0;
    for (int i = 0; i < 8; ++i)
        check[i] = false;
    line.clear();
    datas.clear();
    characterNum.clear();


    datas = data;

    characterNum['A'] = 0;
    characterNum['C'] = 1;
    characterNum['F'] = 2;
    characterNum['J'] = 3;
    characterNum['M'] = 4;
    characterNum['N'] = 5;
    characterNum['R'] = 6;
    characterNum['T'] = 7;

    Line_Up(0);

    answer = lineNum;

    return answer;
}
*/