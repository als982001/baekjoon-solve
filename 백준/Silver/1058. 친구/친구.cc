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
// #include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 51

int N;
int answer = 0;
bool isFriend[MAX];
vector<int> friends[MAX];

int CheckFriend(int person)
{
	int count = 0;

	for (int i = 0; i < friends[person].size(); ++i)
	{
		int curFriend = friends[person][i];

		if (isFriend[curFriend] == false)
		{
			isFriend[curFriend] = true;
			++count;
		}
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int person = 1; person <= N; ++person)
	{
		string friendsList;
		cin >> friendsList;

		for (int i = 0; i < friendsList.size(); ++i)
		{
			if (friendsList[i] == 'Y')
			{
				friends[person].push_back(i + 1);
				friends[i + 1].push_back(person);
			}
		}
	}

	for (int person = 1; person <= N; ++person)
	{
		memset(isFriend, false, sizeof(isFriend));
		isFriend[person] = true;

		int count = 0;

		count += CheckFriend(person);

		for (int i = 0; i < friends[person].size(); ++i)
		{
			int curFriend = friends[person][i];
			count += CheckFriend(curFriend);
		}

		if (answer < count)
			answer = count;
	}

	cout << answer << endl;

	return 0;
}
