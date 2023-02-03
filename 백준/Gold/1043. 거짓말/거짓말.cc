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
#define MAX 51

int N, M;
int knowNum;
vector<int> knows;
int parentNode[MAX];
vector<vector<int>> partys;

int ParentNode(int n)
{
	if (parentNode[n] == n)
		return n;
	else
		return parentNode[n] = ParentNode(parentNode[n]);
}

bool IsSame(int a, int b)
{
	a = ParentNode(a);
	b = ParentNode(b);

	if (a == b)
		return true;
	else
		return false;
}

void MakeSame(int a, int b)
{
	a = ParentNode(a);
	b = ParentNode(b);

	if (a < b)
		parentNode[b] = a;
	else
		parentNode[a] = b;
}

void InputPartys()
{
	for (int m = 0; m < M; ++m)
	{
		int partyPersonNum;
		vector<int> party;

		cin >> partyPersonNum;

		for (int p = 0; p < partyPersonNum; ++p)
		{
			int person;
			cin >> person;

			party.push_back(person);
		}

		partys.push_back(party);
	}
}

void CheckPartys()
{
	for (int i = 0; i < MAX; ++i)
		parentNode[i] = i;

	for (int p = 0; p < partys.size(); ++p)
	{
		vector<int> party = partys[p];

		int firstPerson = party[0];

		for (int idx = 1; idx < party.size(); ++idx)
		{
			int nxtPerson = party[idx];

			MakeSame(firstPerson, nxtPerson);
		}

	}
}

int MakeAnswer()
{
	int count = 0;

	for (int p = 0; p < partys.size(); ++p)
	{
		vector<int> party = partys[p];
		bool dangerous = false;

		for (int idx = 0; dangerous == false && idx < party.size(); ++idx)
		{
			int person = party[idx];

			for (int k = 0; k < knows.size(); ++k)
			{
				int know = knows[k];

				if (IsSame(person, know))
				{
					dangerous = true;
					break;
				}
			}
		}

		if (dangerous == false)
			++count;
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> N >> M;

	cin >> knowNum;
	for (int k = 0; k < knowNum; ++k)
	{
		int know;
		cin >> know;

		knows.push_back(know);
	}

	InputPartys();

	CheckPartys();

	int answer = MakeAnswer();

	cout << answer << endl;

	return 0;
}