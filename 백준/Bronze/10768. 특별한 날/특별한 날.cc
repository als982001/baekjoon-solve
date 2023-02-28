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

#define MAX 511

#define BEFORE "Before"
#define AFTER "After"
#define SPECIAL "Special"

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	int month, day;
	string answer;

	cin >> month;
	cin >> day;
	
	if (month < 2)
		answer = BEFORE;
	else if (month > 2)
		answer = AFTER;
	else
	{
		if (day < 18)
			answer = BEFORE;
		else if (day > 18)
			answer = AFTER;
		else
			answer = SPECIAL;
	}

	cout << answer << endl;

	return 0;
}
