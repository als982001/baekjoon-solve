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

string word;
int answer = 0;

bool IsVowel(char alp)
{
	return alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u';
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> word;

	for (int i = 0; i < word.size(); ++i)
	{
		if (IsVowel(word[i]))
			++answer;
	}

	cout << answer << endl;

    return 0;
}
