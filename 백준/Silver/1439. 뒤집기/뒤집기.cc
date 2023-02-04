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

#define MAX 1000001

string num;
int counts[2] = { 0, 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	
	
	cin >> num;

	char before = num[0];
	++counts[before - '0'];

	for (int i = 1; i < num.size(); ++i)
	{
		if (before != num[i])
		{
			before = num[i];
			++counts[before - '0'];
		}
	}

	cout << (counts[0] < counts[1] ? counts[0] : counts[1]) << endl;

	return 0;
}