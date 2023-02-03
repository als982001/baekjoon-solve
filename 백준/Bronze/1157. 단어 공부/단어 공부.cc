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

using namespace std;
#define SIZE 2

int Char_To_Int(char c)
{
	if ('A' <= c && c <= 'Z')
		return c - 'A';
	
	if ('a' <= c && c <= 'z')
		return c - 'a';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int maxNum = 0;
	string str;
	int counts[26] = { 0 };
	
	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		int c = Char_To_Int(str[i]);

		++counts[c];

		if (maxNum < counts[c])
			maxNum = counts[c];
	}

	char answer = '?';

	for (int i = 0; i < 26; ++i)
	{
		if (counts[i] == maxNum)
		{
			if (answer != '?')
			{
				answer = '?';
				break;
			}
			else
				answer = i + 'A';
		}
	}

	cout << answer << endl;

	return 0;
}