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

#define FACTOR "factor"
#define MULTIPLE "multiple"
#define NEITHER "neither"

int maxNum = -1;
int num;
int maxR, maxC;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	for (int r = 1; r <= 9; ++r)
	{
		for (int c = 1; c <= 9; ++c)
		{
			cin >> num;

			if (maxNum < num)
			{
				maxNum = num;
				maxR = r;
				maxC = c;
			}
		}
	}

	cout << maxNum << endl;
	cout << maxR << " " << maxC << endl;
	
    return 0;
}
