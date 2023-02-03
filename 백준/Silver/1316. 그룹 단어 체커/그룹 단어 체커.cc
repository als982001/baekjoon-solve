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

#define MAX 101

bool Check(string word)
{
	
	bool check[30] = { false, };
	memset(check, false, sizeof(check));

	char befAlp = word[0];
	check[befAlp - 'a'] = true;

	for (int i = 1; i < word.size(); ++i)
	{
		if (word[i] != befAlp)
		{
			if (check[word[i] - 'a'] == true)
				return false;
			
			befAlp = word[i];
			check[befAlp - 'a'] = true;
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int wordNum, count = 0;
	string word;

	cin >> wordNum; 

	while (wordNum--)
	{
		cin >> word;
		
		if (Check(word))
			++count;
	}

	cout << count << endl;

	return 0;
}