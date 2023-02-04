#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
// #include <map>
#include <memory.h>
#include <deque>
#include <cmath>
#include <stack>
#include <cstring>
#include <typeinfo>

using namespace std;

#define MAX 100111

int w, h, x, y, P;
int r;

bool Square(int pX, int pY)
{
	return x <= pX && pX <= (x + w) && y <= pY && pY <= (y + h);
}

bool Circle(int pX, int pY)
{
	int centerY = y + r;

	// 왼쪽 반원
	if (x - r <= pX && pX <= x && y <= pY && pY <= y + h)
	{
		int len = ((x - pX) * (x - pX)) + ((centerY - pY) * (centerY - pY));
        
		return len <= (r * r);
	}
	// 오른쪽 반원
	else if (x + w <= pX && pX <= x + w + r && y <= pY && pY <= y + h)
	{
		int centerX = x + w;
		int len = ((centerX - pX) * (centerX - pX)) + ((centerY - pY) * (centerY - pY));

		return len <= (r * r);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int answer = 0;

	cin >> w >> h >> x >> y >> P;

	r = h / 2;

	for (int p = 0; p < P; ++p)
	{
		int pX, pY;
		cin >> pX >> pY;

		if (Square(pX, pY) || Circle(pX, pY))
			++answer;
	}

	cout << answer << endl;

	return 0;
}
