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

#define MAX 501

int N, M;
int answer = 0;
bool invited[MAX];
vector<int> friends[MAX];

void Invite(int person)
{
	for (int i = 0; i < friends[person].size(); ++i)
	{
		int curFriend = friends[person][i];

		if (invited[curFriend] == false)
		{
			invited[curFriend] = true;
			++answer;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	invited[1] = true;
	Invite(1);

	for (int i = 0; i < friends[1].size(); ++i)
	{
		int curFriend = friends[1][i];

		Invite(curFriend);
	}

	cout << answer << endl;

	return 0;
}
