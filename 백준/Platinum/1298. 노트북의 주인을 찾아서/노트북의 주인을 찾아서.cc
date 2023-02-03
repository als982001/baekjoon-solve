#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define CASE 3
#define MAX 101

int answer;
int personNum, anticipationNum;
bool matched[MAX];
int owner[MAX];
vector<int> lists[MAX];

bool Match(int person)
{
	for (int i = 0; i < lists[person].size(); ++i)
	{
		int laptop = lists[person][i];

		if (matched[laptop])
			continue;
		matched[laptop] = true;

		if (owner[laptop] == 0 || Match(owner[laptop]))
		{
			owner[laptop] = person;

				return true;
		}
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> personNum >> anticipationNum;

	for (int a = 0; a < anticipationNum; ++a)
	{
		int person, laptop;
		cin >> person >> laptop;

		lists[person].push_back(laptop);
	}

	for (int person = 1; person <= personNum; ++person)
	{
		memset(matched, false, sizeof(matched));

		if (Match(person) == true)
			++answer;
	}

	cout << answer << endl;

	return 0;
}