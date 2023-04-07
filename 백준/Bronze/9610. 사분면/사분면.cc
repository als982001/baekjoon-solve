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

int n, x, y;
int quadrant[4];
int axis;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	quadrant[0] = 0;
	quadrant[1] = 0;
	quadrant[2] = 0;
	quadrant[3] = 0;
	axis = 0;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;

		if (x > 0)
		{
			if (y > 0)
				++quadrant[0];
			else if (y < 0)
				++quadrant[3];
			else
				++axis;
		}
		else if (x < 0)
		{
			if (y > 0)
				++quadrant[1];
			else if (y < 0)
				++quadrant[2];
			else
				++axis;
		}
		else
			++axis;
	}

	for (int i = 0; i < 4; ++i)
		cout << "Q" << i + 1 << ": " << quadrant[i] << endl;
	cout << "AXIS: " << axis << endl;

    return 0;
}
