#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 32001

int studentNum, comparisonNum;
int inDegree[MAX];
vector<int> nexts[MAX];
vector<int> line;

void MakeLine()
{
	queue<int> q;
	
	for (int student = 1; student <= studentNum; ++student)
	{
		if (inDegree[student] == 0)
			q.push(student);
	}

	for (int t = 0; t < studentNum; ++t)
	{
		int student = q.front();
		q.pop();

		line.push_back(student);

		for (int i = 0; i < nexts[student].size(); ++i)
		{
			int nxtStudent = nexts[student][i];

			--inDegree[nxtStudent];

			if (inDegree[nxtStudent] == 0)
				q.push(nxtStudent);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> studentNum >> comparisonNum;

	for (int i = 0; i < comparisonNum; ++i)
	{
		int frontStudent, backStudent;
		cin >> frontStudent >> backStudent;

		inDegree[backStudent]++;
		nexts[frontStudent].push_back(backStudent);
	}

	MakeLine();

	for (int i = 0; i < line.size(); ++i)
		cout << line[i] << " ";
	
	return 0;
}
