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

#define MAX 1000011
#define MOD 1000000009

int caseNum;
int n;
long long dp[MAX];

long long Check(int num)
{
	if (dp[num] >= 0)
		return dp[num];

	long long& current = dp[num];
	current = 0;

	for (int part = 1; part <= 3; ++part)
	{
		current += Check(num - part);
		current %= MOD;
	}
    
	return current;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	memset(dp, -1, sizeof(dp));

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	cin >> caseNum;

	while (caseNum--)
	{
		cin >> n;

		cout << Check(n) << endl;
	}
	
	return 0;
}