#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>
#include <iomanip>
#include <limits.h> 
#pragma warning(disable:4996)

using namespace std;

#define MAX 1000111

string num;
int numCount[11];

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	
	
	cin >> num;

	for (int i = 0; i < num.size(); ++i)
	{
		char n = num[i];

		++numCount[n - '0'];
	}

	int answer = 0;

	for (int i = 0; i < 10; ++i)
	{	
		if (i == 6 || i == 9)
			continue;

		if (answer < numCount[i])
			answer = numCount[i];
	}

	int sixAndNine = (numCount[6] + numCount[9]) / 2;
	if ((numCount[6] + numCount[9]) % 2 == 1)
		++sixAndNine;

	if (answer < sixAndNine)
		answer = sixAndNine;

	cout << answer << endl;


	return 0;
}