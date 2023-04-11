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

#define MAX 1000001

int N;
int x, y;
int minPos, maxPos;
int answer = 0;
priority_queue<pair<int, int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	cin >> N;

	for (int n = 0; n < N; ++n)
	{
		cin >> x >> y;

		pq.push({ -x, -y });
	}

	minPos = -pq.top().first;
	maxPos = -pq.top().second;
	pq.pop();

	while(!pq.empty())
	{
		x = -pq.top().first;
		y = -pq.top().second;
		pq.pop();

		if (x <= maxPos)
		{
			if (maxPos < y)
				maxPos = y;
		}
		else
		{
			answer += (maxPos - minPos);
			
			minPos = x;
			maxPos = y;
		}
	}

	answer += (maxPos - minPos);

	cout << answer << endl;

    return 0;
}
