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

#define MAX 1001
#define INF 987654321

int N;
int prices[MAX];
int dp[MAX];

int Check(int cardNum)
{
	if (cardNum == 0) 
		return 0;
	
	if (dp[cardNum] < INF)
		return dp[cardNum];

	int& curDp = dp[cardNum];

	for (int nxtCardNum = 1; nxtCardNum <= cardNum; ++nxtCardNum)
		curDp = min(curDp, Check(cardNum - nxtCardNum) + prices[nxtCardNum]);

	return curDp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; ++n)
	{
		cin >> prices[n];
		dp[n] = INF;
	}

	int answer = Check(N);

	cout << answer << endl;

    return 0;
}
