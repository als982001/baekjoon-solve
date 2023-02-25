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

int N;
int prices[MAX];
int dp[MAX];

int Max(int a, int b)
{
	return a > b ? a : b;
}

int Check(int cardNum)
{
	if (cardNum == 0)
		return 0;
	if (dp[cardNum] >= 0) 	
		return dp[cardNum];

	int& curDp = dp[cardNum];
	curDp = 0;

	curDp = Check(cardNum - 1) + prices[1];

	for (int n = 2; n <= cardNum; ++n)
		curDp = Max(curDp, Check(cardNum - n) + prices[n]);

	return curDp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> N;
    
	for (int n = 1; n <= N; ++n)
		cin >> prices[n];

	for (int i = 0; i < MAX; ++i)
		dp[i] = -1;

	int answer = Check(N);

	cout << answer << endl;
	
	return 0;
}

