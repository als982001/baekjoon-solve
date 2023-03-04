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

#define PI 3.141592

int skillLevel[4];

int answer = 987654321;

vector<int> teamCases[3] = { { 0, 1, 2, 3 }, { 0, 2, 1, 3 }, { 0, 3, 1, 2 } };

int Diff(int a, int b)
{
	if (a > b)
		return a - b;
	else
		return b - a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> skillLevel[0] >> skillLevel[1] >> skillLevel[2] >> skillLevel[3];

	for (int i = 0; i < 3; ++i)
	{
		int diff = Diff(skillLevel[teamCases[i][0]] + skillLevel[teamCases[i][1]], skillLevel[teamCases[i][2]] + skillLevel[teamCases[i][3]]);

		answer = answer > diff ? diff : answer;
	}
	
	cout << answer << endl;

	return 0;
}
