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

int N;
int a, b, c;
int curPrize;
int maxPrize = -1;

int Max(int x, int y)
{
	return x > y ? x : y;
}

int Max(int x, int y, int z)
{
	return Max(Max(x, y), z);
}

int TwoEqualNumbers(int x, int y, int z)
{
	if (x == y)
	{
		if (x != z)
			return x;
		else
			return -1;
	}
	else if (x == z)
	{
		if (x != y)
			return x;
		else
			return -1;
	}
	else if (y == z)
	{
		if (x != y)
			return y;
		else
			return -1;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b >> c;

		// 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다. 
		if (a == b && b == c)
			curPrize = 10000 + (a * 1000);

		// 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다. 
		else if (TwoEqualNumbers(a, b, c) != -1)
			curPrize = 1000 + (TwoEqualNumbers(a, b, c) * 100);

		// 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.  
		else
			curPrize = 100 * Max(a, b, c);
		
		if (maxPrize < curPrize)
			maxPrize = curPrize;
	}

	cout << maxPrize << endl;

    return 0;
}
