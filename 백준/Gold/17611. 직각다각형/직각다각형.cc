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

#define CORR 500000
#define MAX 1000010

int answer = -1;
int N;
int curX, curY, nxtX, nxtY, lastX, lastY;
int countX[MAX];
int countY[MAX];

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	cin >> curX >> curY;

	curX += CORR;
	curY += CORR;

	lastX = curX;
	lastY = curY;

	for (int n = 1; n < N; ++n)
	{
		cin >> nxtX >> nxtY;

		nxtX += CORR;
		nxtY += CORR;

		if (curX == nxtX)
		{
			int minY = curY < nxtY ? curY : nxtY;
			int maxY = curY > nxtY ? curY : nxtY;

			++countY[minY];
			--countY[maxY];
		}
		else if (curY == nxtY)
		{
			int minX = curX < nxtX ? curX : nxtX;
			int maxX = curX > nxtX ? curX : nxtX;

			++countX[minX];
			--countX[maxX];
		}

		curX = nxtX;
		curY = nxtY;
	}

	if (curX == lastX)
	{
		int minY = curY < lastY ? curY : lastY;
		int maxY = curY > lastY ? curY : lastY;

		++countY[minY];
		--countY[maxY];
		}
	else if (curY == lastY)
	{
		int minX = curX < lastX ? curX : lastX;
		int maxX = curX > lastX ? curX : lastX;

		++countX[minX];
		--countX[maxX];
	}

	for (int i = 1; i < MAX; ++i)
	{
		countX[i] += countX[i - 1];
		countY[i] += countY[i - 1];
	}

	for (int i = 1; i < MAX; ++i)
		answer = max(max(countX[i], countY[i]), answer);
	
	cout << answer << endl;

    return 0;
}
