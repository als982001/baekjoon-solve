#include <iostream>
#include <string>
#include <sstream>
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

#define TOLOWER 32

string sentence;
vector<int> answer;

bool IsVowel(char alp)
{
	if ('A' <= alp && alp <= 'Z')
		alp += TOLOWER;
	return (alp == 'a' || alp == 'e' || alp == 'i' | alp == 'o' || alp == 'u');
}

int VowelNum(string s)
{
	int count = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		if (IsVowel(s[i]))
			++count;
	}

	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	getline(cin, sentence);

	while(sentence != "#")
	{
		int vowelNum = VowelNum(sentence);
		answer.push_back(vowelNum);

		getline(cin, sentence);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

    return 0;
}
