#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>
#define MAX 10011
using namespace std;

int n, k;
int coins[101];
int dp[MAX];

int Solution() {

	dp[0] = 1;

	for (int idx = 0; idx < n; ++idx) {

		for (int val = coins[idx]; val <= k; ++val)
			dp[val] = dp[val] + dp[val - coins[idx]];
	}

	return dp[k];
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; ++i)
		cin >> coins[i];

	int answer = Solution();

	cout << answer << endl;

	return 0;
}