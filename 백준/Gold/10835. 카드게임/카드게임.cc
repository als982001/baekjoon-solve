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

#define MAX 3000

int N;
int dp[MAX][MAX];
vector<int> leftCards;
vector<int> rightCards;

int Check(int leftIdx, int rightIdx)
{
	if (leftIdx >= N || rightIdx >= N)
		return 0;
	
	if (dp[leftIdx][rightIdx] >= 0)
		return dp[leftIdx][rightIdx];

	int& curDp = dp[leftIdx][rightIdx];
	curDp = 0;
	
	int maxScore = 0;

	int leftCard = leftCards[leftIdx];
	int rightCard = rightCards[rightIdx];

	// 1. 언제든지 왼쪽 카드만 통에 버릴 수도 있고 왼쪽 카드와 오른쪽 카드를 둘 다 통에 버릴 수도 있다. 이때 얻는 점수는 없다.
	maxScore = max(Check(leftIdx + 1, rightIdx), Check(leftIdx + 1, rightIdx + 1));

	// 2. 오른쪽 카드에 적힌 수가 왼쪽 카드에 적힌 수보다 작은 경우에는 오른쪽 카드만 통에 버릴 수도 있다. 오른쪽 카드만 버리는 경우에는 오른쪽 카드에 적힌 수만큼 점수를 얻는다.	
	if (leftCard > rightCard)
		maxScore = max(maxScore, Check(leftIdx, rightIdx + 1) + rightCard);

	curDp += maxScore;

	return curDp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int leftIdx = 0; leftIdx <= N; ++leftIdx)
	{
		for (int rightIdx = 0; rightIdx <= N; ++rightIdx)
			dp[leftIdx][rightIdx] = -1;
	}

	for (int n = 0; n < N; ++n)
	{
		int card;
		cin >> card;

		leftCards.push_back(card);
	}

	for (int n = 0; n < N; ++n)
	{
		int card;
		cin >> card;

		rightCards.push_back(card);
	}
	
	int answer = Check(0, 0);

	cout << answer << endl;


    return 0;
}
