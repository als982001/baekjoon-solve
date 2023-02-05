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

#define MAX 21
#define HP 100

int personNum;
int loss[MAX];
int happiness[MAX];
int dp[MAX][HP + 1];

int Max(int a, int b)
{
	return a > b ? a : b;
}

void Check()
{
	for (int person = 1; person <= personNum; ++person)
	{
		for (int hp = 1; hp <= HP; ++hp)
		{
			if (hp > loss[person])
				dp[person][hp] = Max(dp[person - 1][hp], dp[person - 1][hp - loss[person]] + happiness[person]);
			else
				dp[person][hp] = dp[person - 1][hp];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> personNum;

	for (int person = 1; person <= personNum; ++person)
		cin >> loss[person];

	for (int person = 1; person <= personNum; ++person)
		cin >> happiness[person];

	Check();

	int answer = dp[personNum][HP];

	cout << answer << endl;
	
	return 0;
}