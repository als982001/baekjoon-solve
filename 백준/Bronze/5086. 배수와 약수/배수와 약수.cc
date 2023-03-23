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

#define FACTOR "factor"
#define MULTIPLE "multiple"
#define NEITHER "neither"

int a, b;
vector<string> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> a >> b;

	while(a != 0 && b != 0)
	{
		if (a > b)
		{
			if (a % b == 0)
				answer.push_back(MULTIPLE);
			else
				answer.push_back(NEITHER);
		}
		else
		{
			if (b % a == 0)
				answer.push_back(FACTOR);
			else
				answer.push_back(NEITHER);
		}

		cin >> a >> b;
	}

	for (auto ans : answer)
		cout << ans << endl;

    return 0;
}
