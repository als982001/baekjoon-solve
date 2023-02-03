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
#include <map>
#pragma warning(disable:4996)

using namespace std;

#define MAX 31

int testCaseNum;
int westSiteNum, eastSiteNum;
int dp[MAX][MAX];
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> testCaseNum;

	while(testCaseNum--)
	{
		memset(dp, 0, sizeof(dp));

		cin >> westSiteNum >> eastSiteNum;

		for (int eastSite = 1; eastSite <= eastSiteNum; ++eastSite)
			dp[1][eastSite] = eastSite;

		for (int westSite = 2; westSite <= westSiteNum; ++westSite)
		{
			for (int eastSite = westSite; eastSite <= eastSiteNum; ++eastSite)
			{
				for (int eastSiteIdx = eastSite; eastSiteIdx >= westSite; --eastSiteIdx)
					dp[westSite][eastSite] += dp[westSite - 1][eastSiteIdx - 1];
			}
		}

		answer.push_back(dp[westSiteNum][eastSiteNum]);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;
	
	return 0;
}
