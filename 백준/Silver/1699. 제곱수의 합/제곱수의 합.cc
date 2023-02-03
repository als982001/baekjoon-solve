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

#define MAX 100011

int N;
int dp[MAX];

int Small(int a, int b)
{
	return a < b ? a : b;
}

int Check(int num)
{
	if (num == 1)
		return 1;

	if (dp[num] >= 0)
		return dp[num];
	
	int& result = dp[num];
	result = num;

	for (int i = 1; (i * i) <= num; ++i)
	{
		int squareNum = i * i;	
		
		result = Small(result, Check(num - squareNum) + 1);
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	memset(dp, -1, sizeof(dp));

	cin >> N;

	int answer = Check(N);

	cout << answer << endl;	
	
	return 0;
}
