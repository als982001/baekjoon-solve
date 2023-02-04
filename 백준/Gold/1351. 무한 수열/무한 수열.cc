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
using namespace std;

map<long long, long long> dp;
long long N, P, Q;

long long Solve(long long idx)
{
	if (idx == 0)
		return 1;

	if (dp[idx] > 0)
		return dp[idx];

	long long firstIdx = idx / P;
	long long secondIdx = idx / Q;

	dp[idx] = Solve(firstIdx) + Solve(secondIdx);

	return dp[idx];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	dp[0] = 1;

	cin >> N >> P >> Q;

	long long answer = Solve(N);

	cout << answer << endl;	

	return 0;
}