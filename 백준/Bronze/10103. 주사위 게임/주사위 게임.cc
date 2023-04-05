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

int n;
int valueA, valueB;
int scoreA = 100;
int scoreB = 100;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> valueA >> valueB;

		if (valueA < valueB)
			scoreA -= valueB;
		else if (valueA > valueB)
			scoreB -= valueA;
	}

	printf("%d\n%d\n", scoreA, scoreB);

    return 0;
}
