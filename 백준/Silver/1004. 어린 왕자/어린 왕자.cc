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

#define MAX 1111

int T, N;
int startX, startY, endX, endY;
int areaX, areaY, radius;
vector<int> answer;

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	cin >> T;

	while (T--)
	{
		cin >> startX >> startY >> endX >> endY;

		cin >> N;

		int count = 0;

		for (int n = 0; n < N; ++n)
		{
			cin >> areaX >> areaY >> radius;

			int startDist = ((startX - areaX) * (startX - areaX)) + ((startY - areaY) * (startY - areaY));
			int endDist = ((endX - areaX) * (endX - areaX)) + ((endY - areaY) * (endY - areaY));
			int r = radius * radius;

			if (startDist < r && endDist > r)
				++count;

			if (startDist > r && endDist < r)
				++count;
		}

		answer.push_back(count);
	}

	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << endl;

	return 0;
}