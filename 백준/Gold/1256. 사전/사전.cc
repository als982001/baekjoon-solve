#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 101
#define INF 1000000001
using namespace std;

int N, M, K;
string kthWord;
int dp[MAX][MAX];

int Find_Word_Num(int curA, int curZ)
{
	if (curA == 0 || curZ == 0)
		return 1;

	int& curDP = dp[curA][curZ];
	if (curDP > -1)
		return curDP;

	curDP = min(Find_Word_Num(curA - 1, curZ) + Find_Word_Num(curA, curZ - 1), INF);

	return curDP;
}

void Find_KthWord(int curA, int curZ, int leftNum)
{
	if (curA == 0)
	{
		for (int i = 0; i < curZ; ++i)
			kthWord += 'z';
		return;
	}

	if (curZ == 0)
	{
		for (int i = 0; i < curA; ++i)
			kthWord += 'a';
		return;
	}

	int numOfStartA = Find_Word_Num(curA - 1, curZ);

	if (leftNum < numOfStartA)
	{
		kthWord += 'a';
		Find_KthWord(curA - 1, curZ, leftNum);
	}
	else
	{
		kthWord += 'z';
		Find_KthWord(curA, curZ - 1, leftNum - numOfStartA);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> M >> K;

	memset(dp, -1, sizeof(dp));

	int totalWord = Find_Word_Num(N, M);

	if (totalWord < K)
		cout << -1 << endl;
	else
	{
		Find_KthWord(N, M, K - 1);
		cout << kthWord << endl;
	}

	return 0;
}