#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 1001
using namespace std;

int T, W;
int pos[MAX];
int dp[MAX][31];

int Solve(int curTime, int curChance, int curPos) {

	if (dp[curTime][curChance] >= 0)
		return dp[curTime][curChance];

	if (curTime > T)
		return 0;

	int& curDP = dp[curTime][curChance];
	if (curPos == pos[curTime])
		curDP = 1;
	else
		curDP = 0;

	int differentPos = 1;
	if (curPos == 1)
		differentPos = 2;

	if (curChance > 0)
		dp[curTime][curChance] += max(Solve(curTime + 1, curChance, curPos), Solve(curTime + 1, curChance - 1, differentPos));
	else
		dp[curTime][curChance] += Solve(curTime + 1, curChance, curPos);
	
	return dp[curTime][curChance];
}

int main() {

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> T >> W;

	for (int idx = 1; idx <= T; ++idx) 
		cin >> pos[idx];
	
	memset(dp, -1, sizeof(dp));
	
	int answer = 0;
	//if (pos[1] == 1)
	//	++answer;

	answer += max(Solve(1, W, 1), Solve(1, W - 1, 2));

	cout << answer << endl;

	return 0;
}