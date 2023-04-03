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

#define MAX 14

int weightsNum;
int totalWeight = 0;
int weightSumsNum = 0;
int weights[MAX];
map<int, bool> check;

void Check(int weightIdx, int sum)
{
	if (weightIdx >= weightsNum)
	{
		if (sum > 0 && check[sum] == false)
		{
			++weightSumsNum;
			check[sum] = true;
		}

		return;
	}

	Check(weightIdx + 1, sum);
	Check(weightIdx + 1, sum + weights[weightIdx]);
	Check(weightIdx + 1, sum - weights[weightIdx]);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> weightsNum;

	for (int w = 0; w < weightsNum; ++w)
	{
		cin >> weights[w];
		totalWeight += weights[w];
	}

	Check(0, 0);

	cout << totalWeight - weightSumsNum << endl;

    return 0;
}
