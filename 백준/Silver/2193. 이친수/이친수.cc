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

#define MAX 91

int N;
long long answer;
long long dp[MAX][2];

long long Check(int num, int startNum)
{
	if (dp[num][startNum] >= 0)
		return dp[num][startNum];
	
	long long& currentDp = dp[num][startNum];
	currentDp = 0;

	if (startNum == 0)
		currentDp += Check(num - 1, 0) + Check(num - 1, 1);
	else if (startNum == 1)
		currentDp += Check(num - 1, 0);

	return currentDp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	memset(dp, -1, sizeof(dp));
	dp[2][0] = 2, dp[2][1] = 1;
	dp[3][0] = dp[2][0] + dp[2][1], dp[3][1] = dp[2][0];
	dp[4][0] = dp[3][0] + dp[3][1], dp[4][1] = dp[3][0];

	cin >> N;

	switch(N)
	{
		case 1:
		case 2:
			answer = 1;
			break;
		case 3:
			answer = 2;
			break;
		case 4:
			answer = 3;
			break;
		default:
			answer = Check(N - 2, 0) + Check(N - 2, 1);
			break;
	}
	
	cout << answer << endl;

	return 0;
}
