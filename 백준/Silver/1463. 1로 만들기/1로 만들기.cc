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
#define MAX 1000010

int X, answer = MAX;
int dp[MAX];

int Smaller(int a, int b)
{
	return a < b ? a : b;
}

int Check(int num)
{
	if (num == 1)
		return 0;

	if (dp[num] > 0)
		return dp[num];

	dp[num] = MAX;
	int& curDp = dp[num];

	if (num % 3 == 0)
		curDp = Smaller(curDp, Check(num / 3) + 1);

	if (num % 2 == 0)
		curDp = Smaller(curDp, Check(num / 2) + 1);

	curDp = Smaller(curDp, Check(num - 1) + 1);

	return curDp;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	for (int i = 0; i < MAX; ++i)
		dp[i] = -1;

	cin >> X;

	int answer = Check(X);

	cout << answer << endl;


	return 0;
}