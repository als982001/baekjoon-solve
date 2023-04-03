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

int hour, minute;
int requiredMinute;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> hour >> minute;
	cin >> requiredMinute;

	minute += requiredMinute;

	hour = (hour + (minute / 60)) % 24;
	minute %= 60;

	printf("%d %d \n", hour, minute);

    return 0;
}
