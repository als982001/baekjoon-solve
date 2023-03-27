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

int N, callTime;
int yeonsik = 0;
int minsik = 0;

int YeongsikCost(int t)
{
	int cost = 0;
	int unitCost = 10;
	int unitTime = 30;

	cost += ((t / unitTime) * unitCost);	
	cost += unitCost;

	return cost;
}

int MinsikCost(int t)
{
	int cost = 0;
	int unitCost = 15;
	int unitTime = 60;

	cost += ((t / unitTime) * unitCost);
	cost += unitCost;

	return cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> callTime;

		yeonsik += YeongsikCost(callTime);
		minsik += MinsikCost(callTime);
	}

	if (yeonsik < minsik)
		cout << "Y " << yeonsik << endl;
	else if (yeonsik > minsik)
		cout << "M " << minsik << endl;
	else
		cout << "Y M " << yeonsik << endl;
	
    return 0;
}
