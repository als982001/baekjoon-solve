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

#define SEC 60
#define MIN 60
#define HOUR 24	

int hour, minute, second;
int cookingTime;
int tempTime;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	cin >> hour >> minute >> second;

	cin >> cookingTime;

	second += cookingTime;

	if (second >= SEC)
	{
		tempTime = second / SEC;
		minute += tempTime;

		second %= SEC;
	}

	if (minute >= MIN)
	{
		tempTime = minute / MIN;
		hour += tempTime;

		minute %= MIN;
	}

	if (hour >= HOUR)
		hour %= HOUR;

	printf("%d %d %d \n", hour, minute, second);

	return 0;
}
