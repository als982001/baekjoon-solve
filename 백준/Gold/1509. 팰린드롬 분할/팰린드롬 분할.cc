#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2501
#define INF 100000000
using namespace std;

int strLen, answer;
string str;
bool isPalindrome[MAX][MAX];
int dp[MAX];

void Find_Palindrome()
{
	for (int idx = 1; idx <= strLen; ++idx)
		isPalindrome[idx][idx] = true;

	for (int idx = 1; idx < strLen; ++idx)
	{
		if (str[idx] == str[idx + 1])
			isPalindrome[idx][idx + 1] = true;
	}

	for (int len = 3; len <= strLen; ++len)
	{
		for (int start = 1; start + len - 1 <= strLen; ++start)
		{
			int end = start + len - 1;

			if (str[start] == str[end] && isPalindrome[start + 1][end - 1])
				isPalindrome[start][end] = true;
		}
	}
}

void Find_Min_Num()
{
	for (int end = 1; end <= strLen; ++end)
	{
		dp[end] = INF;

		for (int start = 1; start <= end; ++start)
		{
			if (isPalindrome[start][end])
				dp[end] = min(dp[end], dp[start - 1] + 1);
		}
	}

	answer = dp[strLen];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	cin >> str;
	strLen = str.size();
	str = "?" + str;

	Find_Palindrome();

	Find_Min_Num();

	cout << answer << endl;

	return 0;
}